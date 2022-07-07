#include "addblueraydialog.h"
#include "ui_addblueraydialog.h"

AddBluerayDialog::AddBluerayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBluerayDialog)
{
    ui->setupUi(this);
}

AddBluerayDialog::~AddBluerayDialog()
{
    delete ui;
}
