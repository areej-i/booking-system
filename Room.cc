#include "Room.h"

Room::Room(string name, int capacity, int computers, bool whiteboard){
    setName(name);
    setCapacity(capacity);
    setComputers(computers);
    setWhiteboard(whiteboard);
}

void Room::setName(string n){ name = n;}
void Room::setCapacity(int cap){ capacity = cap;}
void Room::setComputers(int c){ computers = c;}
void Room::setWhiteboard(bool w){ whiteboard = w;}

string Room::getName(){return name;}
int Room::getCapacity(){return capacity;}
int Room::getComputers(){return computers;}
bool Room::hasWhiteboard(){return whiteboard;}

bool Room::meetsCriteria(int capacity, int computers=0, bool whiteboard=false){
    if((this->capacity >= capacity)&&(this->computers >= computers)&&(this->whiteboard)){
        return true;
    }
    return false;
}

bool Room::lessThan(Room& r){
    if(this->name.compare(r.name) > 0){
        return true;
    }
    return false;
}

void Room::print(){
    cout << "Room name: "<< getName() << "   Capacity: " << getCapacity() << endl 
    << "Computers: " << getComputers() << "        Whiteboards: ";
    if(hasWhiteboard()){
        cout << "1 " << endl;
    }
    else{
        cout << "0 " << endl;
    }
}