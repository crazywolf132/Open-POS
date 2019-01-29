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

/*void addToBasket(std::map<int, std::map<std::string, std::string> > &stock, std::map<int, int> &Basket) {
    std::cout << std::endl << std::setw(21) << "Menu" << "\n" << std::endl;
    std::cout << std::setw(6) << "Code" << std::setw(11) << "Items" << std::setw(17) << "Price" << std::endl << std::endl;

    int lastStockNum = 0;

    for (auto v: stock) {
        std::cout << std::setw(6) << v.first << " " << std::setw(6) << v.second["name"] << std::setw(17) << v.second["price"] << std::endl;
        lastStockNum = v.first;
    }

    std::cout << "\n\n\n";

    int code = 0;
    int confirm = 0;
    int qty = 0;

    while (confirm != 1) {
        std::cout << "Enter Item's code (-1 to process): ";
        std::cin >> code;
        std::cin.ignore(100000, '\n');

        if (code == -1) {
            std::cout << "\n\n";
            std::cout << std::endl << "-------------------------------" << std::endl;
            std::cout << std::setw(7) << "Items" << std::setw(24) << "Quantity";
            std::cout << std::endl << "-------------------------------" << std::endl;

            for(auto v: Basket) {
                if (v.second != 0){
                    std::cout << "  " << stock[v.first]["name"] << std::setw(20) << v.second << std::endl;
                }
            }
        } else if (code > lastStockNum || code < 1) {
            std::cout << "Please enter a code that is on the menu..." << std::endl;
            continue;
        } else {
            std::cout << "How many? ";
            std::cin >> qty;
            std::cin.ignore(100000, '\n');

            Basket[code] += qty;
        }

    }
    system("clear");
}*/

void payOrder(map<int, Stock > &stock, map<int, int> &Basket) {

    system("clear");
}

int main() {

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
        }
    }


    return 0;
}