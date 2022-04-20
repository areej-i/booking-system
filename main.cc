#include<iostream>
#include <string.h>
#include "a1-global.cc"
#include "Student.h"
#include "Reservation.h"
#include "Room.h"
#include "Library.h"
#include "Date.h"
using namespace std;

int main() {

    //1a
    Date d1(2020,3,26,11,3);
    Date d2(2020,3,27,11,3);
    testDate(d1,d2,false);

    //1b
    Date d3(2020,3,26,20,3);
    Date d4(2020,3,26,11,3);
    testDate(d3,d4,false);

    //1c
    Date d5(2020,6,30,9,1);
    Date d6(2020,6,30,10,3);
    testDate(d5,d6,false);

    //1d
    Date d7(2020,3,26,15,2);
    Date d8(2020,3,26,16,1);
    testDate(d7,d8,true);

    //1e
    Date d9(2020,7,16,11,3);
    Date d10(2020,7,16,11,2);
    testDate(d9,d10,true);

    Library lib;
    populate(lib);
    testReservations(lib);
}
