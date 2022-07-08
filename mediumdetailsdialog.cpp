#include "mediumdetailsdialog.h"
#include "ui_mediumdetailsdialog.h"

MediumDetailsDialog::MediumDetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MediumDetailsDialog)
{
    ui->setupUi(this);
}

MediumDetailsDialog::~MediumDetailsDialog()
{
    delete ui;
}
