#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
protected:
    double amount;

public:
    Payment(double amount);
    virtual ~Payment();

    virtual bool pay() = 0;
    double getAmount();
};

#endif
