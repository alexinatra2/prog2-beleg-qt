#ifndef USER_H
#define USER_H

#include <QObject>
#include <string>
#include <sstream>
#include <ctime>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    std::string GetFirstName() {
        return this->_firstName;
    }
    void SetFirstName(std::string firstName) {
        this->_firstName = firstName;
    }
    std::string GetLastName() {
        return this->_lastName;
    }
    void SetLastName(std::string lastName) {
        this->_lastName = lastName;
    }
    std::time_t GetBirthday() {
        return this->_birthday;
    }
    void SetBirthday(std::time_t birthday) {
        this->_birthday = birthday;
    }
    std::string GetFullName() {
        std::stringstream ss;
        ss << this->_firstName << ' ' << this->_lastName;
        return ss.str();
    }
    int GetAge() {
        return std::difftime(this->_birthday, std::time(0)) *
                60 * // minutes
                60 * // hours
                24 * // days
                365.25;
    }

private:
    std::string _firstName;
    std::string _lastName;
    std::time_t _birthday;
};

#endif // USER_H
