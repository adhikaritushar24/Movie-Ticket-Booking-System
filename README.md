# 🎬 Movie Ticket Booking System - C++

A simple and clean C++ implementation of a Movie Ticket Booking System using OOP principles. This project follows SOLID principles with proper class segregation and is designed from UML to code.

📂 GitHub Repository: https://github.com/adhikaritushar24/Movie-Ticket-Booking-System

## 📁 Project Structure

```
MovieTicketFlat/
├── .gitignore
├── main.cpp                # Entry point - Console Menu System
├── main.exe                # Compiled executable
├── Movie.h / Movie.cpp
├── Screen.h / Screen.cpp   # Screen containing vector<Seat>
├── Seat.h / Seat.cpp       # Seat with SeatType (SILVER, GOLD, PLATINUM)
├── Show.h / Show.cpp       # Show with Movie* and Screen*
├── ShowSeat.h / ShowSeat.cpp # Show-specific seat with SeatStatus
├── Cinema.h / Cinema.cpp   # Manages Movies and Shows
├── Customer.h / Customer.cpp
├── Booking.h / Booking.cpp # Booking with Customer*, Show*, vector<ShowSeat*>
├── BookingService.h / BookingService.cpp # Core service for booking logic
├── Payment.h / Payment.cpp # Abstract Payment class
├── PaymentTypes.h / PaymentTypes.cpp # UpiPayment, CardPayment, CashPayment
├── PriceCalculator.h / PriceCalculator.cpp
├── TicketPrinter.h / TicketPrinter.cpp
├── README.md
└── images/
    ├── movie_ticket_booking_system_class_diagram.png
    ├── movie_ticket_booking_sequence_diagram.png
    ├── console_part1_steps_1_2.png
    └── console_part2_steps_3_4.png
```

> All headers (.h) and implementations (.cpp) are in the same folder for simple flat-file compilation. No separate headers/src folder.

## 🧱 Class Diagram
![Class Diagram](images/movie_ticket_booking_system_class_diagram.png)

This diagram is 100% matched with your codebase headers.

### Key Relationships:
- **Composition** `Screen ◆-- Seat` : Screen owns Seats by value `vector<Seat>`
- **Aggregation** `Show ◇-- Movie* , Screen*` : Show has pointers to Movie and Screen
- **Composition** `ShowSeat -- Seat` : ShowSeat contains Seat by value
- **Aggregation** `Cinema ◇-- Movie, Show` : Cinema manages collection
- **Aggregation** `Booking ◇-- Customer*, Show*, ShowSeat*` : Booking holds pointers
- **Inheritance** `Payment <|-- UpiPayment, CardPayment, CashPayment`
- **Dependency** `PriceCalculator ..> ShowSeat, SeatType` and `TicketPrinter ..> Booking` and `BookingService ..> Cinema, Booking`

### Enums (from your code):
```cpp
enum class SeatType { SILVER, GOLD, PLATINUM };
enum class SeatStatus { AVAILABLE, BOOKED };
enum class BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };
```

## 🔄 Sequence Diagram - Book Ticket Flow
![Sequence Diagram](images/movie_ticket_booking_sequence_diagram.png)

### Complete Flow (Matches your console output):
1. **listMovies()** - MAIN MENU Choice: 1 -> `Cinema: getMovies()`
2. **selectShow(showId)** - MAIN MENU Choice: 3 -> Show ID 1 -> `Cinema: getShow(1)` -> `Selected: Show #1 | Movie: Fight-Club | Screen: 1 | Time: 7:00 PM`
3. **getSeatAvailability()** - MAIN MENU Choice: 4 -> `ShowSeat: isAvailable()` -> Display `A1 [SILVER] Rs.150 - AVAILABLE` etc.
4. **bookSeats([A1])** - MAIN MENU Choice: 5 -> `Enter seat numbers: A1` -> `isAvailable()` check
5. **calculatePrice()** - `PriceCalculator: calculatePrice()` -> `Total amount for 1 seat(s): Rs.150`
6. **pay()** - `Select payment: 3. Cash` -> Polymorphic `Payment->pay(amount)` -> `Cash received. Payment successful.`
7. **createBooking() & confirm()** - On success `Booking: confirm()` -> `Status: CONFIRMED`
8. **printTicket()** - `TicketPrinter: printTicket(Booking&)` -> Prints Booking ID, Movie, Screen, Seats, Amount

### Alt / Failure Flows:
- **alt [Seat already booked]**: `isAvailable() == false` -> "Seat already booked"
- **alt [Payment failed]**: `pay() == false` -> `Booking: fail()` -> `ShowSeat: release()`

## 🔑 Core Code Snippets (Exact from your code)

**ShowSeat.h**
```cpp
class ShowSeat {
private:
    Seat seat;
    SeatStatus status;
public:
    bool isAvailable();
    void book();
    void release();
};
```

**Booking.h**
```cpp
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
```

## 🚀 How to Compile & Run

Since it's a flat structure, compile directly inside `MovieTicketFlat`:

```bash
# Inside MovieTicketFlat folder
g++ -std=c++17 *.cpp -o main
./main          # Linux/Mac
.\main.exe      # Windows PowerShell

# Or compile file by file (as shown in your screenshot)
g++ -std=c++17 main.cpp Booking.cpp BookingService.cpp Cinema.cpp Customer.cpp Movie.cpp Payment.cpp PaymentTypes.cpp PriceCalculator.cpp Screen.cpp Seat.cpp Show.cpp ShowSeat.cpp TicketPrinter.cpp -o main
```

Menu Flow to test:
```
1. List Movies
3. Select a Show -> Enter 1
4. Show Seat Availability
5. Book Seats -> A1 -> 3 (Cash)
```

## 💡 Design Concepts Used
- **Strategy Pattern**: `Payment` base class with `UpiPayment, CardPayment, CashPayment`
- **Composition over Inheritance**: `Screen` owns `Seat` by value
- **SOLID**: Single Responsibility (PriceCalculator, TicketPrinter separate), Open/Closed (Payment extensible), Dependency Inversion (Booking depends on Payment abstraction)
- **Encapsulation**: Seat status managed via `book()/release()/isAvailable()`

---
Made for System Design coursework.
