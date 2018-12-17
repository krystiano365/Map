#include "Map.h"														// Defines template Map<Key, Value>
#include "Employee.h"													// Defines class Employee
#include <iostream>


using namespace std;

int main() {
//	Map<int, float> m;
//	try{
//		m.add(15, 9);
//		m.add(10, 10.5f);
//		m.add(9, 10.1f);
//		m.add(12, 10.31f);
//		m.add(15, 10.3f);
//	}catch (exception &e){
//		cout << e.what() << endl;
//	}
//	cout << m << endl;
//
//	float *dupa;
//	dupa = m.find(12);
//
//	Map<int, float> m2(m);
//	try{
//		cout << *m.find(15) << endl;
//	} catch (NoSuchKeyException &e){
//		cout << e.what() << endl;
//	}


	typedef unsigned int ID; 											// Identification number of Employee
	Map<ID, Employee> database;											// Database of employees

	try{
		database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
		database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee: name: Adam Nowak, position: storekeeper, age: 54
		database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee: name: Anna Zaradna, position: secretary, age: 32
	} catch (KeyAlreadyExistsException e) {
		cout << e.what() << endl;
	}

	cout << database << endl;											// Print database

	Map<ID, Employee> newDatabase = database;							// Make a copy of database (copy constructor called)

	Employee* pE;
	try {
		pE = newDatabase.find(510212881);                                    // Find employee using its ID
		pE->position = "salesman";                                            // Modify the position of employee
		pE = newDatabase.find(761028073);                                    // Find employee using its ID
		pE->age = 29;                                                        // Modify the age of employee
	} catch (NoSuchKeyException e){
		cout << e.what() << endl;
	}
	newDatabase.add(3333333, Employee("Edek B", "debil", 33));
	//database = newDatabase;												// Update original database (assignment operator called)
	Map<ID, Employee> test = newDatabase;
	cout << test << endl;
	//cout << database << endl;											// Print original database
};