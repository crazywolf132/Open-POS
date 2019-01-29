#include "Stock.h"


Stock::Stock(int id, string n, double p) {
    id = id;
    name = n;
    price = p;
}

void Stock::display() const {
    printf("%-20s $%5.2f\n", name.c_str(), price);
}

double Stock::get_price() const {
    return price;
}

void addStock(map<int, Stock> &stockItems, map<int, int> &Basket)
{
    ifstream fin("stock.db");

    if (fin.fail()) {
        cout << "Error opening stock file!" << endl;
    } else {
        string line;
        int pos = 1;
        if (fin.is_open()) {
            while(getline(fin, line)) {
                string s;
                istringstream iss(line);
                vector < string > parts;
                while (getline(iss, s, ',')) {
                    parts.push_back(s);
                }

                double price = 0.00;
                stringstream priceTag(parts.at(1));
                priceTag >> price;

                Stock newest(pos, parts.at(0), price);
                stockItems.insert(stockItems.begin(), pair< int, Stock >(pos, newest));
                pos += 1;
            }
            fin.close();
        }
    }
}

void addToBasket(map<int, Stock> &stockItems, map<int, int> &Basket) {
    int code = 0, qty = 0, confirm = 0;

    cout << endl << setw(21) << "Menu" << endl << endl;
    cout << setw(6) << "Code" << setw(11) << "Items" << setw(17) << "Price" << endl << endl;

    int lastStockNum = 0;
    for (auto item: stockItems) {
        printf("%5d   ", item.first);
        item.second.display();
        lastStockNum = item.first;
    }

    cout << endl << " Order Up! " << endl;

    while (confirm != 1) {
        cout << "Enter item number (1-" << lastStockNum << ") (-1 to end): " << endl;
        cin >> code;

        if (code == -1) {
            cout << endl << "-------------------------------" << endl;
            printf("%7s%24s", "Items", "Quantity");
            cout << endl << "-------------------------------" << endl;

            for(auto selected: Basket) {
                printf("  %-24s%d\n", stockItems[selected.first].getName().c_str(), selected.second);
            }

            cout << endl << endl << "Would you like to finish this cart (1=yes, other=no)? ";
            cin >> confirm;

        } else if (code > lastStockNum || code < 1) {
            cout << endl << " Please enter a code that is in the menu!" << endl << endl;
            continue;
        } else {
            cout << "Enter qty: ";
            cin >> qty;

            Basket[code] += qty;
        }
    }
    system("clear");
}

void payOrder(map<int, Stock > &stockItems, map<int, int> &Basket) {
    cout << endl << "----------------------------------------------------" << endl;
    printf("%fs%30s%15s\n", "Items", "Quantity", "Subtotal");
    cout << endl << "----------------------------------------------------" << endl;

    double subTotal = 0;

    for (auto item: Basket) {
        if (item.second > 0) {
            printf("  %-24s%7d%13s%6.2f\n", stockItems[item.first].getName().c_str(), item.second, (stockItems[item.first].get_price() * item.first));
            subTotal += (stockItems[item.first].get_price() * item.first);
        }
    }
    system("clear");
}

int main() {

    system("clear");

    map<int, Stock> stockItems;
    map<int, int> Basket;

    addStock(stockItems, Basket);

    int selected = 0;

    while (selected != 3) {
        cout << "\n Welcome to OPEN POS v1.0.1" << endl;
        cout << "Please choose one of the following options..." << endl << endl << endl;
        cout << "1]    Place Order" << endl;
        cout << "2]    Calculate and print the bill" << endl;
        cout << "3]    Exit" << endl;
        
        cout << endl << "Enter Option: ";
        cin >> selected;

        system("clear");
        switch(selected) {
            case 1:
                /*for(auto v: stock) {
                    for(auto i: v.second) {
                        std::cout << v.first << " : " << i.first << " : " << i.second << std::endl;
                    }
                }*/
                addToBasket(stockItems, Basket);
                break;
            case 2:
                payOrder(stockItems, Basket);
                break;
        }
    }


    return 0;
}