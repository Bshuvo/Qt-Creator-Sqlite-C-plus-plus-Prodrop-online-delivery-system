
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    admindb = QSqlDatabase::addDatabase("QSQLITE");
    admindb.setDatabaseName("E:/QT PROJECT/database sqlite/prodropadmin.db");
    admindb.open();



}

MainWindow::~MainWindow()
{
    admindb.close();
    delete ui;

}

//ADMIN PANEL

void MainWindow::on_admin_ui_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_admin_login_clicked()
{
   QString username1 = ui->admin_username1->text();
   QString password1 = ui->admin_password1->text();

    QSqlQuery query;

    query.exec("SELECT * FROM admins WHERE username = '"+username1+"' AND password = '"+password1+"'");



    if(query.next())
    {
        QMessageBox ::information(this,"Information","Login success!!");
        ui->stackedWidget->setCurrentIndex(5);

        ui->showadminname->setText(query.value(2).toString());

    }
    else
    {
        QMessageBox::warning(this,"Warning","Please Enter Valid Username or Password");
    }
    ui->admin_username1->clear();
    ui->admin_password1->clear();


}


void MainWindow::on_admin_l_cancel_clicked()
{
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Information","Are you sure to close the application?"),QMessageBox::Yes|QMessageBox::No;
        if (reply == QMessageBox::Yes )
        {
            QApplication::quit();
        }
    }
}

void MainWindow::on_go_to_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}





//DELIVERY BOY

void MainWindow::on_delivery_boy_ui_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_delivery_boy_login_clicked()
{
    QString username1 = ui->delivery_boy_username->text();
    QString password1 = ui->delivery_boy_password->text();
    QSqlQuery query;

    query.exec("SELECT * FROM deliveryboy WHERE username = '"+username1+"' AND password = '"+password1+"'");



    if(query.next())
    {
        QMessageBox ::information(this,"Information","Login success!!");
        ui->stackedWidget->setCurrentIndex(8);
        // ui->demo->setText(query.value(2).toString());

    }
    else
    {
        QMessageBox::warning(this,"Warning","Please Enter Valid Username or Password");
    }
    ui->delivery_boy_username->clear();
    ui->delivery_boy_password->clear();
}


void MainWindow::on_delivery_boy_cancel_clicked()
{
    {
        QMessageBox :: StandardButton reply;
        reply = QMessageBox :: question (this,"Cancel","Are you sure to close the application"),QMessageBox::Yes|QMessageBox::No;
        if(reply == QMessageBox::Yes)
        {
            QApplication ::quit();
        }

    }
}


void MainWindow::on_db_goto_home_clicked()
{
    ui ->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_delivery_boy_signup_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}





//CUSTOMER


void MainWindow::on_customer_ui_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_cust_login_3_clicked()
{
    QString username1 = ui->custusername_3->text();
    QString password1 = ui->custpassword_3->text();
    QSqlQuery query;

    query.exec("SELECT * FROM customers WHERE username = '"+username1+"' AND password = '"+password1+"'");



    if(query.next())
    {
        QMessageBox ::information(this,"Information","Login success!!");
        ui->stackedWidget->setCurrentIndex(7);



    }
    else
    {
        QMessageBox::warning(this,"Warning","Please Enter Valid Username or Password");
    }
    ui->custusername_3->clear();
    ui->custpassword_3->clear();

}


void MainWindow::on_custcancel_3_clicked()
{

    {
        QMessageBox :: StandardButton reply;
        reply = QMessageBox :: question (this,"Cancel","Are you sure to close the application"),QMessageBox::Yes|QMessageBox::No;
        if(reply == QMessageBox::Yes)
        {
            QApplication ::quit();
        }

    }

}

void MainWindow::on_cust_goto_home_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_custsignup_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}



// QUIT

void MainWindow::on_quit_clicked()
{
    {
    QMessageBox::StandardButton reply;
    reply = QMessageBox :: question(this,"Quit","Are you sure to close the application"),QMessageBox::Yes|QMessageBox::No;
    if(reply == QMessageBox::Yes)
    {
        QApplication :: quit();
    }
    }
}

// admin sub page

void MainWindow::on_logout_clicked()
{
    {
    QMessageBox::StandardButton reply;
    reply = QMessageBox :: question(this,"Logout","Are you want to logout"),QMessageBox::Yes|QMessageBox::No;
    if(reply == QMessageBox::Yes)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    }
}


