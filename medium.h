#ifndef MEDIUM_H
#define MEDIUM_H

#include <QObject>
#include <QString>
#include <sstream>
#include "user.h"

class Medium : public QObject
{
    Q_OBJECT
public:
    explicit Medium(QObject *parent = nullptr);
    virtual QString details() = 0;
    virtual bool isAllowedToBeBorrowedBy(User *user);
    const QString &title() const;
    void setTitle(const QString &newTitle);
    const QString &description() const;
    void setDescription(const QString &newDescription);
    void setBorrower(User *newBorrower);
    User *borrower() const;
    bool available() const;

signals:
    void medium_submitted();

private:
    QString _title;
    QString _description;
    User *_borrower;
};

#endif // MEDIUM_H
