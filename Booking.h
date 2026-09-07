#ifndef BOOKING_H
#define BOOKING_H

#include <vector>
#include <string>
#include "Customer.h"
#include "Show.h"
#include "ShowSeat.h"
using namespace std;

enum class BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };

class Booking {
private:
    static int nextBookingId;
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> selectedSeats;
    double totalAmount;
    BookingStatus status;

public:
    Booking(Customer* customer, Show* show);

    void addSeat(ShowSeat* seat, int price);

    void confirm();
    void fail();
    void cancel();

    int getBookingId();
    Customer* getCustomer();
    Show* getShow();
    vector<ShowSeat*>& getSeats();
    double getTotalAmount();
    BookingStatus getStatus();
    string getStatusString();
};

#endif
