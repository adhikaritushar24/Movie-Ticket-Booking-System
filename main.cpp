#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#include "Movie.h"
#include "Seat.h"
#include "Screen.h"
#include "Cinema.h"
#include "Show.h"
#include "ShowSeat.h"
#include "Customer.h"
#include "Booking.h"
#include "Payment.h"
#include "PaymentTypes.h"
#include "PriceCalculator.h"
#include "TicketPrinter.h"
#include "BookingService.h"

int readInt()
{
    int value;
    while (!(cin >> value))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return value;
}

vector<string> splitSeatNumbers(string line)
{
    vector<string> result;
    stringstream ss(line);
    string token;
    while (ss >> token)
    {
        result.push_back(token);
    }
    return result;
}

int main()
{
    Movie movie1("Fight-Club", "English", 180);
    Movie movie2("Vivah", "Hindi", 182);

    Screen screen1(1);
    screen1.addSeat(Seat("A1", SeatType::SILVER));
    screen1.addSeat(Seat("A2", SeatType::SILVER));
    screen1.addSeat(Seat("B1", SeatType::GOLD));
    screen1.addSeat(Seat("B2", SeatType::GOLD));
    screen1.addSeat(Seat("C1", SeatType::PLATINUM));
    screen1.addSeat(Seat("C2", SeatType::PLATINUM));

    Cinema cinema("PVR Cinemas");
    cinema.addScreen(screen1);

    vector<Movie *> movies;
    movies.push_back(&movie1);
    movies.push_back(&movie2);

    Show show1(1, &movie1, &cinema.getScreens()[0], "7:00 PM");
    Show show2(2, &movie2, &cinema.getScreens()[0], "10:00 PM");

    vector<Show *> shows;
    shows.push_back(&show1);
    shows.push_back(&show2);

    vector<vector<ShowSeat>> showSeatsPerShow;
    for (int i = 0; i < shows.size(); i++)
    {
        vector<ShowSeat> ss;
        vector<Seat> &physicalSeats = cinema.getScreens()[0].getSeats();
        for (int j = 0; j < physicalSeats.size(); j++)
        {
            ss.push_back(ShowSeat(physicalSeats[j]));
        }
        showSeatsPerShow.push_back(ss);
    }

    Customer customer(1, "Tushar Adhikari", "9876543210");
    BookingService bookingService;
    vector<Booking *> allBookings;

    Show *selectedShow = NULL;
    vector<ShowSeat> *selectedShowSeats = NULL;

    // this lines,i am adding for attractive look these are not ai generated.
    cout << "=====================================" << endl;
    cout << "   MOVIE TICKET BOOKING SYSTEM" << endl;
    cout << "=====================================" << endl;

    while (true)
    {
        cout << endl
             << "----------- MAIN MENU -----------" << endl;
        cout << "1. List Movies" << endl;
        cout << "2. List Shows" << endl;
        cout << "3. Select a Show" << endl;
        cout << "4. Show Seat Availability" << endl;
        cout << "5. Book Seats" << endl;
        cout << "6. Cancel a Booking" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        int choice = readInt();

        if (choice == 0)
        {
            cout << "Thank you for using the Movie Ticket Booking System!" << endl;
            break;
        }
        else if (choice == 1)
        {
            cout << endl
                 << "-- Movies Now Playing --" << endl;
            for (int i = 0; i < movies.size(); i++)
            {
                cout << i + 1 << ". ";
                movies[i]->displayMovie();
                cout << "-----" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << endl
                 << "-- Available Shows --" << endl;
            for (int i = 0; i < shows.size(); i++)
            {
                shows[i]->displayShow();
            }
        }
        else if (choice == 3)
        {
            cout << "Enter Show ID to select (1 or 2): ";
            int showId = readInt();
            bool found = false;

            for (int i = 0; i < shows.size(); i++)
            {
                if (shows[i]->getShowId() == showId)
                {
                    selectedShow = shows[i];
                    selectedShowSeats = &showSeatsPerShow[i];
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "Selected: ";
                selectedShow->displayShow();
            }
            else
            {
                cout << "Error: No such show ID." << endl;
            }
        }
        else if (choice == 4)
        {
            if (selectedShow == NULL)
            {
                cout << "Error: Please select a show first (option 3)." << endl;
                continue;
            }
            cout << endl
                 << "-- Seat Layout for Show #" << selectedShow->getShowId() << " --" << endl;
            for (int i = 0; i < selectedShowSeats->size(); i++)
            {
                (*selectedShowSeats)[i].showSeat();
            }
        }
        else if (choice == 5)
        {
            if (selectedShow == NULL)
            {
                cout << "Error: Please select a show first (option 3)." << endl;
                continue;
            }

            cin.ignore(1000, '\n');
            cout << "Enter seat numbers to book, space separated (e.g. A1 B2): ";
            string line;
            getline(cin, line);
            vector<string> seatNumbers = splitSeatNumbers(line);

            if (seatNumbers.size() == 0)
            {
                cout << "Error: No seats entered." << endl;
                continue;
            }

            vector<ShowSeat *> resolvedSeats;
            bool ok = bookingService.checkAvailability(*selectedShowSeats, seatNumbers, resolvedSeats);
            if (!ok)
            {
                cout << "Booking rejected. No seats were changed." << endl;
                continue;
            }

            Booking *booking = bookingService.createBooking(&customer, selectedShow, resolvedSeats);

            PriceCalculator calc;
            double total = calc.calculatePrice(resolvedSeats);
            cout << "Total amount for " << resolvedSeats.size() << " seat(s): Rs." << total << endl;

            cout << "Select payment method:" << endl;
            cout << "1. UPI" << endl;
            cout << "2. Card" << endl;
            cout << "3. Cash" << endl;
            cout << "Enter choice: ";
            int payChoice = readInt();

            Payment *payment = NULL;
            if (payChoice == 1)
                payment = new UpiPayment(total);
            else if (payChoice == 2)
                payment = new CardPayment(total);
            else if (payChoice == 3)
                payment = new CashPayment(total);
            else
            {
                cout << "Error: Invalid payment method. Booking cancelled." << endl;
                bookingService.releaseSeats(resolvedSeats);
                delete booking;
                continue;
            }

            bool success = bookingService.confirmBooking(booking, payment);
            if (success)
                allBookings.push_back(booking);
            else
                delete booking;

            delete payment;
        }
        else if (choice == 6)
        {
            if (allBookings.size() == 0)
            {
                cout << "No bookings to cancel." << endl;
                continue;
            }

            cout << "Your confirmed bookings:" << endl;
            for (int i = 0; i < allBookings.size(); i++)
            {
                if (allBookings[i]->getStatus() == BookingStatus::CONFIRMED)
                {
                    cout << "  Booking ID: " << allBookings[i]->getBookingId() << " | Amount: Rs." << allBookings[i]->getTotalAmount() << endl;
                }
            }

            cout << "Enter Booking ID to cancel: ";
            int id = readInt();
            bool found = false;

            for (int i = 0; i < allBookings.size(); i++)
            {
                if (allBookings[i]->getBookingId() == id && allBookings[i]->getStatus() == BookingStatus::CONFIRMED)
                {
                    bookingService.cancelBooking(allBookings[i]);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Error: No confirmed booking with that ID." << endl;
            }
        }
        else
        {
            cout << "Error: Invalid menu choice. Please try again." << endl;
        }
    }

    for (int i = 0; i < allBookings.size(); i++)
    {
        delete allBookings[i];
    }

    return 0;
}
