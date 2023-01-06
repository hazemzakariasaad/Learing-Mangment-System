#include "editstudent.h"
#include "ui_editstudent.h"
//#include "classes.h"
#include "Database.h"
#include "algorithm"
#include "QMessageBox"

// deleteeee men awel hena
//    Professor p1 = Professor("Khaeld","Badr",40,"0132342423","gf@vfds","TA");
//    Professor p = Professor();
//    Professor p2 = Professor("Hazem","Ba",42,"013243534","gdf@vfds","Pt");
//    Professor p3 = Professor("Ahmed","Bar",44,"01323443645","453@vfds","Prof");
//    Student s1 = Student("hana","hazem",20,"01145345","gtgetg@vfds","year3");
//    Student s2 = Student("Malak","Ahmed",21,"012425354","dadaag@vfds","year2");
//    Student s3 = Student("#omda","hazem",22,"01145345","ffsgtr@vfds","year 1");
//    Course c1 = Course("Phy","0211","02:30","3201");
//    Course c2 = Course("Cs","0111","02:00","3200");
//    Course c3 = Course("Bio","4566","12:30","3203");
//    vector<Professor> prfsVector = {p1,p2,p3};
//    vector<Student> stdsVector = {s1,s2,s3};
//    vector<Course> crsVector = {c1,c2,c3};
//le7ad hena
//int index = 0;
EditStudent::EditStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditStudent)
{
    ui->setupUi(this);
    for(auto i:database.stdsVector){
        ui->comboBoxStudent->addItem(QString::fromStdString( i.getfirstName()+" " + i.getlastName()));
    }

    displayStudent(0);
}


EditStudent::~EditStudent()
{
    delete ui;
}

void EditStudent::on_comboBoxStudent_currentIndexChanged(int index)
{
    displayStudent(index);
}

void EditStudent::displayStudent(int i){
    ui->lineEditFirstName->setText(QString::fromStdString(database.stdsVector[i].getfirstName()));
    ui->lineEditLastName->setText(QString::fromStdString(database.stdsVector[i].getlastName()));
    ui->lineEditAge->setText(QString::number(database.stdsVector[i].getAge()));
    ui->lineEditMobile->setText(QString::fromStdString(database.stdsVector[i].getMobile()));
    ui->lineEditEmail->setText(QString::fromStdString(database.stdsVector[i].getEmail()));
    ui->comboBoxCurrentCourses->clear();
    ui->lineEditScore->clear();
    ui->comboBoxAddCourses->clear();
    ui->comboBoxRemoveCourses->clear();
    ui->comboBoxAddCourses->addItem("None");
    ui->comboBoxRemoveCourses->addItem("None");
    for(int j=0;j<database.stdsVector[i].getCourses().size();j++){
        ui->comboBoxCurrentCourses->addItem(QString::fromStdString(database.stdsVector[i].getCourses()[j].getName()));
        ui->comboBoxRemoveCourses->addItem(QString::fromStdString(database.stdsVector[i].getCourses()[j].getName()));
    }
    //hagarab el add
    for(int j=0;j<database.Crsvector.size();j++){
        bool flag = 1;
        for(int z=0;z<database.stdsVector[i].getCourses().size();z++){
            if(database.stdsVector[i].getCourses()[z].getCode()==database.Crsvector[j].getCode()){
                flag = 0;
                break;
            }
        }
        if(flag){
            ui->comboBoxAddCourses->addItem(QString::fromStdString(database.Crsvector[j].getName()));
        }
    }

    //matgarabsh tany b2a
    ui->lineEditGrade->setText(QString::fromStdString(database.stdsVector[i].getGrade()));
}

void EditStudent::displayScore(int j,int curstd){
    if(!(database.stdsVector[curstd].isScore(database.stdsVector[curstd].getCourses()[j].getCode()))){
        ui->lineEditScore->setText("No score added yet");
        return;
    }else {
    ui->lineEditScore->setText(QString::number(database.stdsVector[curstd].getScore(database.stdsVector[curstd].getCourses()[j].getCode())));
    }
}


void EditStudent::on_comboBoxCurrentCourses_currentIndexChanged(int index)
{
    ui->lineEditScore->clear();
    //displayScore(index,ui->comboBoxStudent->currentIndex());

    //            ui->comboBoxCurrentCourses->currentIndex()
//            ui->comboBoxStudent->currentIndex()
}


