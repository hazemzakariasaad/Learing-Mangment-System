#include "createcourse.h"
#include "ui_createcourse.h"
//#include "QString"
//#include"classes.h"  // azon msh mafrod ashelha
#include <string>
#include <vector>
#include <QMessageBox>
#include"Database.h"

using namespace std;

CreateCourse::CreateCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCourse)
{
    ui->setupUi(this);

    for(auto c : database.Profsvector)
    {
       // ui->comboBox_prof_4->addItems(QString::fromStdString(c.getfirstName()));
        ui->comboBox_prof_4->addItem(QString::fromStdString(c.getfirstName()+" "+c.getlastName()));
    }


    for (auto c : database.stdsVector)
    {
        ui->comboBox_stud_4->addItem(QString::fromStdString(c.getfirstName()+" "+c.getlastName()));
    }
}

//vector<string> v1 = {"hello","hello2"};

//    ui->comboBox_stud_4->addItem("hana");
//    ui->comboBox_stud_4->addItem(QString::fromStdString(v1[0]));
//}

CreateCourse::~CreateCourse()
{
    delete ui;
}



void CreateCourse::on_pushButton_create_clicked()
{
    if(isNum(ui->lineEdit_name_5->text())){
        QMessageBox::warning(this,"ERROR","Wrong name, try again");
    }    else if(ui->lineEdit_name_5->text().isEmpty()||ui->lineEdit_code_4->text().isEmpty()||ui->lineEdit_lecture_5->text().isEmpty()){
        QMessageBox::warning(this,"ERROR","Empty field, try again");
    }
    else{

    int chosenprof = ui->comboBox_prof_4->currentIndex();
    int chosenstd = ui->comboBox_stud_4->currentIndex();
    string name = ui->lineEdit_name_5->text().toStdString();
    string code = ui->lineEdit_code_4->text().toStdString();
    string lecture = ui->lineEdit_lecture_5->text().toStdString();
    string time = ui->comboBox_times->itemText(ui->comboBox_times->currentIndex()).toStdString();

    int flag =1;
    for(int i=0;i<database.Crsvector.size();i++){
        if(database.Crsvector[i].getLecHall() == lecture && database.Crsvector[i].getTime() == time){
            flag = 0;
            break;
        }
//        else if (database.Crsvector[i].)
    }

    if(flag){
    Course obj2;
    obj2.setName(name);
    obj2.setCode(code);
    obj2.setLecHall(lecture);
    obj2.setTime(time);
    obj2.addProfessor(database.Profsvector[chosenprof]);
    obj2.addStudent(database.stdsVector[chosenstd]);
    database.Crsvector.push_back(obj2);
    QMessageBox::information(this ,tr("The Title") , tr("Course is created successfully!"));
    this->close();
    }
    else{
    QMessageBox::warning(this ,tr("Caution") , tr("Sorry, lecture hall or time chosen is taken by another course! "));
         }
    //QString code = ui->lineEdit_code->text();
    //std::string input = ui->lineEdit_lecture->text().toStdString();

    //Course obj1(name ,code ,time , lecture);

    this->close();
    }
}


bool CreateCourse::isNum(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (isdigit(i)){
              return 1;
           }
        }
    return 0;
}

bool CreateCourse::isString(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (!isdigit(i)){
              return 1;
           }
        }
    return 0;
}

