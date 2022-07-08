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

private slots:
    void on_addUserButton_released();
    void on_addMediumButton_released();

    void addUser(User *user);
    void removeUser();
    void populateUserTable();

    void addMedium(Medium *medium);
    void removeMedium();
    void getMediumDetails();
    void populateMediumTable();

signals:
    void user_table_modified();
    void medium_table_modified();

private:
    Ui::MainWindow *ui;
    std::vector<Medium *> *media = new std::vector<Medium *>();
    std::vector<User *> *users = new std::vector<User *>();
};
#endif // MAINWINDOW_H
