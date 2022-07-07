#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include <qtablewidget.h>
#include "user.h"

namespace Ui {
class AddUserDialog;
}

class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog(QWidget *parent = nullptr, User *newUser = nullptr);
    ~AddUserDialog();

private slots:
    void on_buttonBox_accepted();

    void on_firstNameLineEdit_textEdited(const QString &arg1);

    void on_lastNameLineEdit_textEdited(const QString &arg1);

    void on_birthdayDateEdit_userDateChanged(const QDate &date);

signals:
    void user_submitted(User *user);

private:
    Ui::AddUserDialog *ui;
    User *newUser;
};

#endif // ADDUSERDIALOG_H
