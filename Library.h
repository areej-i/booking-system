#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Reservation.h"
#include "Date.h"

using namespace std;

#define MAX_SIZE 16
class Library {

    public:
        //constructor
        Library();

        //deconstructor
        ~Library();

        
        bool addStudent(const string& name, const string& number);
        bool addRoom(string name, int capacity=1, int computers=0, bool whiteboard=false);
        bool getStudent(const string& name, Student** student);
        bool getRoom(const string& roomName, Room** room);
        bool isFree(const string& room, Date&);
        bool makeReservation(const string& student, const string& room, Date&);
        void printReservations();
        bool helper(const string& roomName);
    
    private:
        Student** stuArr;
        Reservation** resArr;
        Room* rooArr[MAX_SIZE];
        int stuCount;
        int roomCount;
        int resCount;
};
#endif