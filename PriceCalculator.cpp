#include "PriceCalculator.h"
using namespace std;

double PriceCalculator::calculatePrice(SeatType type) {
    if (type == SeatType::SILVER)
        return 150;
    else if (type == SeatType::GOLD)
        return 250;
    else
        return 400;
}

double PriceCalculator::calculatePrice(vector<ShowSeat*>& seats) {
    double total = 0;
    for (int i = 0; i < seats.size(); i++) {
        total += seats[i]->getPrice();
    }
    return total;
}
