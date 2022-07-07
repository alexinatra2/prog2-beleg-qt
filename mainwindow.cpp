#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QSignalMapper>
#include "adduserdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addUserButton_released()
{
    User *user = new User();
    UserDialog *dialog = new UserDialog(this, user);
    connect(dialog, SIGNAL(user_submitted(User *)), this, SLOT(addUser(User *)));
    dialog->exec();
}

void MainWindow::addUser(User *user) {
    QTableWidget *table = ui->userTable;
    int row = table->rowCount();
    table->insertRow(row );
    table->setItem(row, 0, new QTableWidgetItem(user->GetFirstName()));
    table->setItem(row, 1, new QTableWidgetItem(user->GetLastName()));
    table->setItem(row, 2, new QTableWidgetItem(user->GetBirthday().toString("dd/MM/yyyy")));
    QPushButton *removeButton = new QPushButton(tr("remove"), this);
    connect(removeButton, &QPushButton::released, this, &MainWindow::removeUser);
    table->setCellWidget(row, 3, removeButton);
}

void MainWindow::removeUser() {
    QTableWidget *table = ui->userTable;
    int row = table->currentRow();
    table->removeRow(row);
}

void MainWindow::on_addMediumButton_released()
{

}


void MainWindow::on_borrowMediumButton_released()
{

}

