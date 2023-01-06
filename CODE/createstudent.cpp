#include "createstudent.h"
#include "ui_createstudent.h"
#include <vector>
#include <string>
#include <QMessageBox>
#include <algorithm>
using namespace std ;
CreateStudent::CreateStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateStudent)

{
    ui->setupUi(this);
    ui->comboBox->addItem("1year");
      ui->comboBox->addItem("2year");
        ui->comboBox->addItem("3year");
          ui->comboBox->addItem("4year");
            ui->comboBox->addItem("5year");
    for(auto c:database.Crsvector){
 ui->listWidget->addItem(QString::fromStdString(c.getName())) ;
//  ui->comboBox->addItem(QString::fromStdString(c.getName())) ;
    }
}

CreateStudent::~CreateStudent()
{
    delete ui;
}
Student s ;

void CreateStudent::on_pushButton_save_clicked()
{     if(isnum(ui->lineEdit_fname_3->text())||isnum(ui->lineEdit_lname_3->text())){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again"); // hz11 for string yaa 3omda
    }
    else if(ui->lineEdit_fname_3->text().isEmpty()||ui->lineEdit_lname_3->text().isEmpty()||ui->lineEdit_email->text().isEmpty()||ui->lineEdit_mobile_3->text().isEmpty()){
         QMessageBox::warning(this,"ERROR","Empty field, try again"); // hz11 for empty yaa 3omda
    }

    else if(isstring(ui->lineEdit_mobile_3->text())){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again");// hz11 for num yaa 3omda

    }
    else if( !age(ui->spinBox->value())){
          QMessageBox::warning(this,"ERROR","Student must be older than 15");// hz11 for age yaa 3omda
    }
        else{
    string a = ui->lineEdit_fname_3->text().toStdString();

    string b = ui->lineEdit_lname_3->text().toStdString();
    int c = ui->spinBox->value();
    string d = ui->lineEdit_mobile_3->text().toStdString();
    string e = ui->lineEdit_email->text().toStdString();
    string f =ui->comboBox->currentText().toStdString();
        s = Student(a,b,c,d,e,f);
   for(int i=0;i<ui->listWidget->count();i++){
       if(ui->listWidget->item(i)->text() == "selected")
            pushToVector(i,s);
   }
   database.stdsVector.push_back(s);
   close();
}
}



void CreateStudent:: pushToVector(int row,Student &s){
    database.Crsvector[row].addStudent(s);
}


void CreateStudent::on_pushButton_clicked()
{
       QListWidgetItem *it = ui->listWidget->item(ui->listWidget->currentRow());
               it->setText("selected");
//ui->listWidget->currentRow() ;
}
bool CreateStudent:: isnum(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (isdigit(i)){
             //QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
 }

bool CreateStudent :: isstring(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (!isdigit(i)){
//              QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}
                                          // hz11 for age < 15
bool CreateStudent::age(int s){
    if (s<15)
        return false ;
    return true ;
}
