#include "createprofessor.h"
#include "ui_createprofessor.h"
#include "Database.h"
#include "QMessageBox"

CreateProfessor::CreateProfessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProfessor)
{
    ui->setupUi(this);
    for(auto c:database.Crsvector){
     ui->listWidget->addItem(QString::fromStdString(c.getName())) ;
     //ui->comboBox->addItem(QString::fromStdString(c.getName())) ;
        }
}
Professor p1;
CreateProfessor::~CreateProfessor()
{
    delete ui;
}

void CreateProfessor::on_pushButton_clicked()
{
    if(isNum(ui->lineEditFirstName->text())||isNum(ui->lineEditLastName->text())||isNum(ui->lineEditTitle->text())){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again"); // hz11 for string yaa 3omda
    }else if(isString(ui->lineEditMobile->text())){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again"); // hz11 for num yaa 3omda
    }
    else if(ui->lineEditFirstName->text().isEmpty()||ui->lineEditLastName->text().isEmpty()||ui->lineEditEmail->text().isEmpty()||ui->lineEditTitle->text().isEmpty()||ui->lineEditMobile->text().isEmpty()){
         QMessageBox::warning(this,"ERROR","Empty field, try again"); // hz11 for empty yaa 3omda
    }
    else if( !age(ui->spinBoxAge->value())){
          QMessageBox::warning(this,"ERROR","Professor must be older than 22");  // hz11 for age yaa 3omda
    }
    else{
    string FirstName(ui->lineEditFirstName->text().toStdString());
     string LastName(ui->lineEditLastName->text().toStdString());
     string Email (ui->lineEditEmail->text().toStdString());
     string Title(ui->lineEditTitle->text().toStdString());
     string Mobile(ui->lineEditMobile->text().toStdString());
     int Age (ui->spinBoxAge->value());
     //string Age (ui->lineEditAge->text().toInt());
     Professor p1(FirstName,LastName,Age,Mobile,Email,Title);
     for(int i=0;i<ui->listWidget->count();i++){
         if(ui->listWidget->item(i)->text() == "selected"){
            database.Crsvector[i].addProfessor(p1);
         }
     }
     database.Profsvector.push_back(p1);
     // ui->label->setText(QString::fromStdString(p1.getfirstName()));
     close();
    }
}


void CreateProfessor::on_listWidget_currentRowChanged(int currentRow)
{
//    if(ui->listWidget->item(ui->listWidget->currentRow())->text() != "selected"){
//             database.Crsvector[currentRow].addProfessor(p1);
//    }
}


void CreateProfessor::on_pushButton_2_clicked()
{
    QListWidgetItem *it = ui->listWidget->item(ui->listWidget->currentRow());
                   it->setText("selected");
}

bool CreateProfessor::isNum(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (isdigit(i)){
             //QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}

bool CreateProfessor::isString(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (!isdigit(i)){
//              QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}
// hz11 for age <20
bool CreateProfessor::age(int s){
    if (s<22)
        return false ;
    return true ;
}
