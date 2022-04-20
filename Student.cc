#include "Student.h"

Student::Student(){
	setName("N/A");
    setNumber("0");
}

Student::Student(string name, string number){
    setName(name);
    setNumber(number);
}

void Student::setName(string n){ name = n;}
void Student::setNumber(string num){ number = num;}

string Student::getName(){ return name;}
string Student::getNumber(){ return number;}

bool Student::lessThan(Student& s){
    if(this->number.compare(s.number) > 0){
        return true;
    }
    return false;
}

void Student::print(){
    cout << "Student name: "<< getName() << "   Student Number: " << getNumber() << endl;
}