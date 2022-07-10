#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <vector>

#include "medium.h"
#include "sortmediadialog.h"
#include "user.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getUserIndex(User *user);
    void importXml();

private slots:
    void on_addUserButton_released();
    void on_addMediumButton_released();

    void addUser(User *user);
    void removeUser();

    void addMedium(Medium *medium);
    void removeMedium();
    void getMediumDetails();
    void borrowDialog();
    void borrowMedium(User *user);
    void returnMedium();

    void populateUserTable();
    void populateMediumTable();

    void exportXml();

    void on_sortMediaButton_released();
    void setMediaDescending(bool newMediaDescending);
    void setMediaOrder(SortingOrder newMediaOrder);
    void sortMedia();

signals:
    void user_table_modified();
    void medium_table_modified();
    void media_sort_options_changed();
    void closing();

private:
    Ui::MainWindow *ui;
    std::vector<Medium *> *media = new std::vector<Medium *>();
    std::vector<User *> *users = new std::vector<User *>();
    bool mediaDescending = false;
    SortingOrder mediaOrder = SortingOrder::INSERTED;

protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
