#include "Screen.h"
#include <iostream>
using namespace std;

Screen::Screen(int screenNumber) {
    this->screenNumber = screenNumber;
}

void Screen::addSeat(Seat seat) {
    seats.push_back(seat);
}

vector<Seat>& Screen::getSeats() {
    return seats;
}

int Screen::getScreenNumber() {
    return screenNumber;
}

void Screen::displaySeats() {
    cout << "Screen " << screenNumber << " Seats:" << endl;
    for (int i = 0; i < seats.size(); i++) {
        cout << "  " << seats[i].getSeatNumber() << " (" << Seat::seatTypeToString(seats[i].getSeatType()) << ", Rs." << seats[i].getPrice() << ")" << endl;
    }
}
