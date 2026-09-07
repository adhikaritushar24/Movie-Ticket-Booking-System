# Movie-Ticket-Booking-System
Movie Ticket Booking System - C++
A simple and clean C++ implementation of a Movie Ticket Booking System using OOP principles. This project follows SOLID principles with proper class segregation.

📁 Project Structure
/headers
  ├── Seat.h              # Seat with SeatType (SILVER, GOLD, PLATINUM)
  ├── Screen.h            # Screen containing vector<Seat>
  ├── Movie.h             # Movie details
  ├── Show.h              # Show with Movie* and Screen*
  ├── ShowSeat.h          # Show-specific seat with SeatStatus
  ├── Customer.h          # Customer info
  ├── Booking.h           # Booking with Customer*, Show*, vector<ShowSeat*>
  ├── Payment.h           # Abstract Payment class
  ├── PaymentTypes.h      # UpiPayment, CardPayment, CashPayment
  ├── PriceCalculator.h   # Utility to calculate price
  └── TicketPrinter.h     # Utility to print ticket
/src
  ├── *.cpp               # Implementations
  └── main.cpp
🧱 Class Diagram
This diagram is 100% matched with your codebase headers.

Image not available

Key Relationships:
Composition: Screen ◆-- Seat (Screen owns Seats by value - vector<Seat>)
Aggregation: Show ◇-- Movie* , Screen* (Show has pointers)
Composition/Aggregation: ShowSeat -- Seat (ShowSeat contains Seat by value)
Aggregation: Booking ◇-- Customer*, Show*, ShowSeat* (Booking holds pointers)
Inheritance: Payment <|-- UpiPayment, CardPayment, CashPayment
Dependency: PriceCalculator ..> ShowSeat, SeatType and TicketPrinter ..> Booking
Enums:
cpp
enum class SeatType { SILVER, GOLD, PLATINUM };
enum class SeatStatus { AVAILABLE, BOOKED };
enum class BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };
🔄 Sequence Diagram - Book Ticket Flow
Complete booking flow from search to ticket print, including failure cases.

Image not available

Flow Description:
searchMovies() - User searches movies -> BookingService -> Cinema: getMovies()
selectMovie(movieId) -> getShows(movieId)
selectShow(showId) -> Show: getShow(), getScreen(), displaySeats()
selectSeats(seatNumbers) -> ShowSeat: isAvailable() -> checks SeatStatus, getPrice()
createBooking(customer, show) -> Booking: new Booking(customer, show)
Loop: addSeat(ShowSeat*, price) + book()
calculatePrice(seats) -> PriceCalculator: calculatePrice(vector<ShowSeat*>)
pay(bookingId, paymentMethod) -> Payment: pay(amount) (UPI/Card/Cash polymorphism)
confirmBooking(bookingId) -> On success: Booking: confirm() -> Status CONFIRMED
printTicket(bookingId) -> TicketPrinter: printTicket(Booking&)
Alt Flows:
alt [Seat already booked]: isAvailable() == false -> "Seat already booked"
alt [Payment failed]: pay() fails -> Booking: fail() + cancel() + ShowSeat: release()
🔑 Core Code Snippets
ShowSeat.h (Exact from your code)
cpp
class ShowSeat {
private:
    Seat seat;
    SeatStatus status;
public:
    bool isAvailable();
    void book();
    void release();
    // ...
};
Booking.h (Exact from your code)
cpp
class Booking {
    static int nextBookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> selectedSeats;
    BookingStatus status;
public:
    void addSeat(ShowSeat* seat, int price);
    void confirm();
    void fail();
    void cancel();
};
🚀 How to Compile & Run
bash
g++ -std=c++17 src/*.cpp -o booking_system
./booking_system
💡 Design Patterns Used
Strategy Pattern: Payment (UpiPayment, CardPayment, CashPayment)
Utility Classes: PriceCalculator, TicketPrinter
Enum for State Management: BookingStatus, SeatStatus
Made for academic project
