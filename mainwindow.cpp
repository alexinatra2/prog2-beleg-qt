#include "mainwindow.h"
#include "sortmediadialog.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QMessageBox>
#include <QtXml>
#include <algorithm>

#include "adduserdialog.h"
#include "mediumchoicedialog.h"
#include "borrowmediumdialog.h"

#include "book.h"
#include "cd.h"
#include "dvd.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(user_table_modified()), this, SLOT(populateUserTable()));
    connect(this, SIGNAL(medium_table_modified()), this, SLOT(populateMediumTable()));
    connect(this, SIGNAL(media_sort_options_changed()), this, SLOT(sortMedia()));
    connect(this, SIGNAL(closing()), this, SLOT(exportXml()));

    importXml();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addUserButton_released()
{
    User *user = new User();
    user->setBirthday(QDate::currentDate().addYears(-12));
    AddUserDialog *dialog = new AddUserDialog(this, user);
    connect(dialog, SIGNAL(user_submitted(User *)), this, SLOT(addUser(User *)));
    dialog->exec();
}

void MainWindow::addUser(User *user) {
    if (user->firstName().isEmpty()) {
        QMessageBox messageBox;
        messageBox.setText("User should have a first name.");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.exec();
        return;
    }
    if (user->lastName().isEmpty()) {
        QMessageBox messageBox;
        messageBox.setText("User should have a last name.");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.exec();
        return;
    }
    if (user->age() < 12) {
        QMessageBox messageBox;
        messageBox.setText("User must be of age 12 or older to be added.");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.exec();
        return;
    }
    users->push_back(user);
    emit user_table_modified();
}

void MainWindow::removeUser() {
    QTableWidget *table = ui->userTable;
    int row = table->currentRow();
    users->erase(users->begin() + row);
    emit user_table_modified();
}

void MainWindow::populateUserTable() {
    QTableWidget *table = ui->userTable;
    table->setRowCount(0);
    for (User *u : *users) {
        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(u->firstName()));
        table->setItem(row, 1, new QTableWidgetItem(u->lastName()));        
        table->setItem(row, 2, new QTableWidgetItem(u->birthday().toString("dd/MM/yyyy")));

        QPushButton *removeButton = new QPushButton(tr("remove"), this);
        connect(removeButton, SIGNAL(released()), this, SLOT(removeUser()));
        table->setCellWidget(row, 3, removeButton);
    }
}

void MainWindow::on_addMediumButton_released()
{
    Medium *medium = nullptr;
    MediumChoiceDialog *dialog = new MediumChoiceDialog(this, medium);
    connect(dialog, SIGNAL(medium_submitted(Medium *)), this, SLOT(addMedium(Medium *)));
    dialog->exec();
}

void MainWindow::addMedium(Medium *medium) {
    media->push_back(medium);
    emit medium_table_modified();
}

void MainWindow::removeMedium() {
    QTableWidget *table = ui->mediumTable;
    int row = table->currentRow();
    media->erase(media->begin() + row);
    emit medium_table_modified();
}

void MainWindow::getMediumDetails() {
    int row = ui->mediumTable->currentRow();
    Medium *medium = (*media)[row];
    QMessageBox messageBox;
    messageBox.setText(medium->details());
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.exec();
}

void MainWindow::borrowDialog()
{
    QTableWidget *table = ui->mediumTable;
    int row = table->currentRow();
    Medium *medium = (*media)[row];
    std::vector<User *> *eligibleUsers = new std::vector<User *>();
    std::copy_if (users->begin(),
                  users->end(),
                  std::back_inserter(*eligibleUsers),
                  [&](User *u){return medium->isAllowedToBeBorrowedBy(u);} );
    BorrowMediumDialog *dialog = new BorrowMediumDialog(this, eligibleUsers);
    connect(dialog, SIGNAL(borrower_chosen(User *)), this, SLOT(borrowMedium(User *)));
    dialog->exec();
}

void MainWindow::borrowMedium(User *user)
{
    QTableWidget *table = ui->mediumTable;
    int row = table->currentRow();
    Medium *medium = (*media)[row];
    medium->setBorrower(user);
    emit medium_table_modified();
}

void MainWindow::returnMedium()
{
    QTableWidget *table = ui->mediumTable;
    int row = table->currentRow();
    (*media)[row]->setBorrower(nullptr);
    emit medium_table_modified();
}

