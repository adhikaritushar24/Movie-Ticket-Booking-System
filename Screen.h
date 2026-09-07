#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "Seat.h"
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber);

    void addSeat(Seat seat);
    vector<Seat>& getSeats();
    int getScreenNumber();

    void displaySeats();
};

#endif
