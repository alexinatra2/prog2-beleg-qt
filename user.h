#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDate>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    QString GetFirstName() {
        return this->_firstName;
    }
    void SetFirstName(QString firstName) {
        this->_firstName = firstName;
    }
    QString GetLastName() {
        return this->_lastName;
    }
    void SetLastName(QString lastName) {
        this->_lastName = lastName;
    }
    QDate GetBirthday() {
        return this->_birthday;
    }
    void SetBirthday(QDate birthday) {
        this->_birthday = birthday;
    }
    QString GetFullName() {
        return this->_firstName + ' ' + this->_lastName;
    }
    int GetAge() {
        return _birthday.daysTo(QDate::currentDate()) / 365.25;
    }

private:
    QString _firstName;
    QString _lastName;
    QDate _birthday;
};

#endif // USER_H
