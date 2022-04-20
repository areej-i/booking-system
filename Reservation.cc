#include "Reservation.h"

Reservation::Reservation(Student* student, Room* room, Date& date){
    this->student = student;
    this->room = room;
    this->date = &date;
}
Reservation::~Reservation(){
//delete 
}

Student* Reservation::getStudent(){ return student;}
Room* Reservation::getRoom(){ return room;}
Date* Reservation::getDate(){ return date;}

bool Reservation::lessThan(Reservation& res){
    if((this->date)->lessThan(*res.date)){
        return true;
    }
    return false;
}

bool Reservation::overlaps(string r, Date& d){
    //This function returns true if the r argument matches the name of the room member variable and 
    //this->date overlaps d, and false otherwise
    if (r == room->getName() && this->date->overlaps(d)){
        return true;
    }
    return false;
}

void Reservation::print(){
    cout << endl << " " << endl;
    student->print();
    room->print();
    (*date).print();
}