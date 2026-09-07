#include "Booking.h"
using namespace std;

int Booking::nextBookingId = 1000;

Booking::Booking(Customer* customer, Show* show) {
    bookingId = ++nextBookingId;
    this->customer = customer;
    this->show = show;
    totalAmount = 0;
    status = BookingStatus::PENDING;
}

void Booking::addSeat(ShowSeat* seat, int price) {
    selectedSeats.push_back(seat);
    totalAmount += price;
}

void Booking::confirm() { status = BookingStatus::CONFIRMED; }
void Booking::fail() { status = BookingStatus::FAILED; }
void Booking::cancel() { status = BookingStatus::CANCELLED; }

int Booking::getBookingId() { return bookingId; }
Customer* Booking::getCustomer() { return customer; }
Show* Booking::getShow() { return show; }
vector<ShowSeat*>& Booking::getSeats() { return selectedSeats; }
double Booking::getTotalAmount() { return totalAmount; }
BookingStatus Booking::getStatus() { return status; }

string Booking::getStatusString() {
    if (status == BookingStatus::PENDING)
        return "PENDING";
    else if (status == BookingStatus::CONFIRMED)
        return "CONFIRMED";
    else if (status == BookingStatus::FAILED)
        return "FAILED";
    else
        return "CANCELLED";
}
