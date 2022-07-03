#include "addmediumdialog.h"
#include "ui_addmediumdialog.h"

AddMediumDialog::AddMediumDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMediumDialog)
{
    ui->setupUi(this);
}

AddMediumDialog::~AddMediumDialog()
{
    delete ui;
}
