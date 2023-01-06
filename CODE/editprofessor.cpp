#include "editprofessor.h"
#include "ui_editprofessor.h"
#include "classes.h"
#include <vector>
#include "QMessageBox"
#include "Database.h"
#include <algorithm>


EditProfessor::EditProfessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProfessor)
{
    ui->setupUi(this);


    for(auto i : database.Profsvector){
      ui->comboBox_Profs->addItem(QString::fromStdString((i.getfirstName()) +" " + i.getlastName()));
    }

}

bool EditProfessor::isNum(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (isdigit(i)){
             //QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}

bool EditProfessor::isString(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (!isdigit(i)){
//              QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}


void EditProfessor::on_comboBox_Profs_currentIndexChanged(int index)
{
    ui->comboBox_courses->clear();
        ui->comboBox_remcrs->clear();
        ui->comboBox_addcrs->clear();
        ui->comboBox_addcrs->addItem("None");

            for(auto c: database.Crsvector){
                bool flag =1;
            for(auto i : database.Profsvector[index].getCourses()){
                if( c.getCode() == i.getCode()){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ui->comboBox_addcrs->addItem(QString::fromStdString((c.getName())));
        }
    ui->lineEdit_first->setText(QString::fromStdString(database.Profsvector[index].getfirstName()));
    ui->lineEdit_last->setText(QString::fromStdString(database.Profsvector[index].getlastName()));
    ui->lineEdit_mobile->setText(QString::fromStdString(database.Profsvector[index].getMobile()));
    ui->lineEdit_email->setText(QString::fromStdString(database.Profsvector[index].getEmail()));
    ui->lineEdit_ttl->setText(QString::fromStdString(database.Profsvector[index].getTitle()));
    ui->lineEdit_age->setText(QString::number(database.Profsvector[index].getAge()));

    vector <Course> v = database.Profsvector[index].getCourses();
    for(auto i : v){
      ui->comboBox_courses->addItem(QString::fromStdString((i.getName())));
    }

    for(auto i : v){
      ui->comboBox_remcrs->addItem(QString::fromStdString((i.getName())));
    }

}


void EditProfessor::on_ok_clicked()
{
   this->close();
}


void EditProfessor::on_save_clicked()
{
    int chosenprof = ui->comboBox_Profs->currentIndex();
    int chosencrs = ui->comboBox_addcrs->currentIndex();
    if(isNum(ui->lineEdit_first->text()) || isNum(ui->lineEdit_last->text()) || isNum(ui->lineEdit_ttl->text()) ){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again"); // kol validation
    }
    else if(isString(ui->lineEdit_mobile->text()) || isString(ui->lineEdit_age->text())){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again");
    }
    else if(ui->lineEdit_age->text().isEmpty()||ui->lineEdit_first->text().isEmpty()||ui->lineEdit_last->text().isEmpty()||ui->lineEdit_email->text().isEmpty()||ui->lineEdit_mobile->text().isEmpty()){
          QMessageBox::warning(this,"ERROR","Empty field , try again");
    }
    else if(ui->lineEdit_age->text().toInt()<15)     // kol validation
            QMessageBox::warning(this,"ERROR","Wrong age , try again");
    else{
    database.Profsvector[chosenprof].setfirstName(ui->lineEdit_first->text().toStdString());
    database.Profsvector[chosenprof].setlastName(ui->lineEdit_last->text().toStdString());
    database.Profsvector[chosenprof].setTitle(ui->lineEdit_ttl->text().toStdString());
     database.Profsvector[chosenprof].setAge(ui->lineEdit_age->text().toInt());
    database.Profsvector[chosenprof].setMobile(ui->lineEdit_mobile->text().toStdString());
    database.Profsvector[chosenprof].setEmail(ui->lineEdit_email->text().toStdString());

    if(chosencrs!=0){
        for(int f=0;f<database.Crsvector.size();f++){
            if(ui->comboBox_addcrs->itemText(chosencrs).toStdString()==database.Crsvector[f].getName()){
                database.Crsvector[f].addProfessor(database.Profsvector[chosenprof]);
                break;
            }
        }

        QMessageBox::information(this, "Added Course", "Course added succesfully!");
    }


    QMessageBox::information(this, "Save Changes", "Details updated succesfully!");

    this->close();
    }


}


void EditProfessor::on_delete_2_clicked()
{
    int chosenprof = ui->comboBox_Profs->currentIndex();
    int deletecrs = ui->comboBox_remcrs->currentIndex();
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "Delete Course", "Are you sure you want to delete this Course?", QMessageBox::Cancel | QMessageBox::Yes);

    if(reply == QMessageBox::Yes){
    database.Profsvector[chosenprof].getCourses()[deletecrs].remProfessor(database.Profsvector[chosenprof]);
    this->close();
    }

}

void EditProfessor::on_delete_prof_clicked()
{
    int std = ui->comboBox_Profs->currentIndex();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete Professor", "Are you sure you want to delete this Professor?", QMessageBox::Cancel | QMessageBox::Yes);

    if(reply == QMessageBox::Yes){
        for(auto i : database.Profsvector[std].getCourses()){
            i.remProfessor(database.Profsvector[std]);
            for(int j=0;j<database.Crsvector.size();j++){
                if(database.Crsvector[j].getCode()==i.getCode()){
                    for(int z=0;z<database.Crsvector[j].getProfessors().size();z++){
                        if(database.Profsvector[std].isEqual(database.Crsvector[j].getProfessors()[z])){
                        database.Crsvector[j].remProfessor(database.Crsvector[j].getProfessors()[z]);
                        break;
                        }
                    }
                    break;
                }
            }
        }
        database.Profsvector.erase(database.Profsvector.begin()+std);
        this->close();
    }

}

EditProfessor::~EditProfessor()
{
    delete ui;
}






