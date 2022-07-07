#ifndef ADDCDDIALOG_H
#define ADDCDDIALOG_H

#include <QDialog>

namespace Ui {
class AddCdDialog;
}

class AddCdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCdDialog(QWidget *parent = nullptr);
    ~AddCdDialog();

private:
    Ui::AddCdDialog *ui;
};

#endif // ADDCDDIALOG_H
