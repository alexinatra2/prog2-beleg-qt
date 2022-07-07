#include "addbookdialog.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent, Book *book) :
    QDialog(parent),
    ui(new Ui::AddBookDialog),
    book(book)
{
    ui->setupUi(this);
    ui->titleLineEdit->setText(book->title());
    ui->titleLineEdit->setText(book->description());
    ui->authorLineEdit->setText(book->author());
    ui->pagesSpinBox->setValue(book->pages());
    ui->chaptersSpinBox->setValue(book->chapters());
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

void AddBookDialog::on_buttonBox_accepted()
{
    emit medium_submitted(this->book);
}


void AddBookDialog::on_titleLineEdit_textEdited(const QString &title)
{
    this->book->setTitle(title);
}


void AddBookDialog::on_descriptionLineEdit_textEdited(const QString &description)
{
    this->book->setDescription(description);
}


void AddBookDialog::on_authorLineEdit_textEdited(const QString &author)
{
    this->book->setAuthor(author);
}


void AddBookDialog::on_pagesSpinBox_valueChanged(int pages)
{
    this->book->setPages(pages);
}


void AddBookDialog::on_chaptersSpinBox_valueChanged(int chapters)
{
    this->book->setChapters(chapters);
}