void MainWindow::populateMediumTable() {
    QTableWidget *table = ui->mediumTable;
    table->setRowCount(0);
    for (Medium *m : *media) {
        int row = table->rowCount();
        table->insertRow(row);

        table->setItem(row, 0, new QTableWidgetItem(Medium::mediumTypeString(m->type())));
        table->setItem(row, 1, new QTableWidgetItem(m->title()));
        table->setItem(row, 2, new QTableWidgetItem(m->description()));

        QTableWidgetItem *availabilityItem = new QTableWidgetItem(QVariant(m->available()).toString());
        availabilityItem->setFlags(availabilityItem->flags() ^ Qt::ItemIsEditable);
        table->setItem(row, 3, availabilityItem);

        QTableWidgetItem *borrowerItem = new QTableWidgetItem(m->borrower() != nullptr ? m->borrower()->fullName() : "-");
        borrowerItem->setFlags(borrowerItem->flags() ^ Qt::ItemIsEditable);
        table->setItem(row, 4, borrowerItem);

        QPushButton *borrowButton = new QPushButton(tr(m->available() ? "borrow" : "return"), this);
        connect(borrowButton, &QPushButton::released, this,
                m->available() ? &MainWindow::borrowDialog : &MainWindow::returnMedium);
        table->setCellWidget(row, 5, borrowButton);

        QPushButton *removeButton = new QPushButton(tr("remove"), this);
        connect(removeButton, &QPushButton::released, this, &MainWindow::removeMedium);
        table->setCellWidget(row, 6, removeButton);

        QPushButton *detailsButton = new QPushButton(tr("details"), this);
        connect(detailsButton, &QPushButton::released, this, &MainWindow::getMediumDetails);
        table->setCellWidget(row, 7, detailsButton);
    }
}

int MainWindow::getUserIndex(User *user) {
    if (user == nullptr) {
        return -1;
    }
    std::vector<User *>::iterator iterator = std::find(users->begin(), users->end(), user);
    if (iterator != users->cend()) {
        return std::distance(users->begin(), iterator);
    }
    else {
        return -1;
    }
}

void MainWindow::importXml() {
    QDomDocument document;
    QFile file("tabledata.xml");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        qDebug() << "reading: \n" << content << '\n';
        if (document.setContent(content)) {
            QDomNodeList userElements = document.elementsByTagName("user");
            for (int i = 0; i < userElements.count(); i++) {
                QDomNode userNode = userElements.at(i);
                if (userNode.isElement()) {
                    QDomElement userElement = userNode.toElement();
                    User *user = new User();
                    user->setFirstName(userElement.attribute("firstName"));
                    user->setLastName(userElement.attribute("lastName"));
                    user->setBirthday(QDate::fromString(userElement.attribute("birthday"), "dd/MM/yyyy"));
                    users->push_back(user);
                }
            }
            QDomNodeList bookElements = document.elementsByTagName("book");
            for (int i = 0; i < bookElements.count(); i++) {
                QDomNode bookNode = bookElements.at(i);
                if (bookNode.isElement()) {
                    QDomElement bookElement = bookNode.toElement();
                    Book *book = new Book();
                    book->setTitle(bookElement.attribute("title"));
                    book->setDescription(bookElement.attribute("description"));
                    book->setAuthor(bookElement.attribute("author"));
                    book->setPages(bookElement.attribute("pages").toInt());
                    book->setChapters(bookElement.attribute("chapters").toInt());
                    int borrowerIndex = bookElement.attribute("borrower").toInt();
                    book->setBorrower(borrowerIndex >= 0 ? users->at(borrowerIndex): nullptr);
                    media->push_back(book);
                }
            }
            QDomNodeList cdElements = document.elementsByTagName("cd");
            for (int i = 0; i < cdElements.count(); i++) {
                QDomNode cdNode = bookElements.at(i);
                if (cdNode.isElement()) {
                    QDomElement cdElement = cdNode.toElement();
                    Cd *cd = new Cd();
                    cd->setTitle(cdElement.attribute("title"));
                    cd->setDescription(cdElement.attribute("description"));
                    cd->setTotalLength(cdElement.attribute("totalLength").toInt());
                    cd->setNumberOfTracks(cdElement.attribute("numberOfTracks").toInt());
                    cd->setReleaseDate(QDate::fromString(cdElement.attribute("releaseDate"), "dd/MM/yyyy"));
                    int borrowerIndex = cdElement.attribute("borrower").toInt();
                    cd->setBorrower(borrowerIndex >= 0 ? users->at(borrowerIndex): nullptr);
                    media->push_back(cd);
                }
            }
            QDomNodeList dvdElements = document.elementsByTagName("dvd");
            for (int i = 0; i < dvdElements.count(); i++) {
                QDomNode dvdNode = dvdElements.at(i);
                if (dvdNode.isElement()) {
                    QDomElement dvdElement = dvdNode.toElement();
                    Dvd *dvd = new Dvd();
                    dvd->setTitle(dvdElement.attribute("title"));
                    dvd->setDescription(dvdElement.attribute("description"));
                    dvd->setAgeRating(dvdElement.attribute("ageRating").toInt());
                    dvd->setLength(dvdElement.attribute("length").toInt());
                    int borrowerIndex = dvdElement.attribute("borrower").toInt();
                    dvd->setBorrower(borrowerIndex >= 0 ? users->at(borrowerIndex): nullptr);
                    media->push_back(dvd);
                }
            }
        }
        file.close();
    } else {
        QMessageBox messageBox;
        messageBox.setText("the file tabledata.xml does not yet exist");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.exec();
    }
    emit medium_table_modified();
    emit user_table_modified();
}

