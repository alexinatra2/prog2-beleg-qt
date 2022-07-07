#include "adduserdialog.h"
#include "ui_adduserdialog.h"
#include <QDebug>

AddUserDialog::AddUserDialog(QWidget *parent, User *user) :
    QDialog(parent),
    ui(new Ui::AddUserDialog),
    newUser(user)
{
    ui->setupUi(this);
    ui->firstNameLineEdit->setText(user->firstName());
    ui->lastNameLineEdit->setText(user->lastName());
    ui->birthdayDateEdit->setDate(user->birthday());
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
    this->newUser->setFirstName(firstName);
}


void AddUserDialog::on_lastNameLineEdit_textEdited(const QString &lastName)
{
    this->newUser->setLastName(lastName);
}


void AddUserDialog::on_birthdayDateEdit_userDateChanged(const QDate &date)
{
    this->newUser->setBirthday(date);
}

