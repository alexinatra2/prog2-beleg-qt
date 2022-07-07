#include "adduserdialog.h"
#include "ui_adduserdialog.h"
#include <QDebug>

AddUserDialog::AddUserDialog(QWidget *parent, User *user, QTableWidget *table) :
    QDialog(parent),
    ui(new Ui::AddUserDialog),
    newUser(user),
    table(table)
{
    ui->setupUi(this);
}

AddUserDialog::~AddUserDialog()
{
    delete ui;
}

void AddUserDialog::on_buttonBox_accepted() {
    int lastRow = table->rowCount();
    table->insertRow(lastRow);
    table->setItem(lastRow, 0, new QTableWidgetItem(this->newUser->GetFirstName()));
    table->setItem(lastRow, 1, new QTableWidgetItem(this->newUser->GetLastName()));
    table->setItem(lastRow, 2, new QTableWidgetItem(QString::number(this->newUser->GetAge())));
    accept();
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

