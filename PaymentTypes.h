#ifndef PAYMENTTYPES_H
#define PAYMENTTYPES_H

#include "Payment.h"

class UpiPayment : public Payment {
public:
    UpiPayment(double amount);
    bool pay();
};

class CardPayment : public Payment {
public:
    CardPayment(double amount);
    bool pay();
};

class CashPayment : public Payment {
public:
    CashPayment(double amount);
    bool pay();
};

#endif
