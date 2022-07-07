#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDate>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);

    const QString &firstName() const;
    void setFirstName(const QString &newFirstName);
    const QString &lastName() const;
    void setLastName(const QString &newLastName);
    const QDate &birthday() const;
    void setBirthday(const QDate &newBirthday);
    const QString fullName() const;
    const int age() const;

private:
    QString _firstName;
    QString _lastName;
    QDate _birthday;
};

#endif // USER_H
