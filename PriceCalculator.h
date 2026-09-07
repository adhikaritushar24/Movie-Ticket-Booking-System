#ifndef PRICECALCULATOR_H
#define PRICECALCULATOR_H

#include <vector>
#include "ShowSeat.h"
#include "Seat.h"
using namespace std;

class PriceCalculator {
public:
    double calculatePrice(SeatType type);
    double calculatePrice(vector<ShowSeat*>& seats);
};

#endif
