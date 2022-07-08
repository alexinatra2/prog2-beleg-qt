#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QMessageBox>

#include "adduserdialog.h"
#include "mediumchoicedialog.h"

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
    AddUserDialog *dialog = new AddUserDialog(this, user);
    connect(dialog, SIGNAL(user_submitted(User *)), this, SLOT(addUser(User *)));
    dialog->exec();
}

void MainWindow::addUser(User *user) {
    users->push_back(user);
    emit user_table_modified();
}

void MainWindow::removeUser() {
    int row = ui->userTable->currentRow();
    ui->userTable->removeRow(row);
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

void MainWindow::populateMediumTable() {
    QTableWidget *table = ui->mediumTable;
    table->setRowCount(0);
    for (Medium *m : *media) {
        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(m->title()));
        table->setItem(row, 1, new QTableWidgetItem(m->description()));
        table->setItem(row, 2, new QTableWidgetItem(QVariant(true).toString()));

        QPushButton *removeButton = new QPushButton(tr("remove"), this);
        connect(removeButton, &QPushButton::released, this, &MainWindow::removeMedium);
        table->setCellWidget(row, 3, removeButton);

        QPushButton *detailsButton = new QPushButton(tr("details"), this);
        connect(detailsButton, &QPushButton::released, this, &MainWindow::getMediumDetails);
        table->setCellWidget(row, 4, detailsButton);
    }
}

