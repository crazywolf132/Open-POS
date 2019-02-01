#ifndef POS
#define POS

#include "transactions.h"

typedef Transactions TRANS;
typedef map<int, Stock> STOCKITEMS;
typedef map<int, int> BASKET;

void _clear_screen( );
void loadTrans( TRANS &trans );
void addStock( STOCKITEMS & stockItems, BASKET & Basket );
void addToBasket( STOCKITEMS & stockItems, BASKET & Basket );
void payOrder( STOCKITEMS & stockItems, BASKET & Basket, TRANS &trans );
void listOTrans( TRANS &trans );
void saveTrans( TRANS &trans );


#endif