#ifndef CLASSES_H
#define CLASSES_H
class Person;
class Course;
class Professor;
class Student;

#include <vector>
#include <iostream>
#include <map>
//#include <bits/stdc++.h>
using namespace std;

//vector<Student> StudsVector;
//vector <Professor> ProfsVector;
//vector <Course> CrsVector;








class Person {
    private:
        string firstName;
        string lastName;
        int age;
        string mobile;
        string email;
        vector<Course> courses;
        friend class Course;
        void AddCourse(Course &c);        //U cant use it,,,,use the automated function in class course instead :: course.addProf/stud(prof/stud)
        void RemoveCourse(Course &c);     //U cant use it,,,,use the automated function in class course instead :: course.remProf/stud(prof/stud)

    public:

    Person();

    Person(string f, string l, int a, string m, string e);

    void setfirstName(string s);

    string getfirstName();

    void setlastName(string s);

    string getlastName();

    void setAge(int age);

    int getAge();

    void setMobile(string mob);

    string getMobile();

    void setEmail(string email);

    string getEmail();

    bool isEqual(Person tt);

    vector<Course> getCourses();

    ~Person();

};

class Professor : public Person {
    private:
        string title;

    public:
        Professor();
        Professor(string f, string l, int a, string m, string e,string t);
        void setTitle(string t);
        string getTitle();
        ~Professor();
};

class Student : public Person {
    private:
        string grade;
        map<string,int> scores;


    public:
        Student();
        Student(string f, string l, int a, string m, string e,string g);
        void setGrade(string g);
        void setScore(string c,int s);
        int getScore(string c);
        bool isScore(string c);
        void changeScore(string c,int news);
        string getGrade();
        ~Student();

};


class Course{
private:
    string name;
    string code;
    string time;
    string lecHall;
    vector<Professor> profs;
    vector<Student> students;
public:
    Course();
    Course(string name, string code, string lecHall);
    void setName(string n);
    void setCode(string c);
    void setTime(string t);
    void setLecHall(string l);
    void addProfessor(Professor &p);            //automated function
    void addStudent(Student &s);                //automated function
    string getName();
    string getCode();
    string getTime();
    string getLecHall();
    vector <Professor> getProfessors();
    vector <Student> getStudents();
    void remProfessor(Professor &p);           //automated function
    void remStudent(Student &s);                //automated function
    ~Course();
};

#endif


