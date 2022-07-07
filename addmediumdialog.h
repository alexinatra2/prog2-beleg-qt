#ifndef ADDMEDIUMDIALOG_H
#define ADDMEDIUMDIALOG_H

#include <QDialog>

#include "medium.h"

namespace Ui {
class AddMediumDialog;
}

class AddMediumDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMediumDialog(QWidget *parent = nullptr);
    ~AddMediumDialog();

private:
    Ui::AddMediumDialog *ui;
    Medium *newMedium;

signals:
    void createMedium();
};

#endif // ADDMEDIUMDIALOG_H
