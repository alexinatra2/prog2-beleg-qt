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
    AddUserDialog *dialog = new AddUserDialog(this, user, ui->userTable);
    dialog->exec();
}


void MainWindow::on_addMediumButton_released()
{

}


void MainWindow::on_borrowMediumButton_released()
{

}

