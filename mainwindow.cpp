#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QSignalMapper>
#include "adduserdialog.h"
#include "mediumchoicedialog.h"

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
    int row = table->rowCount();
    table->insertRow(row );
    table->setItem(row, 0, new QTableWidgetItem(user->firstName()));
    table->setItem(row, 1, new QTableWidgetItem(user->lastName()));
    table->setItem(row, 2, new QTableWidgetItem(user->birthday().toString("dd/MM/yyyy")));
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
    Medium *medium = nullptr;
    MediumChoiceDialog *dialog = new MediumChoiceDialog(this, medium);
    connect(dialog, SIGNAL(medium_submitted(Medium *)), this, SLOT(addMedium(Medium *)));
    dialog->exec();
}

void MainWindow::addMedium(Medium *medium) {
    QTableWidget *table = ui->mediumTable;
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(medium->title()));
    table->setItem(row, 1, new QTableWidgetItem(medium->description()));
    table->setItem(row, 2, new QTableWidgetItem(QVariant(true).toString()));
    QPushButton *removeButton = new QPushButton(tr("remove"), this);
    connect(removeButton, &QPushButton::released, this, &MainWindow::removeMedium);
    table->setCellWidget(row, 3, removeButton);
}

void MainWindow::removeMedium() {
    QTableWidget *table = ui->mediumTable;
    int row = table->currentRow();
    table->removeRow(row);
}


void MainWindow::on_borrowMediumButton_released()
{

}

