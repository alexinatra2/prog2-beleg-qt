#ifndef BORROWDIALOG_H
#define BORROWDIALOG_H

#include <QDialog>

namespace Ui {
class BorrowDialog;
}

class BorrowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowDialog(QWidget *parent = nullptr);
    ~BorrowDialog();

private:
    Ui::BorrowDialog *ui;
};

#endif // BORROWDIALOG_H
