#include "addcddialog.h"
#include "ui_addcddialog.h"

AddCdDialog::AddCdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCdDialog)
{
    ui->setupUi(this);
}

AddCdDialog::~AddCdDialog()
{
    delete ui;
}
