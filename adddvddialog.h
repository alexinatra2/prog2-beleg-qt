#ifndef ADDDVDDIALOG_H
#define ADDDVDDIALOG_H

#include <QDialog>
#include "dvd.h"

namespace Ui {
class AddDvdDialog;
}

class AddDvdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDvdDialog(QWidget *parent = nullptr, Dvd *dvd = nullptr);
    ~AddDvdDialog();

signals:
    void medium_submitted(Medium *);

private slots:
    void on_titleLineEdit_textEdited(const QString &arg1);

    void on_descriptionLineEdit_textEdited(const QString &arg1);

    void on_lengthSpinBox_valueChanged(int arg1);

    void on_ageRatingSpinBox_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::AddDvdDialog *ui;
    Dvd *dvd;
};

#endif // ADDDVDDIALOG_H
