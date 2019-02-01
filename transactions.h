#ifndef TRANSACTIONS
#define TRANSACTIONS

#include <vector>
#include <fstream>
#include "orders.h"

class Transactions {
    public:
        Transactions( ) = default;
        Transactions( vector<Order> t );

        const int transLength( ) const { return trans.size(); }
        double getTotal( ) const;

        Order getTrans( int id ) const;

        void addTrans( Order o );

        friend ostream& operator << ( ostream& os, const Transactions & trans );
        friend ofstream& operator << ( ofstream& os, const Transactions & trans );
        friend istream& operator >> ( istream& is, Transactions & trans );
        friend ifstream& operator >> ( ifstream& is, Transactions & trans );

    private:
        vector< Order > trans;
};
#endif