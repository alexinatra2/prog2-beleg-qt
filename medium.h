#ifndef MEDIUM_H
#define MEDIUM_H

#include <QObject>
#include <ostream>
#include <string>
#include "user.h"

enum MediumType {
    BOOK,
    CD,
    DVD,
    BLUERAY
};

class Medium : public QObject
{
    Q_OBJECT
public:
    explicit Medium(QObject *parent = nullptr);
    std::string GetTitle() {
        return this->_title;
    }
    void SetTitle(std::string title) {
        this->_title = title;
    }
    std::string GetDescription() {
        return this->_description == nullptr ? "no description" : *this->_description;
    }
    void SetDescription(std::string *description) {
        this->_description = description;
    }
    User *GetBorrowingUser() {
        return this->_borrowingUser;
    }
    void SetBorrowingUser(User *user) {
        this->_borrowingUser = user;
    }
    MediumType GetType() {
        return this->_type;
    }
    std::string GetTypeString() {
        switch(this->_type) {
        case BOOK:
            return "book";
        case CD:
            return "cd";
        case DVD:
            return "dvd";
        case BLUERAY:
            return "blueray";
        }
    }
    bool isBorrowed() {
        return _borrowingUser == nullptr;
    }
    virtual std::ostream &Show(std::ostream &os) {
        return os;
    }

private slots:


private:
    std::string _title;
    std::string *_description;
    User *_borrowingUser;

protected:
    MediumType _type;
};

#endif // MEDIUM_H
