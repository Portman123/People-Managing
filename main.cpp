// 201319103
// COMP282 Assignment 1

// PLEASE INCLUDE YOUR ID AT THE TOP OF EACH SOURCE FILE
// Student ID: 201319103

// - I wasn't sure whether to make seperate functions for each task in each part.
// - I decided to keep all code for each part in the methods given as there were instructions for this.


#include <iostream>
#include "Person.h"
#include <vector>
#include <algorithm>
using namespace std;

void main_part1() {
	// Treat this as the main method for PART 1 of the coursework
	cout << "Part 1" << endl;

	Person person1("Percy", 17);
	Person person2("Lucy", 24);
	Person person3;
	cout << "person1: " << person1 << endl;
	cout << "person2: " << person2 << endl;
	cout << "person3: " << person3 << endl;

	cout << "person1 == person2?... " << (person1 == person2) << endl;
	cout << "person1 < person2?... " << (person1 < person2) << endl;
	cout << "person1 > person2?... " << (person1 > person2) << endl;
}

void main_part2() {
	// Treat this as the main method for PART 2 of the coursework	
	cout << endl;
	cout << "Part 2" << endl;
	
	//Declare variables
	string menuInput;
	Person personList[9];
	//Track number of people in the array
	int peopleAdded = 0;

	//Menu Loop
	while (menuInput != "Q") {

		//Print Menu
		cout << "1. Add Person" << endl;
		cout << "2. List Everyone" << endl;
		cout << "3. Remove Person" << endl;
		cout << "4. Find Oldest" << endl;
		cout << "Q. Quit" << endl;
		cout << "Enter Option: ";

		//Get user menu input
		cin >> menuInput;

		//Menu Option 1 - Add Person
		if (menuInput == "1") {
			if (peopleAdded < 9) {
				//Declare new person to add
				Person newPerson;

				//Get user input
				cout << "Enter Details: ";
				cin >> newPerson;

				//Add to array
				personList[peopleAdded] = newPerson;
				peopleAdded++;
			}
			else {
				cout << "9 people have already been added" << endl;
			}
		}

		//Menu Option 2 - List Everyone
		else if (menuInput == "2") {
			for (int i = 0; i < peopleAdded; i++) {
				cout << "[" << i + 1 << "] " << personList[i] << endl;
			}
		}

		//Menu Option 3 - Remove Person
		else if (menuInput == "3") {

			//Get user input for index
			int inputIndex;
			cout << "Enter Index: ";
			cin >> inputIndex;

			//Check user's input in range
			if (inputIndex > 0 && inputIndex <= peopleAdded) {
				//Shift everything after specified index down by one index
				for (int i = inputIndex; i < peopleAdded; i++) {
					personList[i - 1] = personList[i];
				}

				//Now that person effectively removed from list, decrement people added
				peopleAdded--;
			}
			else {
				cout << "Index out of range" << endl;
			}
		}

		//Menu Option 4 - Find Oldest
		else if (menuInput == "4") {
			Person oldest;

			//Compare with current oldest
			for (int i = 0; i < peopleAdded; i++) {
				if (personList[i] > oldest) {
					oldest = personList[i];
				}
			}

			//Output oldest
			cout << "Oldest: " << oldest << endl;
		}
	}
}

void main_part3() {
	// Treat this as the main method for PART 3 of the coursework
	cout << endl;
	cout << "Part 3" << endl;

	string menuInput;
	//personList is now a vector container with no predetermined size
	vector<Person> personList;
	//Declare iterator for person list Vector
	vector<Person>::iterator it;

	//Menu Loop
	while (menuInput != "Q") {

		//Print Menu
		cout << "1. Add Person" << endl;
		cout << "2. List Everyone" << endl;
		cout << "3. Remove Person" << endl;
		cout << "4. Find Oldest" << endl;
		cout << "5. Sort Data" << endl;
		cout << "Q. Quit" << endl;
		cout << "Enter Option: ";

		//Get user menu input
		cin >> menuInput;

		//Menu Option 1 - Add Person
		if (menuInput == "1") {
			//Declare new person to add
			Person newPerson;

			//Get user input
			cout << "Enter Details: ";
			cin >> newPerson;

			//Add to vector
			personList.push_back(newPerson);
		}

		//Menu Option 2 - List Everyone
		else if (menuInput == "2") {
			for (it = personList.begin(); it != personList.end(); it++) {
				//(calculate offset from begining to display index)
				cout << "[" << it - personList.begin() + 1 << "] " << *it << endl;
			}
		}

		//Menu Option 3 - Remove Person
		else if (menuInput == "3") {

			//Get user input for index
			int inputIndex;
			cout << "Enter Index: ";
			cin >> inputIndex;

			//Check user's input in range
			if (inputIndex > 0 && inputIndex <= personList.size()) {
				//Erase Person and user input index
				personList.erase(personList.begin() + (inputIndex - 1));
			}
			else {
				cout << "Index out of range" << endl;
			}
		}

		//Menu Option 4 - Find Oldest
		else if (menuInput == "4") {
			Person oldest;

			//Compare with current oldest
			for (it = personList.begin(); it != personList.end(); it++) {
				if (*it > oldest) {
					oldest = *it;
				}
			}

			//Output oldest
			cout << "Oldest: " << oldest << endl;
		}

		//Menu Option 5 - Sort Data
		else if (menuInput == "5") {
			sort(personList.begin(), personList.end());
		}
	}
}

int main() {
	// UNCOMMENT THE RELEVANT LINE TO TEST/RUN EACH PART
	
	cout << "Each part executes after the last, quit part2 to access part3." << endl;
	cout << endl;
	main_part1();
	main_part2();
	main_part3();
}
