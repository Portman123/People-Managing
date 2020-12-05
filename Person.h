// Student ID: 201319103

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
	//Declare person class attributes
private:
	string name;
	int age;

	//Public methods
public:
	//Constructor declerations
	Person(string nameValue, int ageValue);
	Person();

	//Getters and setters
	void setName(string value) { name = value; }
	string getName(void) { return name; }

	void setAge(int value) { age = value; }
	int getAge(void) { return age; }

	//Operator overloads...
	//-Comparisons
	bool operator==(Person& person);
	bool operator<(Person& person);
	bool operator>(Person& person);

	//-Output
	friend ostream& operator<<(ostream& ouput, const Person& person);
	
	//-Input
	friend istream& operator>>(istream& input, Person& person);

};

