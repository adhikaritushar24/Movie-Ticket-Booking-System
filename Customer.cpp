#include "Customer.h"
using namespace std;

Customer::Customer(int customerId, string name, string phone) {
    this->customerId = customerId;
    this->name = name;
    this->phone = phone;
}

int Customer::getCustomerId() { return this->customerId; }
string Customer::getName() { return this->name; }
string Customer::getPhone() { return this->phone; }
