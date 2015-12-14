#include "mainwindow.h"
#include "ui_mainwindow.h"

//Constructor - more info later
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logindb = QSqlDatabase::addDatabase("QSQLITE");
    logindb.setDatabaseName("login.sqlite");

    if(!logindb.open())
    {
        ui->label_status->setText("User Database Could not Connect");
    }
    else
    {
        ui->label_status->setText("User Database Connected");
    }
    //connect(ui->pushButton_login,SIGNAL(clicked()), this, SLOT(login_menu()));

}

//Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}

//LoginIn button that takes you to mainWindow
void MainWindow::on_pushButton_login_clicked()
{
    login_menu();
}

//Creates pointer and displays mainWindow
void MainWindow::open_display_window()
{
    displaywindow_object = new DisplayWindow();
    displaywindow_object->show();
    this->close();
}

//Connects to SQLite Database to get users logIn info
void MainWindow::login_menu()
{
    QString username, password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!logindb.isOpen())
    {
        qDebug() << "User Database Failed to Connect";
        return;
    }

    QSqlQuery qry;

    if(qry.exec("SELECT * FROM users WHERE username='"+username+"'and password='"+password+"'"))
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }

        if(count == 1)
        {
            ui->label_status->setText("Login Successful!");

            logindb.close();
            open_display_window();
        }
        if(count > 1)
        {
            ui->label_status->setText("Duplicate Username and Password!");
        }
        if(count < 1)
        {
            ui->label_status->setText("Username or Password Incorrect, Try Again!");
        }
    }
}
