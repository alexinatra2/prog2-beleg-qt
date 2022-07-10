#ifndef SORTMEDIADIALOG_H
#define SORTMEDIADIALOG_H

#include <QDialog>

namespace Ui {
class SortMediaDialog;
}

enum SortingOrder {
    INSERTED,
    TYPE,
    AVAILABILITY,
    BORROWER,
    TITLE
};

class SortMediaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortMediaDialog(QWidget *parent = nullptr);
    ~SortMediaDialog();

signals:
    void sort_selected(SortingOrder order);
    void descending_selected(bool selected);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SortMediaDialog *ui;
};

#endif // SORTMEDIADIALOG_H
