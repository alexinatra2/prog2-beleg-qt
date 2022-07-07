#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include "medium.h"

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBookDialog(QWidget *parent = nullptr);
    ~AddBookDialog();

signals:
    void medium_submitted(Medium *);

private:
    Ui::AddBookDialog *ui;
};

#endif // ADDBOOKDIALOG_H
