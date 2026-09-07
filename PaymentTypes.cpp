#include "PaymentTypes.h"
#include <iostream>
using namespace std;

UpiPayment::UpiPayment(double amount) : Payment(amount) {
}

bool UpiPayment::pay() {
    cout << "Processing UPI payment of Rs." << amount << "..." << endl;
    char choice;
    cout << "Simulate this payment as successful? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
        return true;
    return false;
}

CardPayment::CardPayment(double amount) : Payment(amount) {
}

bool CardPayment::pay() {
    cout << "Processing Card payment of Rs." << amount << "..." << endl;
    char choice;
    cout << "Simulate this payment as successful? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
        return true;
    return false;
}

CashPayment::CashPayment(double amount) : Payment(amount) {
}

bool CashPayment::pay() {
    cout << "Processing Cash payment of Rs." << amount << "..." << endl;
    cout << "Cash received. Payment successful." << endl;
    return true;
}
