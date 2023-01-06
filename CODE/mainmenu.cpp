#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "editprofessor.h"
#include "editstudent.h"
#include "editcourse.h"
#include "createstudent.h"
#include "createprofessor.h"
#include "createcourse.h"
#include <QPixmap>
#include "Database.h"
#include <fstream>
#include <QMessageBox>

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    for(auto i:database.Crsvector){
            ui->comboBoxCourse->addItem(QString::fromStdString(i.getName()));
            x++;
        }
//    QPixmap pic("/Users/ahmedemadv/Desktop/Pics/add");
//    ui->label_add->setPixmap(pic);
//    QPixmap pic2("/Users/ahmedemadv/Desktop/Pics/edit");
//    ui->label_edit->setPixmap(pic2);
//    QPixmap pic3("/Users/ahmedemadv/Desktop/Pics/details.jpeg");
//    ui->label_det->setPixmap(pic3);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_1_clicked()
{
    int index = ui->comboBox->currentIndex();

    if(index == 0){
        CreateStudent createstu;
        createstu.setModal(true);
        createstu.exec();
    }

    if(index == 1){
        CreateProfessor createprof;
        createprof.setModal(true);
        createprof.exec();
    }

    if(index == 2){
        CreateCourse createcrs;
        createcrs.setModal(true);
        createcrs.exec();
    }
}


void MainMenu::on_pushButton_2_clicked()
{
    int index = ui->comboBox_details->currentIndex();

    if(index == 0){
        EditStudent edtstu;
        edtstu.setModal(true);
        edtstu.exec();
    }

    if(index == 1){
        EditProfessor edtprof;
        edtprof.setModal(true);
        edtprof.exec();
    }

    if(index == 2){
        EditCourse edtcrs;
        edtcrs.setModal(true);
        edtcrs.exec();
    }
}


void MainMenu::on_pushButtonExport_clicked()
{
    int z = ui->comboBoxCourse->currentIndex();
    ofstream myfile;
    myfile.open("Grades.csv");
    myfile<<"Class:"<<","<<database.Crsvector[z].getName();
    myfile<<endl<<"Professors: ";
    for(auto i:database.Crsvector[z].getProfessors()){
        myfile<<","<<i.getfirstName()+" "+i.getlastName();

    }
    myfile<<endl<<"Lecture Hall: "<<","<<database.Crsvector[z].getLecHall();
    myfile<<endl<<"Time"<<","<<database.Crsvector[z].getTime();
    myfile<<endl<<"Name"<<","<<"Grade";
    for(auto i : database.stdsVector){
        for(int j=0;j<i.getCourses().size();j++){
            if(i.getCourses()[j].getCode()==database.Crsvector[z].getCode()){
                myfile<<endl<<i.getfirstName()+" "+i.getlastName()<<","<<i.getScore(database.Crsvector[z].getCode());
                break;
            }
        }
    }
QMessageBox::information(this ,tr("The Title") , tr("CSV file is created successfully!"));

//    for(auto i:database.Crsvector[z].getStudents()){
//        myfile<<endl<<i.getfirstName()+" "+i.getlastName()<<","<<i.getScore(database.Crsvector[z].getCode());
//    }
}


void MainMenu::on_comboBoxCourse_highlighted(int index)
{
    for(int i = x;i<database.Crsvector.size();i++){
            ui->comboBoxCourse->addItem(QString::fromStdString(database.Crsvector[i].getName()));
            x++;
        }
}

