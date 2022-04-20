#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Date.h"

using namespace std;

class Reservation{

    public:
        //constructor
        Reservation(Student* s, Room* r, Date& date);

        //deconstructor
        ~Reservation();

        //getters
        Student* getStudent();
        Room* getRoom();
        Date* getDate();

        //other
        bool lessThan(Reservation& res);
        bool overlaps(string r, Date& d);
        void print();
    
    private:
        Student* student;
        Room* room;
        Date* date;
};
#endif