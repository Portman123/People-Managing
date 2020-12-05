// Student ID: 201319103

#include "Person.h"
#include <iostream>

Person::Person(string nameValue, int ageValue)
{
	setName(nameValue);
	setAge(ageValue);
}

Person::Person()
{
	setName("");
	setAge(0);
}

bool Person::operator==(Person & person)
{
	return this->age == person.getAge();
}

bool Person::operator<(Person & person)
{
	return this->age < person.getAge();
}

bool Person::operator>(Person & person)
{
	return this->age > person.getAge();
}

istream& operator>>(istream & input, Person& person)
{
	input >> person.name >> person.age;
	return input;
}

ostream& operator<<(ostream& output, const Person& person)
{
	output << person.name << " " << person.age;
	return output;
}
