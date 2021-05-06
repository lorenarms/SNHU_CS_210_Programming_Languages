#include <iostream>
#include <string>
#include <Python.h>


using namespace std;

int main() {
	cout << "Start 1 \n";
	Py_Initialize();
	cout << "2\n";
	PyObject* my_module = PyImport_ImportModule("pthon");
	cerr << my_module << "\n";
	PyErr_Print();
	cout << "3\n";
	PyObject* my_function = PyObject_GetAttrString(my_module, "printSomething");
	cout << "4\n";
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

}