#include "ShowSeat.h"
#include <iostream>
using namespace std;

ShowSeat::ShowSeat(Seat seat) : seat(seat) {
    status = SeatStatus::AVAILABLE;
}

bool ShowSeat::isAvailable() {
    return status == SeatStatus::AVAILABLE;
}

void ShowSeat::book() {
    status = SeatStatus::BOOKED;
}

void ShowSeat::release() {
    status = SeatStatus::AVAILABLE;
}

string ShowSeat::getSeatNumber() { return seat.getSeatNumber(); }
SeatType ShowSeat::getSeatType() { return seat.getSeatType(); }
int ShowSeat::getPrice() { return seat.getPrice(); }
SeatStatus ShowSeat::getStatus() { return status; }

void ShowSeat::showSeat() {
    cout << "  " << seat.getSeatNumber() << " [" << Seat::seatTypeToString(seat.getSeatType()) << "] Rs." << seat.getPrice() << " - ";
    if (isAvailable())
        cout << "AVAILABLE" << endl;
    else
        cout << "BOOKED" << endl;
}
