#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

void ItemToPurchase::setName(string name) {
    itemName = name;
}
void ItemToPurchase::setPrice(int price) {
    itemPrice = price;
}
void ItemToPurchase::setQuantity(int quantity) {
    itemQuantity = quantity;
}

string ItemToPurchase::getName() {
    return itemName;
}
int ItemToPurchase::getPrice() {
    return itemPrice;
}
int ItemToPurchase::getQuantity() {
    return itemQuantity;
}
    //getting the total cost of all items
int ItemToPurchase::getTotalCost(vector<ItemToPurchase>& items) {
    int totalCost = 0;
    int itemCost = 0;
    cout << "TOTAL COST" << endl;
    //loop through any sized vector
    for (int i = 0; i < items.size(); i++) {
        //calculate total cost and individual item cost
        totalCost += items.at(i).getPrice() * items.at(i).getQuantity();
        itemCost = items.at(i).getPrice() * items.at(i).getQuantity();
        cout << items.at(i).getName() << " " << items.at(i).getQuantity() << " @ $" << items.at(i).getPrice() << " = $" << itemCost << endl;
    }
    cout << endl;
    cout << "Total: $" << totalCost << endl;

    /*
    TOTAL COST
    Chocolate Chips 1 @ $3 = $3
    Bottled Water 10 @ $1 = $10

    Total: $13
    */

    return totalCost;

}


