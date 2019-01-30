#include "stock.h"

Stock::Stock(int id, string n, double p) : id(id), name(n), price(p) {}

void Stock::display() const {
    printf("%-20s $%5.2f\n", name.c_str(), price);
}