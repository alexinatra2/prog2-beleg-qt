#ifndef BORROWMEDIUMDIALOG_H
#define BORROWMEDIUMDIALOG_H

#include <QDialog>
#include <vector>
#include "medium.h"
#include "user.h"

namespace Ui {
class BorrowMediumDialog;
}

class BorrowMediumDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowMediumDialog(QWidget *parent = nullptr, std::vector<User *> *eligibleUsers = nullptr);
    ~BorrowMediumDialog();

signals:
    void borrower_chosen(User *);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::BorrowMediumDialog *ui;
    std::vector<User *> *eligibleUsers;
};

#endif // BORROWMEDIUMDIALOG_H