void EditStudent::on_pushButton_clicked()
{
    displayScore(ui->comboBoxCurrentCourses->currentIndex(),ui->comboBoxStudent->currentIndex());
}


void EditStudent::on_pushButtonSave_clicked()
{
    if(isNum(ui->lineEditFirstName->text())||isNum(ui->lineEditLastName->text())){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again");
    }else if(isString(ui->lineEditAge->text())||isString(ui->lineEditMobile->text())){
        QMessageBox::warning(this,"ERROR","Invalid data type, try again");
    }
    else if(ui->lineEditAge->text().toInt()<15)    // kol validation
            QMessageBox::warning(this,"ERROR","Wrong age , try again");
    else if(ui->lineEditAge->text().isEmpty()||ui->lineEditFirstName->text().isEmpty()||ui->lineEditLastName->text().isEmpty()||ui->lineEditEmail->text().isEmpty()||ui->lineEditMobile->text().isEmpty()||ui->lineEditGrade->text().isEmpty()){
          QMessageBox::warning(this,"ERROR","Empty field , try again");
    }
   else{

    int std = ui->comboBoxStudent->currentIndex();
    int crs = ui->comboBoxRemoveCourses->currentIndex()-1;
    int acrs = ui->comboBoxAddCourses->currentIndex();
    database.stdsVector[std].setfirstName(ui->lineEditFirstName->text().toStdString());
    database.stdsVector[std].setlastName(ui->lineEditLastName->text().toStdString());
    database.stdsVector[std].setAge(ui->lineEditAge->text().toInt());
    database.stdsVector[std].setMobile(ui->lineEditMobile->text().toStdString());
    database.stdsVector[std].setEmail(ui->lineEditEmail->text().toStdString());
    //deh el score
    if(database.stdsVector[std].isScore(database.stdsVector[std].getCourses()[ui->comboBoxCurrentCourses->currentIndex()].getCode())){
        database.stdsVector[std].changeScore(database.stdsVector[std].getCourses()[ui->comboBoxCurrentCourses->currentIndex()].getCode(),ui->lineEditScore->text().toInt());
    }else{
        database.stdsVector[std].setScore(database.stdsVector[std].getCourses()[ui->comboBoxCurrentCourses->currentIndex()].getCode(),ui->lineEditScore->text().toInt());
    }
    //kda 5alas el score
    database.stdsVector[std].setGrade(ui->lineEditGrade->text().toStdString());
    //deh el add course
    if(acrs!=0){
        for(int f=0;f<database.Crsvector.size();f++){
            if(ui->comboBoxAddCourses->itemText(acrs).toStdString()==database.Crsvector[f].getName()){
                database.Crsvector[f].addStudent(database.stdsVector[std]);
                break;
            }
        }

    }
    //kda el add course 5elset we 5alaset 3alaya


    //deh el remove course
    if(crs!=-1)
        database.stdsVector[std].getCourses()[crs].remStudent(database.stdsVector[std]);
    //kda 5alas el remove course
    close();
    }
}


void EditStudent::on_pushButtonMainMenu_clicked()
{
    close();
}


void EditStudent::on_pushButtonRemove_clicked()
{
    int std = ui->comboBoxStudent->currentIndex();
    for(auto i : database.stdsVector[std].getCourses()){
        i.remStudent(database.stdsVector[std]);
        for(int j=0;j<database.Crsvector.size();j++){
            if(database.Crsvector[j].getCode()==i.getCode()){
                for(int z=0;z<database.Crsvector[j].getStudents().size();z++){
                    if(database.stdsVector[std].isEqual(database.Crsvector[j].getStudents()[z])){
                    database.Crsvector[j].remStudent(database.Crsvector[j].getStudents()[z]);
                    break;
                    }
                }
                break;
            }
        }
    }
    database.stdsVector.erase(database.stdsVector.begin()+std);
    close();
}

bool EditStudent::isNum(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (isdigit(i)){
             //QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}

bool EditStudent::isString(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (!isdigit(i)){
//              QMessageBox::warning(this,"ERROR","enter words only, try again");
              return 1;
           }
        }
    return 0;
}


