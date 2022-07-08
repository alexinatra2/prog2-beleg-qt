#ifndef MEDIUMDETAILSDIALOG_H
#define MEDIUMDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class MediumDetailsDialog;
}

class MediumDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MediumDetailsDialog(QWidget *parent = nullptr);
    ~MediumDetailsDialog();

private:
    Ui::MediumDetailsDialog *ui;
};

#endif // MEDIUMDETAILSDIALOG_H
