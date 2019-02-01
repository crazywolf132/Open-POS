#include "transactions.h"

Transactions::Transactions( vector< Order > t ) : trans(t) 
{   }

double Transactions::getTotal( ) const {
    double total = 0.00;
    for (auto order: trans) {
        total += order.getTotal();
    }
    return total;
}

Order Transactions::getTrans( int id ) const {
    return trans.at(id);
}

void Transactions::addTrans(Order o) {
    trans.push_back(o);
}

ostream& operator << ( ostream & os, const Transactions & trans ) {
    return os;
}

ofstream& operator << ( ofstream & os , const Transactions & trans ) {
    return os;
}

istream&  operator >> ( istream & is, Transactions & trans ) {
    return is;
}

ifstream& operator >> ( ifstream & is, Transactions & trans ) {
    return is;
}