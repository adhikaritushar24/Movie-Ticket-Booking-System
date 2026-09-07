#include "Payment.h"

Payment::Payment(double amount) {
    this->amount = amount;
}

Payment::~Payment() {
}

double Payment::getAmount() {
    return amount;
}
