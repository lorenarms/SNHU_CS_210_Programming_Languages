/*
This was a lab from CS 210, sorting a vector

Instructions/parameters are at the bottom
*/


#include <iostream>
#include <vector>
using namespace std;

/* Define your function here */
void SortVector(vector<int>& myVec) {
	int temp;
	for (int i = 0; i < myVec.size(); i++) {
		for (int j = 0; j < myVec.size(); j++) {
			if (myVec.at(i) < myVec.at(j)) {
				temp = myVec.at(j);
				myVec.at(j) = myVec.at(i);
				myVec.at(i) = temp;
			}
		}
	}
}

int main() {
	vector<int> myVec;
	int input;
	int total;
	int index = 0;
	cin >> total;
	
	for (int i = 0; i < total; ++i) {
		cin >> input;
		myVec.emplace_back(input);
	}

	
	
	//vector<int> myVec = { 5, 4, 7, 2, 1, 8, 3 , 10, 6 , 1};
	SortVector(myVec);
	
	for (int i = 0; i < myVec.size(); i++) {
		cout << myVec.at(i) << " ";
	}
	cout << endl;

	return 0;
}

/*
Write a program that gets a list of integers from input, and outputs the integers in ascending order (lowest to highest). 
The first integer indicates how many numbers are in the list. Assume that the list will always contain less than 20 integers.

	Ex: If the input is:

		5 10 4 39 12 2

	the output is:

		2 4 10 12 39

For coding simplicity, follow every output value by a space, including the last one.

Your program must define and call the following function. When the SortVector function is complete, the vector passed 
in as the parameter should be sorted.
void SortVector(vector<int>& myVec)
*/