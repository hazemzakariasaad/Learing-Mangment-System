#include "admin.h"
#include "Database.h"

#include <QApplication>

Database database;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //delete men awel hena tany
    database.Crsvector[0].addStudent(database.stdsVector[0]);
    database.Crsvector[1].addStudent(database.stdsVector[0]);
    database.Crsvector[2].addStudent(database.stdsVector[0]);
    database.Crsvector[0].addStudent(database.stdsVector[2]);
    database.Crsvector[1].addStudent(database.stdsVector[1]);
    database.Crsvector[2].addStudent(database.stdsVector[2]);
    database.stdsVector[0].setScore(database.Crsvector[0].getCode(),50);
    database.stdsVector[0].setScore(database.Crsvector[1].getCode(),70);
    database.stdsVector[0].setScore(database.Crsvector[2].getCode(),80);
    database.stdsVector[1].setScore(database.Crsvector[1].getCode(),19);
    database.stdsVector[2].setScore(database.Crsvector[2].getCode(),8);
    //le7ad hena tany
    Admin w;
    w.show();
    return a.exec();
}
