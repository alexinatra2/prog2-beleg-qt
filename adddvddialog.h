#ifndef ADDDVDDIALOG_H
#define ADDDVDDIALOG_H

#include <QDialog>
#include "medium.h"

namespace Ui {
class AddDvdDialog;
}

class AddDvdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDvdDialog(QWidget *parent = nullptr);
    ~AddDvdDialog();

signals:
    void medium_submitted(Medium *);

private:
    Ui::AddDvdDialog *ui;
};

#endif // ADDDVDDIALOG_H
