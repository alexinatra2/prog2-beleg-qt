#include "user.h"

User::User(QObject *parent)
    : QObject{parent}
{
}

const QString &User::firstName() const
{
    return _firstName;
}

void User::setFirstName(const QString &newFirstName)
{
    _firstName = newFirstName;
}

const QString &User::lastName() const
{
    return _lastName;
}

void User::setLastName(const QString &newLastName)
{
    _lastName = newLastName;
}

const QDate &User::birthday() const
{
    return _birthday;
}

void User::setBirthday(const QDate &newBirthday)
{
    _birthday = newBirthday;
}

const QString User::fullName() const {
    return this->_firstName + ' ' + this->_lastName;
}

const int User::age() const {
    return this->_birthday.daysTo(QDate::currentDate()) / 365.25;
}
