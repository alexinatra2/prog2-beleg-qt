#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addmediumdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->AddMedium, SIGNAL(released()), this, SLOT(addMedium()));
    connect(ui->RemoveMedium, SIGNAL(released()), this, SLOT(removeMedium()));
    connect(ui->EditMedium, SIGNAL(released()), this, SLOT(editMedium()));
    connect(ui->AddMedium, SIGNAL(released()), this, SLOT(addMedium()));
    connect(ui->BorrowMedium, SIGNAL(released()), this, SLOT(borrowMedium()));
    connect(ui->ReturnMedium, SIGNAL(released()), this, SLOT(returnMedium()));

    connect(ui->AddUser, SIGNAL(released()), this, SLOT(addUser()));
    connect(ui->RemoveUser, SIGNAL(released()), this, SLOT(removeUser()));
    connect(ui->EditUser, SIGNAL(released()), this, SLOT(editUser()));

    ui->Details->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addMedium() {
    AddMediumDialog *dialog = new AddMediumDialog();
    if (dialog->exec()) {

    }
}
