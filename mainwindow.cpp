#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
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
    AddUserDialog *dialog = new AddUserDialog(this, user);
    connect(dialog, SIGNAL(user_submitted(User *)), this, SLOT(addUser(User *)));
    dialog->exec();
}

void MainWindow::addUser(User *user) {
    QTableWidget *table = ui->userTable;
    int lastRow = table->rowCount();
    table->insertRow(lastRow);
    table->setItem(lastRow, 0, new QTableWidgetItem(user->GetFirstName()));
    table->setItem(lastRow, 1, new QTableWidgetItem(user->GetLastName()));
    table->setItem(lastRow, 2, new QTableWidgetItem(QString::number(user->GetAge())));
}

void MainWindow::on_addMediumButton_released()
{

}


void MainWindow::on_borrowMediumButton_released()
{

}

