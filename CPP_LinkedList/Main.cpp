/*
Another linked list example
*/

#include <iostream>
#include <string>

using namespace std;

struct node {
	int number;
	string name;
	node* next;
};

bool isEmpty(node *head);
char menu();
void insertAsFirstElement(node *&head, node *&last, int number, string name);
void insert(node*& head, node*& last, int number, string name);
void remove(node*& head, node*& last);
void showList(node *current);

bool isEmpty(node* head) {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
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

void insertAsFirstElement(node*& head, node*& last, int number, string name) {
	node* temp = new node;
	temp->number = number;
	temp->name = name;
	temp->next = NULL;
	head = temp;
	last = temp;
}

void insert(node*& head, node*& last, int number, string name) {
	if (isEmpty(head)) {
		insertAsFirstElement(head, last, number, name);
	}
	else {
		node* temp = new node;
		temp->number = number;
		temp->name = name;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void remove(node*& head, node*& last) {
	if (isEmpty(head)) {
		cout << "The list is already empty.\n";
	}
	else if (head == last) {
		delete head;
		head == NULL;
		last == NULL;
	}
	else {
		node* temp = head;
		head = head->next;
		delete temp;
	}
}

void showList(node* current) {
	if (isEmpty(current)) {
		cout << "The list is empty.\n";
	}
	else {
		cout << "The list containts: \n";
		while (current != NULL) {
			//cout << current->number << endl;
			cout << current->number << " " << current->name << endl;
			current = current->next;

		}
	}
}

int main() {

	node* head = NULL;
	node* last = NULL;
	char choice;
	int number;
	string name;

	do {
		choice = menu();
		switch (choice) {
		case '1':	cout << "Please enter a number: ";
			cin >> number;
			cout << "Please enter a name: ";
			cin >> name;
			insert(head, last, number, name);
			break;
		case '2':	remove(head, last);
			break;
		case '3':	showList(head);
			break;
		default:	cout << "System exit\n";
		}

	} while (choice != '4');

	return 0;
}