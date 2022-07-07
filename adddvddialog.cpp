#include "adddvddialog.h"
#include "ui_adddvddialog.h"

AddDvdDialog::AddDvdDialog(QWidget *parent, Dvd *dvd) :
    QDialog(parent),
    ui(new Ui::AddDvdDialog),
    dvd(dvd)
{
    ui->setupUi(this);
    ui->titleLineEdit->setText(dvd->title());
    ui->descriptionLineEdit->setText(dvd->description());
    ui->lengthSpinBox->setValue(dvd->length());
    ui->ageRatingSpinBox->setValue(dvd->ageRating());
}

AddDvdDialog::~AddDvdDialog()
{
    delete ui;
}

void AddDvdDialog::on_buttonBox_accepted()
{
    emit medium_submitted(this->dvd);
}

void AddDvdDialog::on_titleLineEdit_textEdited(const QString &title)
{
    this->dvd->setTitle(title);
}


void AddDvdDialog::on_descriptionLineEdit_textEdited(const QString &description)
{
    this->dvd->setDescription(description);
}


void AddDvdDialog::on_lengthSpinBox_valueChanged(int length)
{
    this->dvd->setLength(length);
}


void AddDvdDialog::on_ageRatingSpinBox_valueChanged(int ageRating)
{
    this->dvd->setAgeRating(ageRating);
}