void MainWindow::exportXml()
{
    QDomDocument document;
    QDomElement tablesElement = document.createElement("tables");
    document.appendChild(tablesElement);
    QDomElement usersElement = document.createElement("users");
    tablesElement.appendChild(usersElement);
    for (User *user: *users) {
        QDomElement userElement = document.createElement("user");
        userElement.setAttribute("firstName", user->firstName());
        userElement.setAttribute("lastName", user->lastName());
        userElement.setAttribute("birthday", user->birthday().toString("dd/MM/yyyy"));
        usersElement.appendChild(userElement);
    }
    QDomElement mediaElement = document.createElement("media");
    tablesElement.appendChild(mediaElement);
    for (Medium *medium: *media) {
        switch(medium->type()) {
        case MediumType::BOOK: {
            Book *book = static_cast<Book *>(medium);
            QDomElement bookElement = document.createElement("book");
            bookElement.setAttribute("title", book->title());
            bookElement.setAttribute("description", book->description());
            bookElement.setAttribute("author", book->author());
            bookElement.setAttribute("pages", book->pages());
            bookElement.setAttribute("chapters", book->chapters());
            bookElement.setAttribute("borrower", getUserIndex(book->borrower()));
            mediaElement.appendChild(bookElement);
            break;
        }
        case MediumType::CD: {
            Cd *cd = static_cast<Cd *>(medium);
            QDomElement cdElement = document.createElement("cd");
            cdElement.setAttribute("title", cd->title());
            cdElement.setAttribute("description", cd->description());
            cdElement.setAttribute("totalLength", cd->totalLength());
            cdElement.setAttribute("releaseDate", cd->releaseDate().toString("dd/MM/yyyy"));
            cdElement.setAttribute("numberOfTracks", cd->numberOfTracks());
            cdElement.setAttribute("borrower", getUserIndex(cd->borrower()));
            mediaElement.appendChild(cdElement);
            break;
        }
        case MediumType::DVD: {
            Dvd *dvd = static_cast<Dvd *>(medium);
            QDomElement dvdElement = document.createElement("dvd");
            dvdElement.setAttribute("title", dvd->title());
            dvdElement.setAttribute("description", dvd->description());
            dvdElement.setAttribute("ageRating", dvd->ageRating());
            dvdElement.setAttribute("length", dvd->length());
            dvdElement.setAttribute("borrower", getUserIndex(dvd->borrower()));
            mediaElement.appendChild(dvdElement);
            break;
        }
        default:
            QMessageBox messageBox;
            messageBox.setText("something went wrong");
            messageBox.setStandardButtons(QMessageBox::Ok);
            messageBox.exec();
        }
    }

    QFile file("tabledata.xml");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream textStream(&file);
        textStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << document.toString();
        qDebug() << "writing: \n" << document.toString() << '\n';
        file.close();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    qDebug() << event;
}

void MainWindow::on_sortMediaButton_released()
{
    SortMediaDialog *dialog = new SortMediaDialog(this);
    connect(dialog, SIGNAL(sort_selected(SortingOrder)), this, SLOT(setMediaOrder(SortingOrder)));
    connect(dialog, SIGNAL(descending_selected(bool)), this, SLOT(setMediaDescending(bool)));
    dialog->exec();
}

void MainWindow::setMediaOrder(SortingOrder mediaOrder)
{
    this->mediaOrder = mediaOrder;
    emit media_sort_options_changed();
}

void MainWindow::setMediaDescending(bool mediaDescending)
{
    this->mediaDescending = mediaDescending;
    emit media_sort_options_changed();
}

void MainWindow::sortMedia() {
    switch (this->mediaOrder) {
    case TYPE:
        std::sort(this->media->begin(), this->media->end(), [&](Medium *m1, Medium *m2){return m1->type() < m2->type();});
        break;
    case AVAILABILITY:
        std::sort(this->media->begin(), this->media->end(), [&](Medium *m1, Medium *m2){return m1->available();});
        break;
    case BORROWER:
        std::sort(this->media->begin(),
                  this->media->end(),
                  [&](Medium *m1, Medium *m2){
                        if (m1->available()) {
                            return false;
                        }
                        if (m2->available()) {
                            return true;
                        }
                        return QString::compare(m1->borrower()->fullName(), m2->borrower()->fullName()) < 0;
                    }
        );
        break;
    case TITLE:
        std::sort(this->media->begin(), this->media->end(), [&](Medium *m1, Medium *m2){return m1->title() < m2->title();});
        break;
    default:
        break;
    }
    if (this->mediaDescending) {
        std::reverse(this->media->begin(), this->media->begin());
    }
    emit medium_table_modified();
}

