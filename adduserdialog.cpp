#include "adduserdialog.h"
#include "ui_adduserdialog.h"
#include <QDebug>

UserDialog::UserDialog(QWidget *parent, User *user) :
    QDialog(parent),
    ui(new Ui::UserDialog),
    newUser(user)
{
    ui->setupUi(this);
    ui->firstNameLineEdit->setText(user->GetFirstName());
    ui->lastNameLineEdit->setText(user->GetLastName());
    ui->birthdayDateEdit->setDate(user->GetBirthday());
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::on_buttonBox_accepted() {
    emit user_submitted(this->newUser);
}

void UserDialog::on_firstNameLineEdit_textEdited(const QString &firstName)
{
    this->newUser->SetFirstName(firstName);
}


void UserDialog::on_lastNameLineEdit_textEdited(const QString &lastName)
{
    this->newUser->SetLastName(lastName);
}


void UserDialog::on_birthdayDateEdit_userDateChanged(const QDate &date)
{
    this->newUser->SetBirthday(date);
}

