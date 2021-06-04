#include "ContactNode.h"

void ContactNode::InsertAfter(ContactNode*& head, ContactNode*& tail, string number, string name) {
	if (head == NULL) {
		ContactNode* temp = new ContactNode;
		temp->contactName = name;
		temp->contactPhoneNum = number;
		temp->nextNodePtr = NULL;
		head = temp;
		tail = temp;
	}
	else {
		ContactNode* temp = new ContactNode;
		temp->contactName = name;
		temp->contactPhoneNum = number;
		temp->nextNodePtr = NULL;
		tail->nextNodePtr = temp;
		tail = temp;
	}
}

string ContactNode::Getname(ContactNode& curr) {
	//cout << curr.contactName << endl;
	return curr.contactName;
}

void ContactNode::GetPhoneNumber(ContactNode& curr) {
	cout << curr.contactPhoneNum << endl;
}

void GetNext(ContactNode*& head, ContactNode*& tail) {

}

void ContactNode::PrintContactNode(ContactNode* curr) {
	if (curr == NULL) {
		cout << "The list is empty.\n";
	}
	else {
		cout << "CONTACT LIST\n" << endl;
		
		while (curr != NULL) {
			cout << "Name: " << curr->contactName << endl;
			cout << "Number: " << curr->contactPhoneNum << endl;
			cout << endl;
			curr = curr->nextNodePtr;
		}
	}
}



