#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
private:
    string seatNumber;
    SeatType seatType;

public:
    Seat(string seatNumber, SeatType seatType);

    string getSeatNumber();
    SeatType getSeatType();
    int getPrice();

    static string seatTypeToString(SeatType type);
};

#endif
