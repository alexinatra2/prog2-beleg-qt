#include "mediumchoicedialog.h"
#include "ui_mediumchoicedialog.h"
#include "addblueraydialog.h"
#include "addcddialog.h"
#include "addbookdialog.h"
#include "adddvddialog.h"

MediumChoiceDialog::MediumChoiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MediumChoiceDialog)
{
    ui->setupUi(this);
}

MediumChoiceDialog::~MediumChoiceDialog()
{
    delete ui;
}

void MediumChoiceDialog::on_buttonBox_accepted()
{
    if (ui->bookButton->isChecked()) {

    }
    else if (ui->cdButton->isChecked()) {

    }
    else if (ui->dvdButton->isChecked()) {

    }
    else {
        reject();
    }
}

