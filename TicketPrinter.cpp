#include "TicketPrinter.h"
#include <iostream>
#include <vector>
using namespace std;

void TicketPrinter::printTicket(Booking& booking) {
    cout << endl << "===================================" << endl;
    cout << "            MOVIE TICKET           " << endl;
    cout << "===================================" << endl;
    cout << "Booking ID : " << booking.getBookingId() << endl;
    cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << endl;
    cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << endl;
    cout << "Show Time  : " << booking.getShow()->getStartTime() << endl;

    cout << "Seats      : ";
    vector<ShowSeat*> seats = booking.getSeats();
    for (int i = 0; i < seats.size(); i++) {
        cout << seats[i]->getSeatNumber() << " ";
    }
    cout << endl;

    cout << "Amount     : Rs." << booking.getTotalAmount() << endl;
    cout << "Status     : " << booking.getStatusString() << endl;
    cout << "===================================" << endl;
}
