#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include "book.h"

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBookDialog(QWidget *parent = nullptr,
                           Book *book = nullptr);
    ~AddBookDialog();

signals:
    void medium_submitted(Medium *);

private slots:
    void on_buttonBox_accepted();
    void on_titleLineEdit_textEdited(const QString &);
    void on_descriptionLineEdit_textEdited(const QString &);
    void on_authorLineEdit_textEdited(const QString &);
    void on_pagesSpinBox_valueChanged(int);
    void on_chaptersSpinBox_valueChanged(int);

private:
    Ui::AddBookDialog *ui;
    Book *book;
};

#endif // ADDBOOKDIALOG_H
