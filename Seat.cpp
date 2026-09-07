#include "Seat.h"
using namespace std;

Seat::Seat(string seatNumber, SeatType seatType) {
    this->seatNumber = seatNumber;
    this->seatType = seatType;
}

string Seat::getSeatNumber() { return seatNumber; }
SeatType Seat::getSeatType() { return seatType; }

int Seat::getPrice() {
    if (seatType == SeatType::SILVER)
        return 150;
    else if (seatType == SeatType::GOLD)
        return 250;
    else
        return 400;
}

string Seat::seatTypeToString(SeatType type) {
    if (type == SeatType::SILVER)
        return "SILVER";
    else if (type == SeatType::GOLD)
        return "GOLD";
    else
        return "PLATINUM";
}
