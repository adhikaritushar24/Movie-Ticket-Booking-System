#include "BookingService.h"
#include <iostream>
using namespace std;

bool BookingService::checkAvailability(vector<ShowSeat>& seats, vector<string>& seatNumbers, vector<ShowSeat*>& resolvedSeats) {
    resolvedSeats.clear();

    for (int i = 0; i < seatNumbers.size(); i++) {
        bool seatFound = false;

        for (int j = 0; j < seats.size(); j++) {
            if (seats[j].getSeatNumber() == seatNumbers[i]) {
                seatFound = true;

                if (!seats[j].isAvailable()) {
                    cout << "Error: Seat " << seatNumbers[i] << " is already BOOKED." << endl;
                    resolvedSeats.clear();
                    return false;
                }

                resolvedSeats.push_back(&seats[j]);
                break;
            }
        }

        if (!seatFound) {
            cout << "Error: Seat " << seatNumbers[i] << " does not exist." << endl;
            resolvedSeats.clear();
            return false;
        }
    }

    return true;
}

Booking* BookingService::createBooking(Customer* customer, Show* show, vector<ShowSeat*>& selectedSeats) {
    Booking* booking = new Booking(customer, show);

    for (int i = 0; i < selectedSeats.size(); i++) {
        booking->addSeat(selectedSeats[i], selectedSeats[i]->getPrice());
        selectedSeats[i]->book();
    }

    return booking;
}

bool BookingService::confirmBooking(Booking* booking, Payment* payment) {
    if (payment->pay()) {
        booking->confirm();
        ticketPrinter.printTicket(*booking);
        return true;
    } else {
        booking->fail();
        releaseSeats(booking->getSeats());
        cout << "Payment failed. Booking " << booking->getBookingId() << " marked FAILED and seats released." << endl;
        return false;
    }
}

void BookingService::cancelBooking(Booking* booking) {
    releaseSeats(booking->getSeats());
    booking->cancel();
    cout << "Booking " << booking->getBookingId() << " cancelled. Seats released." << endl;
}

void BookingService::releaseSeats(vector<ShowSeat*>& seats) {
    for (int i = 0; i < seats.size(); i++) {
        seats[i]->release();
    }
}
