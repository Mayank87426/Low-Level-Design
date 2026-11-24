
#include <bits/stdc++.h>
using namespace std;

// Base class
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

// Credit Card Payment
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " using Credit Card" << endl;
    }
};

// UPI Payment
class UPIPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " using UPI" << endl;
    }
};

// PayPal Payment
class PayPalPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " using PayPal" << endl;
    }
};

// Shopping Cart
class ShoppingCart {
private:
    PaymentStrategy* paymentStrategy;

public:
    ShoppingCart(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void checkout(double amount) {
        paymentStrategy->pay(amount);
    }
};

int main() {

    CreditCardPayment creditCard;
    UPIPayment upi;
    PayPalPayment paypal;

    ShoppingCart cart1(&creditCard);
    cart1.checkout(1000);

    ShoppingCart cart2(&upi);
    cart2.checkout(2000);

    ShoppingCart cart3(&paypal);
    cart3.checkout(3000);

    return 0;
}
