#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room{

    public:
        //constructers
        Room(string name="n/a", int capacity=1, int computers=0, bool whiteboard=false);
        Room(Room&);

        //setters
        void setName(string);
        void setCapacity(int);
        void setComputers(int);
        void setWhiteboard(bool);

        //getters
        string getName();
        int getCapacity();
        int getComputers();
        bool hasWhiteboard();

        //other
        bool meetsCriteria(int capacity, int computers, bool whiteboard);
        bool lessThan(Room& r);
        void print();
    
    private:
        //member variables
        string name;
        int capacity;
        int computers;
        bool whiteboard;
};
#endif