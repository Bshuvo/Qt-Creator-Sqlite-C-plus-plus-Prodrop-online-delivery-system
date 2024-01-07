
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include<QStackedWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QSqlQueryModel>


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
    //admin

    void on_admin_ui_clicked();

    void on_admin_login_clicked();

    void on_admin_l_cancel_clicked();

    void on_go_to_home_clicked();

    //delivery boy

    void on_delivery_boy_ui_clicked();

    void on_delivery_boy_login_clicked();

    void on_delivery_boy_cancel_clicked();

    void on_db_goto_home_clicked();

    //customer

    void on_customer_ui_clicked();

    void on_cust_login_3_clicked();

    void on_custcancel_3_clicked();

  void on_cust_goto_home_3_clicked();

    //quit

    void on_quit_clicked();

    void on_signupadmin_clicked();

    void on_signuptohome_clicked();



    void on_signupin_clicked();


    void on_custsignup_3_clicked();

    void on_delivery_boy_signup_clicked();



    void on_custhome_clicked();

    void on_deliveryboyhome_clicked();

    void on_enter_clicked();

    void on_cust_clicked();

    void on_dboy_clicked();



    void on_showordeer_clicked();

    void on_logout_clicked();

    void on_about_push_clicked();

    void on_habout_clicked();


    void on_loadorder_clicked();

private:
    Ui::MainWindow *ui;



    //admin
    QString username1,password1,signup_name , signup_email,signup_password,signup_contact,signup_username,signup_gender,signup_address,usertype;

    QSqlDatabase admindb;

    //delivery boy
    QString username2,password2;

    //data customer order
    QString name,pro_id,mobile,addd;


};

#endif // MAINWINDOW_H
