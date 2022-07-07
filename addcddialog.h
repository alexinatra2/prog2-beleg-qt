#ifndef ADDCDDIALOG_H
#define ADDCDDIALOG_H

#include <QDialog>
#include "medium.h"

namespace Ui {
class AddCdDialog;
}

class AddCdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCdDialog(QWidget *parent = nullptr);
    ~AddCdDialog();

signals:
    void medium_submitted(Medium *);

private:
    Ui::AddCdDialog *ui;
};

#endif // ADDCDDIALOG_H