//sign up
void MainWindow::on_signupadmin_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_signuptohome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//input database from signup button

void MainWindow::on_signupin_clicked()
{
     QString signup_name=ui->signup_name_in->text();
    ui->signup_name_in->clear();

     QString signup_email=ui->signup_email_in->text();
    ui->signup_email_in->clear();

     QString signup_password=ui->signup_password_in->text();
    ui->signup_password_in->clear();

     QString signup_contact=ui->signup_contact_in->text();
    ui->signup_contact_in->clear();

     QString signup_username=ui->signup_username_in->text();
    ui->signup_username_in->clear();

     QString signup_gender = ui->gender_in->currentText();
     QString signup_address=ui->signup_address_in->text();
     ui->signup_address_in->clear();

     QString usertype = ui->user_type->currentText();

     if(usertype == "Admin")

     {
        QSqlQuery query;
        query.exec("INSERT INTO admins(Username,Password,Name,Email,Contact,Gender,Address) VALUES('"+signup_username+"','"+signup_password+"','"+signup_name+"','"+signup_email+"','"+signup_contact+"','"+signup_gender+"','"+signup_address+"')");


        QMessageBox :: information(this,"signup","Signup successful , Please login !");

      }

     else if(usertype == "Customer")

     {
        QSqlQuery query;
        query.exec("INSERT INTO customers(Username,Password,Name,Email,Contact,Gender,Address) VALUES('"+signup_username+"','"+signup_password+"','"+signup_name+"','"+signup_email+"','"+signup_contact+"','"+signup_gender+"','"+signup_address+"')");


        QMessageBox :: information(this,"signup","Signup successful , Please login !");

     }

    else if(usertype == "Delivery Boy")

     {
        QSqlQuery query;
        query.exec("INSERT INTO deliveryboy(Username,Password,Name,Email,Contact,Gender,Address) VALUES('"+signup_username+"','"+signup_password+"','"+signup_name+"','"+signup_email+"','"+signup_contact+"','"+signup_gender+"','"+signup_address+"')");


        QMessageBox :: information(this,"signup","Signup successful , Please login !");

     }

}



void MainWindow::on_custhome_clicked()
{
    ui ->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_deliveryboyhome_clicked()
{
    ui ->stackedWidget->setCurrentIndex(0);
}





///customer page
///

void MainWindow::on_enter_clicked()
{

    QString name=ui->cName->text();
     ui->cName->clear();
    QString pro_id=ui->productid->text();
    ui->productid->clear();

    QString addd=ui->proadd->text();
    ui->proadd->clear();

    QString mobile=ui->contactp->text();
    ui->contactp->clear();

     QSqlQuery query;
     query.exec("INSERT INTO orders(Username,ProductId,Contact,Address) VALUES('"+name+"','"+pro_id+"','"+addd+"','"+mobile+"')");


    QMessageBox :: information(this,"Order","Order Confirmed :)");

}



//showing list of data

void MainWindow::on_cust_clicked()
{


    QSqlQueryModel *model = new QSqlQueryModel();

    admindb.open();
    QSqlQuery* query = new  QSqlQuery(admindb);

    query->prepare("SELECT * FROM customers ");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);


}


void MainWindow::on_dboy_clicked()
{

    QSqlQueryModel *model2 = new QSqlQueryModel();

    admindb.open();
    QSqlQuery* query = new  QSqlQuery(admindb);

    query->prepare("SELECT * FROM deliveryboy ");
    query->exec();
    model2->setQuery(*query);
    ui->tableView->setModel(model2);
}


void MainWindow::on_showordeer_clicked()
{

    QSqlQueryModel *model3 = new QSqlQueryModel();

    admindb.open();
    QSqlQuery* query = new  QSqlQuery(admindb);

    query->prepare("SELECT * FROM orders ");
    query->exec();
    model3->setQuery(*query);
    ui->tableView->setModel(model3);
}




void MainWindow::on_about_push_clicked()
{
     ui ->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_habout_clicked()
{
     ui ->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_loadorder_clicked()
{
     QSqlQueryModel *model3 = new QSqlQueryModel();

     admindb.open();
     QSqlQuery* query = new  QSqlQuery(admindb);

     query->prepare("SELECT * FROM orders ");
     query->exec();
     model3->setQuery(*query);
     ui->tabled->setModel(model3);

}

