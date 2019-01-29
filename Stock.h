/*
 * File Name:    stock.h
 *
 * Author:        Crazy Wolf
 * Creation Date: Tuesday, January 29 2019, 13:42 
 * Last Modified: Tuesday, January 29 2019, 13:42
 * 
 * File Description:
 * This houses the components required to create the stock items.
 */

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstring> 
#include <string> 
#include <list> 
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

class Stock {
    public:
        Stock(int id, string n, double p);
        Stock( ) = default;
        void display() const;
        const string& getName() const { return name; }
        double get_price() const;
    private:
        int id = 0;
        string name = "";
        double price = 0.00;
};