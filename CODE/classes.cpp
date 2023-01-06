#include "classes.h"
#include <iostream>
#include <vector>
using namespace std;


Person::Person(){
    //cout<<"Empty constructor called!";
}

Person::Person(string f, string l, int a, string m, string e){
    firstName = f;
    lastName = l;
    age = a;
    mobile = m;
    email = e;
}

void Person::setfirstName(string s){
    firstName = s;
}

string Person::getfirstName(){
    return firstName;
}

void Person::setlastName(string s){
    lastName = s;
}

string Person::getlastName(){
    return lastName;
}


void Person::setAge(int age){
    this->age = age;
}

int Person::getAge(){
    return age;
}

void Person::setMobile(string s){
    mobile = s;
}

string Person::getMobile(){
    return mobile;
}

void Person::setEmail(string email){
    this->email = email;
}

string Person::getEmail(){
    return email;
}

bool Person::isEqual(Person tt){
    if(this->firstName==tt.firstName && this->lastName == tt.lastName && this->mobile == tt.mobile)
        return 1;
    else
        return 0;
}

void Person::AddCourse(Course &c){
    courses.push_back(c);
}

void Person::RemoveCourse(Course &c){
    // for(auto i:courses){
    //     if(i.getCode()==c.getCode()){
    //         courses.erase(i);
    //     }

    // }

    for(int i=0;i<courses.size();i++){
        if(courses[i].getCode()==c.getCode()){
            courses.erase(courses.begin()+i);
            break;
        }

    }
    //courses.erase(courses.begin(),courses.end(),c);
}

vector<Course> Person :: getCourses(){
    return courses;
}

Person::~Person(){

}










Professor::Professor(){
    //cout<<"reger";
}

Professor::Professor(string f, string l, int a, string m, string e,string t) : Person( f,  l, a, m, e){
    title = t;
}

void Professor::setTitle(string t){
    title = t;
}

string Professor::getTitle(){
    return title;
}


Professor::~Professor(){
    //cout<<"Grt";
}










Student::Student(){

}

Student::Student(string f, string l, int a, string m, string e,string g) : Person( f,  l, a, m, e){
    grade = g;
}

void Student::setGrade(string g){
    grade = g;
}

string Student::getGrade(){
    return grade;
}

void Student::setScore(string c,int s){
    scores.insert({c,s});
}

int Student::getScore(string c){
    return scores[c];
}

bool Student::isScore(string c){
    if(scores.find(c)==scores.end())
        return 0;
    else
        return 1;
}

void Student::changeScore(string c,int news){
    scores[c]= news;
}

Student::~Student(){

}








Course :: Course (){
    name = "Undefined";
    code =  "Undefined";
    time = "Undefined";
    lecHall = "Undefined";
}

//construstor with set values
Course :: Course(string name, string code, string lecHall){
    this->name = name;
    this->code = code;
    this->lecHall = lecHall;
}
void Course::setName(string n) {
    name=n;
}
void Course::setCode(string c) {
    code=c;
}
void Course::setLecHall(string l) {
    lecHall=l;
}
void Course::setTime(string t) {
    time=t;
}
void Course::addProfessor(Professor &p) {
    profs.push_back(p);
    p.AddCourse(*this);
}
void Course::addStudent(Student &s) {
    students.push_back(s);
    s.AddCourse(*this);
}

//Getters
string Course :: getName(){
    return name;
}

string Course :: getCode(){
    return code;
}

string Course :: getTime(){
    return time;
}

string Course :: getLecHall(){
    return lecHall;
}

vector <Professor> Course :: getProfessors(){
    return profs;
}

vector <Student> Course :: getStudents(){
    return students;
}

void Course:: remProfessor(Professor &p){
     for(int i=0;i<profs.size();i++){
        if(profs[i].isEqual(p)){
            profs.erase(profs.begin()+i);
            break;
        }

    }
    p.RemoveCourse(*this);
}
void Course:: remStudent(Student &s){
     for(int i=0;i<students.size();i++){
        if(students[i].isEqual(s)){
            students.erase(students.begin()+i);
            break;
        }

    }
    s.RemoveCourse(*this);
}

Course::~Course(){

}
