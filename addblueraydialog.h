#ifndef ADDBLUERAYDIALOG_H
#define ADDBLUERAYDIALOG_H

#include <QDialog>

namespace Ui {
class AddBluerayDialog;
}

class AddBluerayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBluerayDialog(QWidget *parent = nullptr);
    ~AddBluerayDialog();

private:
    Ui::AddBluerayDialog *ui;
};

#endif // ADDBLUERAYDIALOG_H
