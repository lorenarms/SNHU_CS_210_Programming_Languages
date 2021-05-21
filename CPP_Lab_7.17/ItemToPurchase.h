#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
#include <vector>

using namespace std;

class ItemToPurchase 
{
public:
    void setName(string);
    void setPrice(int);
    void setQuantity(int);

    string getName();
    int getPrice();
    int getQuantity();

    int getTotalCost(vector<ItemToPurchase>& items);

    //default values
private:
    string itemName = "none";
    int itemPrice = 0;
    int itemQuantity = 0;

};
#endif