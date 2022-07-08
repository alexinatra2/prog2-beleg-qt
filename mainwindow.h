#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <vector>

#include "medium.h"
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

signals:
    void user_table_modified();
    void medium_table_modified();
    void closing();

private:
    Ui::MainWindow *ui;
    std::vector<Medium *> *media = new std::vector<Medium *>();
    std::vector<User *> *users = new std::vector<User *>();

protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
