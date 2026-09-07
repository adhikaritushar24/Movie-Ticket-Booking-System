#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    int customerId;
    string name;
    string phone;

public:
    Customer(int customerId, string name, string phone);

    int getCustomerId();
    string getName();
    string getPhone();
};

#endif
