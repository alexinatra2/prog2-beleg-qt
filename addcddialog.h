#ifndef ADDCDDIALOG_H
#define ADDCDDIALOG_H

#include <QDialog>
#include "cd.h"

namespace Ui {
class AddCdDialog;
}

class AddCdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCdDialog(QWidget *parent = nullptr, Cd *cd = nullptr);
    ~AddCdDialog();

signals:
    void medium_submitted(Medium *);

private slots:
    void on_titleLineEdit_textEdited(const QString &arg1);

    void on_descriptionLineEdit_textEdited(const QString &arg1);

    void on_totalLengthSpinBox_valueChanged(int arg1);

    void on_numberOfTracksSpinBox_valueChanged(int arg1);

    void on_releaseDateDateEdit_userDateChanged(const QDate &date);

    void on_buttonBox_accepted();

private:
    Ui::AddCdDialog *ui;
    Cd *cd;
};

#endif // ADDCDDIALOG_H
