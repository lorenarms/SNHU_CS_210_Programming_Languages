#pragma once
#include <string>
#include <iostream>

using namespace std;

class ContactNode
{
public:
    void InsertAfter(ContactNode*& head, ContactNode*& tail, string number, string name);
    string Getname(ContactNode& curr);
    void GetPhoneNumber(ContactNode& curr);
    void GetNext();
    void PrintContactNode(ContactNode* curr);
    

private:
    string contactName = "Jane Doe";
    string contactPhoneNum = "555-555-5555";
    ContactNode* nextNodePtr;
};

/*
example of output
Name: Roxanne Hughes
Phone number: 443-555-2864



*/

