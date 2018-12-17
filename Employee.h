//
// Created by krystian on 17.12.18.
//

#ifndef MAP_EMPLOYEE_H
#define MAP_EMPLOYEE_H

#include <string>

using namespace std;

class Employee {

public:
	string name;
	string position;
	unsigned short int age;

	Employee(){};

	Employee(string name, string position, unsigned short int age){
		this->name = name;
		this->position = position;
		this->age = age;
	}

	friend ostream& operator<< (ostream& os, const Employee &emp){
		return os << emp.name << ", " << emp.position << ", " << emp.age;
	}
};


#endif //MAP_EMPLOYEE_H
