#include "sortmediadialog.h"
#include "ui_sortmediadialog.h"

SortMediaDialog::SortMediaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortMediaDialog)
{
    ui->setupUi(this);
}

SortMediaDialog::~SortMediaDialog()
{
    delete ui;
}

void SortMediaDialog::on_buttonBox_accepted()
{
    if (ui->typeRadioButton->isChecked()) {
        emit sort_selected(TYPE);
    } else if (ui->availabilityRadioButton->isChecked()) {
        emit sort_selected(AVAILABILITY);
    } else if (ui->borrowerRadioButton->isChecked()) {
        emit sort_selected(BORROWER);
    } else if (ui->titleRadioButton->isChecked()) {
        emit sort_selected(TITLE);
    } else {
        reject();
    }
    emit descending_selected(ui->descendingCheckBox->isChecked());
}

