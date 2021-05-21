#include <iostream>
#include <vector>

using namespace std;

#include "ItemToPurchase.h"

int main() {

	//declare a vector to easily add multiple items
	//temp variables for working with the loop
	ItemToPurchase tempItem;
	vector<ItemToPurchase> items;
	string tempName;
	int tempPrice;
	int tempQuantity;

	//loop to reduce redundancy of code
	//add value to 'i' to increase number of items to add
	for (int i = 0; i < 2; i++) {
		cout << "Item " << i + 1 << endl;
		cout << "Enter the item name:" << endl;
		getline(cin, tempName);
		//cin >> tempName;
		//cin.ignore();								//keeps from skipping the next two inputs
		cout << "Enter the item price:" << endl;
		cin >> tempPrice;
		cout << "Enter the item quantity:" << endl;
		cin >> tempQuantity;
		tempItem.setName(tempName);
		tempItem.setPrice(tempPrice);
		tempItem.setQuantity(tempQuantity);
		items.emplace_back(tempItem);				//add to back of vector
		
		cout << endl;
		cin.ignore();
	}
	//reuse variables to minimize memory usage
	tempPrice = tempItem.getTotalCost(items);
	
	return 0;
}

