#include "adddvddialog.h"
#include "ui_adddvddialog.h"

AddDvdDialog::AddDvdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDvdDialog)
{
    ui->setupUi(this);
}

AddDvdDialog::~AddDvdDialog()
{
    delete ui;
}
