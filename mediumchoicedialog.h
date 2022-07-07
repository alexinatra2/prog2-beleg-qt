#ifndef MEDIUMCHOICEDIALOG_H
#define MEDIUMCHOICEDIALOG_H

#include <QDialog>
#include "medium.h"

namespace Ui {
class MediumChoiceDialog;
}

class MediumChoiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MediumChoiceDialog(QWidget *parent = nullptr);
    ~MediumChoiceDialog();

private slots:
    void on_buttonBox_accepted();

signals:
    void medium_submitted(Medium *);

private:
    Ui::MediumChoiceDialog *ui;
};

#endif // MEDIUMCHOICEDIALOG_H
