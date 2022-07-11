#include "mediumchoicedialog.h"
#include "ui_mediumchoicedialog.h"
#include "addcddialog.h"
#include "addbookdialog.h"
#include "adddvddialog.h"

MediumChoiceDialog::MediumChoiceDialog(QWidget *parent, Medium *medium) :
    QDialog(parent),
    ui(new Ui::MediumChoiceDialog),
    newMedium(medium)
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
        AddBookDialog *dialog = new AddBookDialog(this, new Book());
        connect(dialog, SIGNAL(medium_submitted(Medium *)), this, SLOT(submitMedium(Medium *)));
        dialog->exec();
    }
    else if (ui->cdButton->isChecked()) {
        AddCdDialog *dialog = new AddCdDialog(this, new Cd());
        connect(dialog, SIGNAL(medium_submitted(Medium *)), this, SLOT(submitMedium(Medium *)));
        dialog->exec();
    }
    else if (ui->dvdButton->isChecked()) {
        AddDvdDialog *dialog = new AddDvdDialog(this, new Dvd());
        connect(dialog, SIGNAL(medium_submitted(Medium *)), this, SLOT(submitMedium(Medium *)));
        dialog->exec();
    }
    else {
        reject();
    }
}

void MediumChoiceDialog::submitMedium(Medium *medium) {
    emit medium_submitted(medium);
}

