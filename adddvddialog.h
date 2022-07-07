#ifndef ADDDVDDIALOG_H
#define ADDDVDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDvdDialog;
}

class AddDvdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDvdDialog(QWidget *parent = nullptr);
    ~AddDvdDialog();

private:
    Ui::AddDvdDialog *ui;
};

#endif // ADDDVDDIALOG_H
