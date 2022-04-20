#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student{

    public:
        //constructors
        Student();
        Student(string name, string number);
        Student(Student&);

        //setters
        void setName(string);
        void setNumber(string);

        //getters
        string getName();
        string getNumber();

        //other
        bool lessThan(Student& s);
        void print();
    
    private:
        //member variables
        string name;
        string number;
};
#endif