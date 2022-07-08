#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QMessageBox>

#include "adduserdialog.h"
#include "mediumchoicedialog.h"
#include "borrowmediumdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(user_table_modified()), this, SLOT(populateUserTable()));
    connect(this, SIGNAL(medium_table_modified()), this, SLOT(populateMediumTable()));
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
        table->setItem(row, 0, new QTableWidgetItem(m->title()));
        table->setItem(row, 1, new QTableWidgetItem(m->description()));
        table->setItem(row, 2, new QTableWidgetItem(QVariant(m->available()).toString()));
        table->setItem(row, 3, new QTableWidgetItem(m->borrower() != nullptr ? m->borrower()->fullName() : "-"));

        QPushButton *borrowButton = new QPushButton(tr(m->available() ? "borrow" : "return"), this);
        connect(borrowButton, &QPushButton::released, this,
                m->available() ? &MainWindow::borrowDialog : &MainWindow::returnMedium);
        table->setCellWidget(row, 4, borrowButton);

        QPushButton *removeButton = new QPushButton(tr("remove"), this);
        connect(removeButton, &QPushButton::released, this, &MainWindow::removeMedium);
        table->setCellWidget(row, 5, removeButton);

        QPushButton *detailsButton = new QPushButton(tr("details"), this);
        connect(detailsButton, &QPushButton::released, this, &MainWindow::getMediumDetails);
        table->setCellWidget(row, 6, detailsButton);
    }
}

