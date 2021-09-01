/*
A simple linked list example
*/

#include <iostream>
#include <string>

#include "ContactNode.h"

using namespace std;

char menu();

int main() {

	ContactNode* head = NULL;
	ContactNode* tail = NULL;
	ContactNode access;
	string name;
	string number;
	char choice;

	cout << "Person 1" << endl;
	cout << "Enter name:" << endl;
	getline(cin, name);
	//cin >> name;
	cout << "Enter phone number" << endl;
	getline(cin, number);
	cout << "You entered: " << name << ", " << number << endl;
	access.InsertAfter(head, tail, number, name);

	cout << "\nPerson 2" << endl;
	cout << "Enter name:" << endl;
	getline(cin, name);
	cout << "Enter phone number" << endl;
	getline(cin, number);
	cout << "You entered: " << name << ", " << number << endl;
	access.InsertAfter(head, tail, number, name);

	cout << "\nPerson 3" << endl;
	cout << "Enter name:" << endl;
	getline(cin, name);
	cout << "Enter phone number" << endl;
	getline(cin, number);
	cout << "You entered: " << name << ", " << number << endl;
	access.InsertAfter(head, tail, number, name);
	cout << endl;


	access.PrintContactNode(head);



/*
	do {
		choice = menu();
		switch (choice) {
		case '1':	cout << "Please enter a number: ";
			cin >> number;
			cout << "Please enter a name: ";
			cin >> name;
			access.InsertAfter(head, tail, number, name);
			break;
		case '2':	//remove(head, last);
			break;
		case '3':	access.PrintContactNode(head);
			break;
		default:	cout << "System exit\n";
		}

	} while (choice != '4');

*/
	return 0;
}

char menu() {
	char choice;
	cout << "Menu\n";
	cout << "1. Add an item.\n";
	cout << "2. Remove an item.\n";
	cout << "3. Show the list.\n";
	cout << "4. Exit.\n";

	cin >> choice;

	return choice;
}



/*
(3) In main(), prompt the user for three contacts and output the user's input. 
Create three ContactNodes and use the nodes to build a linked list. (2 pts)

*/