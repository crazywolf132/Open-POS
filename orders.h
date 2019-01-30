#include "stock.h"

class Order {
    public:
      Order(double t, map<int, Stock> o, bool im);
      const double getTotal( ) const { return total; }
      const bool getMemberStatus( ) const { return isMember; }
      void display( ) const;
      int itemCount( ) const;

    private:
        double total;
        map<int, Stock> order;
        bool isMember;
};