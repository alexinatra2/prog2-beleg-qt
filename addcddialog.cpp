#include "addcddialog.h"
#include "ui_addcddialog.h"

AddCdDialog::AddCdDialog(QWidget *parent, Cd *cd) :
    QDialog(parent),
    ui(new Ui::AddCdDialog),
    cd(cd)
{
    ui->setupUi(this);
    ui->titleLineEdit->setText(cd->title());
    ui->descriptionLineEdit->setText(cd->description());
    ui->releaseDateDateEdit->setDate(cd->releaseDate());
    ui->numberOfTracksSpinBox->setValue(cd->numberOfTracks());
    ui->totalLengthSpinBox->setValue(cd->totalLength());
}

AddCdDialog::~AddCdDialog()
{
    delete ui;
}

void AddCdDialog::on_buttonBox_accepted()
{
    emit medium_submitted(this->cd);
}

void AddCdDialog::on_titleLineEdit_textEdited(const QString &title)
{
    this->cd->setTitle(title);
}


void AddCdDialog::on_descriptionLineEdit_textEdited(const QString &description)
{
    this->cd->setDescription(description);
}


void AddCdDialog::on_totalLengthSpinBox_valueChanged(int totalLength)
{
    this->cd->setTotalLength(totalLength);
}


void AddCdDialog::on_numberOfTracksSpinBox_valueChanged(int numberOfTracks)
{
    this->cd->setNumberOfTracks(numberOfTracks);
}


void AddCdDialog::on_releaseDateDateEdit_userDateChanged(const QDate &date)
{
    this->cd->setReleaseDate(date);
}

