#include "orders.h"

Order::Order(double t, map<int, Stock> o, bool im) : total(t), order(o), isMember(im) {}

void Order::display( ) const {
    for (auto item: order) {
        item.second.display();
    }
}

int Order::itemCount( ) const {
    int counter = 0;
    for (auto item: order) {
        counter++;
    }
    return counter;
}