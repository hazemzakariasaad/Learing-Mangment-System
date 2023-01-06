#include "admin.h"
#include "ui_admin.h"
#include "mainmenu.h"
#include "QMessageBox"
Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}


void Admin::on_pushButton_clicked()
{
    if(ui->lineEditName->text()=="Admin" && ui->lineEditPassword->text()=="Admin"){
        MainMenu *menu = new MainMenu();
        menu->show();
        hide();
    }else{
        QMessageBox::warning(this,"ERROR","Wrong username or password, try again");
    }
}

