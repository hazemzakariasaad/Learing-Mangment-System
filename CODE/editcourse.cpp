#include "editcourse.h"
#include "ui_editcourse.h"
#include "Database.h"
#include "classes.h"
EditCourse::EditCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCourse)
{
    ui->setupUi(this);
    for(auto i:database.Crsvector){
        ui->comboBox_Course->addItem(QString::fromStdString(i.getName()));
    }
//    ui->lineEdit_Name->setText(QString::fromStdString(database.Crsvector[0].getName()));
//    ui->lineEdit_Code->setText(QString::fromStdString(database.Crsvector[0].getCode()));
//    ui->lineEdit_LecHall->setText(QString::fromStdString(database.Crsvector[0].getLecHall()));
//    ui->lineEdit_Time->setText(QString::fromStdString(database.Crsvector[0].getTime()));
//    for(auto i:database.Crsvector[0].getProfessors()){
//        ui->comboBox_Professors->addItem(QString::fromStdString(i.getfirstName()+i.getlastName()));
//    }
//    for(auto i:database.Crsvector[0].getStudents()){
//        ui->comboBox_Students->addItem(QString::fromStdString(i.getfirstName()+i.getlastName()));
//    }

}

bool EditCourse::isNum(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (isdigit(i)){
             //QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}

bool EditCourse::isString(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (!isdigit(i)){
//              QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}

EditCourse::~EditCourse()
{
    delete ui;
}

void EditCourse::on_pushButton_Mainmenu_clicked()
{
    hide();
}

void EditCourse::on_comboBox_Course_currentIndexChanged(int index)
{
    ui->comboBox_Professors->clear();
    ui->comboBox_Students->clear();
    ui->lineEdit_Name->setText(QString::fromStdString(database.Crsvector[index].getName()));
    ui->lineEdit_Code->setText(QString::fromStdString(database.Crsvector[index].getCode()));
    ui->lineEdit_LecHall->setText(QString::fromStdString(database.Crsvector[index].getLecHall()));
    ui->lineEdit_Time->setText(QString::fromStdString(database.Crsvector[index].getTime()));

    for(auto i:database.Crsvector[index].getProfessors()){
        ui->comboBox_Professors->addItem(QString::fromStdString(i.getfirstName()+" "+ i.getlastName()));
    }
    for(auto i:database.Crsvector[index].getStudents()){
        ui->comboBox_Students->addItem(QString::fromStdString(i.getfirstName()+" " +i.getlastName()));
    }
}

void EditCourse::on_pushButton_Save_clicked()
{
    int index = ui->comboBox_Course->currentIndex();
    int flag = 1;
    //emty field ya 3omdaaaaaa
  if(ui->lineEdit_Code->text().isEmpty()||ui->lineEdit_LecHall->text().isEmpty()||ui->lineEdit_Name->text().isEmpty()||ui->lineEdit_Time->text().isEmpty()){
          QMessageBox::warning(this,"ERROR","Empty field , try again");
    }
  else{
    for(auto i: database.Crsvector){
        if(i.getLecHall() == ui->lineEdit_LecHall->text().toStdString() && i.getTime() == ui->lineEdit_Time->text().toStdString()){
            flag = 0;
            QMessageBox::warning(this,"ERROR","Sorry, lecture hall or time entered is taken by another course!");
            break;
        }
    }

       if(isNum(ui->lineEdit_Name->text())){
           flag = 0;
           QMessageBox::warning(this,"ERROR","Invalid data type, try again");
       }

       if(flag == 1){
       database.Crsvector[index].setName(ui->lineEdit_Name->text().toStdString());
       database.Crsvector[index].setCode(ui->lineEdit_Code->text().toStdString());
       database.Crsvector[index].setLecHall(ui->lineEdit_LecHall->text().toStdString());
       database.Crsvector[index].setTime(ui->lineEdit_Time->text().toStdString());
       hide();
       }
}
}


void EditCourse::on_pushButton_Deletecourse_clicked()
{
    int x= ui->comboBox_Course->currentIndex();
    for(int i=0;i<database.Crsvector[x].getStudents().size();i++){
        database.Crsvector[x].remStudent(database.Crsvector[x].getStudents()[i]);
    }
    for(auto i:database.Crsvector[x].getProfessors()){
        database.Crsvector[x].remProfessor(i);
    }
    database.Crsvector.erase(database.Crsvector.begin()+x);
    hide();
}

