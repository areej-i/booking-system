#include "Library.h"
#include "Date.h"
#include "Reservation.h"
#include "Student.h"
#include "Room.h"

Library::Library()
{
    Room roo[MAX_SIZE] = {};
    stuArr = new Student *[MAX_SIZE];
    resArr = new Reservation *[MAX_SIZE];

    stuCount = 0;
    roomCount = 0;
    resCount = 0;
}

Library::~Library(){
    for(int j = 0; j < stuCount; j++){
        delete stuArr[j];
    }
    delete [] stuArr;
    
    for(int j = 0; j < roomCount; j++){
        delete rooArr[j];
    }

    for(int j = 0; j < resCount; j++){
        delete resArr[j];
    }
    delete [] resArr;

}

bool Library::addStudent(const string& name, const string& number){
    if (stuCount < MAX_SIZE)
    {
        Student* s = new Student(name,number);
        stuArr[stuCount] = s;
        stuCount++;
        return true;
    }
    return false;
}

bool Library::addRoom(string name, int capacity, int computers, bool whiteboard){
    if (roomCount < MAX_SIZE)
    {
        Room* r = new Room(name,capacity,computers,whiteboard);
        rooArr[roomCount] = r;
        roomCount++;
        return true;
    }
    return false;
}

bool Library::getStudent(const string& name, Student** student){
    for(int i = 0; i < stuCount; i++){
        if (stuArr[i]->getName() == name){
            *student = stuArr[i];
            return true;
        }
    }
    return false;
}

bool Library::getRoom(const string& roomName, Room** room){
    for(int i = 0; i < roomCount; i++){
        if (rooArr[i]->getName() == roomName){
            *room = rooArr[i];
            return true;
        }
    }
    return false;
}
/*This function just checks if room exits in the library and returns true if it does*/
bool Library::helper(const string& room){
    for (int j = 0; j < roomCount; j++)
    {
        if(rooArr[j]->getName() == room){
            return true;
        }
    }
    return false;
}

bool Library::isFree(const string& room, Date& d)
{
    if (helper(room))
    {
        for(int i = 0; i < resCount; i++)
        {
            if(resArr[i]->overlaps(room, d)){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Library::makeReservation(const string& studentN, const string& roomN, Date& d){
    if(!(isFree(roomN,d))){
        return false;
    }
    Student * su = new Student;
    Room * ru = new Room;
    
    if((getStudent(studentN,&su)) && (getRoom(roomN,&ru))){
        if(resCount < MAX_SIZE)
        {
            Reservation * reserve = new Reservation(su,ru,d);
            resArr[resCount] = reserve;
            resCount++;
    //         //delete reserve;
    //         //delete su;
    //         //delete ru;
            return true;
        }
    //     //delete su;
    //     //delete ru;
        return false;
    }
    //delete su;
    //delete ru;
    return false;
}

void Library::printReservations(){
    cout << endl << "Reservations:";
    for (int i = 0; i < resCount; i++){
        resArr[i]->print();
    }
}
