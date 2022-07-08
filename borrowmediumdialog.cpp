#include "borrowmediumdialog.h"
#include "ui_borrowmediumdialog.h"

#include <QStringList>
#include <QStringListModel>

BorrowMediumDialog::BorrowMediumDialog(QWidget *parent, std::vector<User *> *eligibleUsers) :
    QDialog(parent),
    ui(new Ui::BorrowMediumDialog),
    eligibleUsers(eligibleUsers)
{
    ui->setupUi(this);
    QListView *eligibleUsersList = ui->eligibleUsersListView;
    QStringList *fullNames = new QStringList();
    for (User *u : *eligibleUsers) {
        *fullNames << u->fullName();
    }
    QStringListModel *model = new QStringListModel(this);
    model->setStringList(*fullNames);
    eligibleUsersList->setModel(model);
    eligibleUsersList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    eligibleUsersList->setSelectionMode(QAbstractItemView::SingleSelection);
}

BorrowMediumDialog::~BorrowMediumDialog()
{
    delete ui;
}

void BorrowMediumDialog::on_buttonBox_accepted()
{
    QListView *eligibleUsersList = ui->eligibleUsersListView;
    if (!eligibleUsersList->selectionModel()->hasSelection()) {
        reject();
    }
    int row = eligibleUsersList->selectionModel()->selectedIndexes()[0].row();
    emit borrower_chosen((*this->eligibleUsers)[row]);
}

