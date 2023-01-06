#ifndef DATABASE_H
#define DATABASE_H
#include "classes.h"
#include "qtconfigmacros.h"
#include <vector>

using namespace std;


class Database{

public:
    vector <Professor> Profsvector;
    vector <Course> Crsvector;
    vector <Student> stdsVector;

    Database(){

        Professor p1 = Professor("Ahmed","Emad",45 , "01002023932", "ahmedemad@gmail.com", "Prof. Dr.");
        Professor p2 = Professor("Khaled","Badr", 50, "0112498492", "khaledbadr@gmail.com", "Prof. Dr.");
        Professor p3 = Professor("Hazem","Zakaria", 26, "01248974398", "HZ11@gmail.com", "TA");
        Professor p4 = Professor("Sarah","Wael", 24, "01528397100", "sarahwael99@gmail.com", "TA");

        Profsvector = {p1,p2,p3,p4};

        Course c1 = Course("Physics", "PHY513", "3201");
        Course c2 = Course("Data Structure", "CMP045", "3001");
        Course c3 = Course("Math", "MTH115","17002");
        Course c4 = Course("Electronics", "ELC7899","1003");
        c1.setTime("8 AM - 10 AM");
        c2.setTime("10 AM - 12 PM");
        c3.setTime("12 PM - 2 PM");
        c4.setTime("4 PM - 6 PM");

        Crsvector = {c1,c2,c3,c4};

        Student s1 = Student("Hana","Hesham",20,"0104215345","hanahesham@gmail.com","Year 3");
        Student s2 = Student("Malak","Nasser",21,"01242533254","malak1@gmail.com","Year 2");
        Student s3 = Student("Omar","Tarek",22,"0114532245","omartarek7@gmail.com","Year 1");

        stdsVector = {s1,s2,s3};

    }

};

QT_BEGIN_NAMESPACE
class Database;
QT_END_NAMESPACE

#define MAGIC_NUM 42

extern Database database;

#endif // DATABASE_H
