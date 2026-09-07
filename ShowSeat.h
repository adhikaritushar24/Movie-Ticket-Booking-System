#ifndef SHOWSEAT_H
#define SHOWSEAT_H

#include "Seat.h"
using namespace std;

enum class SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat seat;
    SeatStatus status;

public:
    ShowSeat(Seat seat);

    bool isAvailable();
    void book();
    void release();

    string getSeatNumber();
    SeatType getSeatType();
    int getPrice();
    SeatStatus getStatus();

    void showSeat();
};

#endif
