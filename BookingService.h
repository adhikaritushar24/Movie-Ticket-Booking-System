#ifndef BOOKINGSERVICE_H
#define BOOKINGSERVICE_H

#include <vector>
#include <string>
#include "ShowSeat.h"
#include "Booking.h"
#include "Payment.h"
#include "PriceCalculator.h"
#include "TicketPrinter.h"
using namespace std;

class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;

public:
    bool checkAvailability(vector<ShowSeat>& seats, vector<string>& seatNumbers, vector<ShowSeat*>& resolvedSeats);
    Booking* createBooking(Customer* customer, Show* show, vector<ShowSeat*>& selectedSeats);
    bool confirmBooking(Booking* booking, Payment* payment);
    void cancelBooking(Booking* booking);
    void releaseSeats(vector<ShowSeat*>& seats);
};

#endif
