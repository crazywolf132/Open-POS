#include "orders.h"

Order::Order(double t, map<int, Stock> o, bool im) : total(t), order(o), isMember(im) {}

void Order::display( ) const {
    cout << itemCount() << setw(15) << getTotal() << setw(15) << getMemberStatus() << endl;
}

int Order::itemCount( ) const {
    int counter = 0;
    for (auto item: order) {
        counter++;
    }
    return counter;
}