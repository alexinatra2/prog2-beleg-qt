#include "adduserdialog.h"
#include "ui_adduserdialog.h"
#include <QDebug>

AddUserDialog::AddUserDialog(QWidget *parent, User *user) :
    QDialog(parent),
    ui(new Ui::AddUserDialog),
    newUser(user)
{
    ui->setupUi(this);
    ui->firstNameLineEdit->setText(user->GetFirstName());
    ui->lastNameLineEdit->setText(user->GetLastName());
    ui->birthdayDateEdit->setDate(user->GetBirthday());
}

AddUserDialog::~AddUserDialog()
{
    delete ui;
}

void AddUserDialog::on_buttonBox_accepted() {
    emit user_submitted(this->newUser);
}

void AddUserDialog::on_firstNameLineEdit_textEdited(const QString &firstName)
{
    this->newUser->SetFirstName(firstName);
}


void AddUserDialog::on_lastNameLineEdit_textEdited(const QString &lastName)
{
    this->newUser->SetLastName(lastName);
}


void AddUserDialog::on_birthdayDateEdit_userDateChanged(const QDate &date)
{
    this->newUser->SetBirthday(date);
}

