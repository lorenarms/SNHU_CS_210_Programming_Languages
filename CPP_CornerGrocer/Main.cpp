#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

#include "Menu.h"

using namespace std;



void GraphData() {
	ifstream inFS;
	ifstream inNow;
	string item;
	int count;
	string graph = "";		//histograph string
	inFS.open("frequency.dat");

	//try to open the file, otherwise return to main
	if (!inFS.is_open()) {
		cout << "Could not open file." << endl;
		return;
	}
	
	//print the graph
	cout << " HISTOGRAM OF ITEMS PURCHASED" << endl;
	cout << " =============================\n" << endl;
	do {
		inFS >> item;
		if (item == "end") {	//make sure python func prints 'end' at the end so that this works
								//otherwise 'endof' doesn't work and prints the last item twice
								//doesn't seem to be a simple workaround using 'endof'
			return;
		}
		inFS >> count;
		for (int i = 0; i < count; i++) {
			graph += "@";
		}

		cout << setw(12) << right << item << "|" << graph << " " << count << endl;
		graph = "";
		
	} while (inFS);
}

string SearchItem(Menu& newMenu) {
	//handles the search function to get string to pass to python
	system("cls");
	string item;
	newMenu.SetNewCursor(0, 0);
	cout << "Enter an item to search for: ";
	cin >> item;
	return item;
}

void DrawTitle(Menu& mainMenu) {
	//draw a splash screen!
	string splash[6];
	splash[0] = "   ____                              ____                         ";
	splash[1] = "  / ___|___  _ __ _ __   ___ _ __   / ___|_ __ ___   ___ ___ _ __ ";
	splash[2] = " | |   / _ \\| '__| '_ \\ / _ \\ '__| | |  _| '__/ _ \\ / __/ _ \\ '__|";
	splash[3] = " | |__| (_) | |  | | | |  __/ |    | |_| | | | (_) | (_|  __/ |   ";
	splash[4] = "  \\____\\___/|_|  |_| |_|\\___|_|     \\____|_|  \\___/ \\___\\___|_|   ";
	splash[5] = "                                                                  ";
	//draw the left margin!	
	mainMenu.SetNewCursor(1, 0);
	cout << "|=============================|\n" << endl;

	int row = 1;
	for (int i = 0; i < 6; i++) {
		mainMenu.SetNewCursor(row, 30);
		cout << splash[i] << endl;
		row++;
	}
	for (int i = 0; i < 25; i++) {
		mainMenu.SetNewCursor(i, 0);
		cout << "|";
		mainMenu.SetNewCursor(i, 30);
		cout << "|";
	}
	mainMenu.SetNewCursor(25, 0);
	cout << "|=============================|\n" << endl;
}

void ClearColumn(Menu& newMenu) {
	//clear the left column 
	//this avoids clearing the whole screen, reduces flashing
	
	string blank = "";
	for (int i = 0; i < 31; i++) {
		blank += " ";
	}

	for (int i = 0; i < 30; i++) {
		newMenu.SetNewCursor(i, 0);
		cout << blank;

	}
}

int MainMenu(Menu& newMenu, vector<string>& menuItems) {
	//handles main menu selection
	DrawTitle(newMenu);
	int selection = 0;
	newMenu.RunMenu(menuItems, selection);
	return selection;
}

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

void main()
{
	
	Menu mainMenu;
	int selection = 0;
	//modify the menu to look nice
	vector <string> menuItems = { "List all Items", "Search for an Item", "Print Graph", "Quit" };
	mainMenu.MenuModifier(menuItems);

	string instr[3] = { "Select an item using" , "the arrow keys and" , "press 'enter'..." };
	
	mainMenu.HideCursorBlink();

	//show the instructions
	int row = 8;
	for (int i = 0; i < 3; i++) {
		mainMenu.SetNewCursor(row, 3);
		cout << instr[i];
		row++;
	}
	
	bool run = true;
	
	while (run) {
		selection = MainMenu(mainMenu, menuItems);
		switch (selection) {
		case 1: {
			ClearColumn(mainMenu);
			mainMenu.SetNewCursor(0, 0);
			CallProcedure("ListItems");
			cout << "\n";
			break;
		}
		case 2: {
			string s = SearchItem(mainMenu); 
			system("cls");
			int count = callIntFunc("SingleItem", s);
			if (count == 0) {
				cout << "No such item exists, try again." << endl;

			}
			else {
				cout << "The number of " << s << " sold today: " << count << "\n\n";
			}
			
			system("pause");
			system("cls");
			int row = 8;
			for (int i = 0; i < 3; i++) {
				mainMenu.SetNewCursor(row, 3);
				cout << instr[i];
				row++;
			}
			break;

		}
		case 3:
			ClearColumn(mainMenu);
			mainMenu.SetNewCursor(0, 0);
			GraphData();
			break;

		case 4:
			system("cls");
			run = false;
			break;

		default: {
			
			break;
		}
		}
		
		
		
	}
		
}