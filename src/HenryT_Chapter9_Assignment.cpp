//============================================================================
// Name        : HenryT_Chapter9_Assignment.cpp
// Author      : Henry Timmons
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <climits>

#include "SearchSort.hpp"


int main() {

	bool programRun = true;
	char DorA;
	char userInput;
	int pop = 0;
	ArcticAnimal* tempAnimal = nullptr;
	vector<ArcticAnimal*> vectorArcticAnimals;

	string setFile;
	string inputRecord;
	string stringAvgWeight;
	string stringAvgLength;
	string stringPopulation;
	string stringEndangered;
	string stringName;
	string stringFoodSource;
	ifstream inputFile;

	while (programRun == true) {
		cout << "Menu Options" << endl;
		cout << "============" << endl;
		cout << "1) Enter the name of and read the CSV file" << endl;
		cout << "2) Bubble sort the vector of animals" << endl;
		cout << "3) Select sort the vector of animals" << endl;
		cout << "4) Binary search the population of animals" << endl;
		cout << "5) Linear search the population of animals" << endl;
		cout << "6) Print out the vector of animals" << endl;
		cout << "x) Exit the program" << endl;
		cin >> userInput;
		clearCin();

		switch (userInput) {
		case '1':
			cout << "You selected to open and read a file." << endl;
			cout << "What is the name of the file? ";
			getline(cin, setFile);
			inputFile.open(setFile);
			if (inputFile.fail()) {
				cout << "**Error file did not open correctly" << endl;
			} else {
				while (!inputFile.eof()) {
					getline(inputFile, inputRecord);

					tempAnimal = new ArcticAnimal;
					stringstream inputStream(inputRecord);
					getline(inputStream, stringName, ',');
					getline(inputStream, stringAvgWeight, ',');
					getline(inputStream, stringAvgLength, ',');
					getline(inputStream, stringPopulation, ',');
					getline(inputStream, stringEndangered, ',');
					getline(inputStream, stringFoodSource, '\n');

					tempAnimal->name = stringName;
					tempAnimal->avgWeight = stoi(stringAvgWeight);
					tempAnimal->avgLength = stoi(stringAvgLength);
					tempAnimal->population = stoi(stringPopulation);
					tempAnimal->endangered = stoi(stringEndangered);
					tempAnimal->foodSource = stringFoodSource;

					vectorArcticAnimals.push_back(tempAnimal);

				}

			}
			break;
		case '2':
			cout << "You selected Bubble Sort" << endl;
			cout
					<< "Enter 'D' to Bubble sort Descending or enter 'A' for Bubble Sort of Ascending: ";
			cin >> DorA;
			clearCin();
			bubbleSort(vectorArcticAnimals, toupper(DorA));

			break;
		case '3':
			cout << "You selected Selection Sort." << endl;
			cout
					<< "Enter 'D' to Selection Sort Descending or enter 'A' for Selection Sort of Ascending: ";
			cin >> DorA;
			clearCin();
			selectSort(vectorArcticAnimals, toupper(DorA));
			break;
		case '4':
			cout << "You selected Binary Search." << endl;
			cout << "What is the population number to search for?";
			cin >> pop;
			clearCin();
			if (intBinSearch(vectorArcticAnimals, pop) == true) {
				cout << "The population number searched for was found." << endl;
			} else if (intBinSearch(vectorArcticAnimals, pop) == false) {
				cout << "The population number searched for was not found"
						<< endl;
			}

			break;
		case '5':
			cout << "You selected Linear Search" << endl;
			cout << "What is the population number to search for?";
			cin >> pop;
			clearCin();
			if (intLinearSearch(vectorArcticAnimals, pop) == true) {
				cout << "The population number searched for was found." << endl;
			} else if (intLinearSearch(vectorArcticAnimals, pop) == false) {
				cout << "The population number searched for was not found"
						<< endl;
			}
			break;
		case '6':
			cout << "You selected to print the vector of animals." << endl;
			cout << setw(15) << left << "Animal Name" << setw(18)
					<< "Average Weight" << setw(18) << "Average Length"
					<< setw(14) << "Population" << setw(14) << "Endangered"
					<< setw(14) << "Food Source" << endl;
			cout << setw(15) << left << "===========" << setw(18)
					<< "==============" << setw(18) << "=============="
					<< setw(14) << "==========" << setw(14) << "=========="
					<< setw(14) << "===========" << endl;

			for (int i = 0; i < vectorArcticAnimals.size(); i++) {
				string YorN;
				if (vectorArcticAnimals[i]->endangered == 1) {
					YorN = "Yes";
				} else if (vectorArcticAnimals[i]->endangered == 0) {
					YorN = "No";
				}
				cout << setw(15) << left << vectorArcticAnimals[i]->name
						<< setw(18) << vectorArcticAnimals[i]->avgWeight
						<< setw(18) << vectorArcticAnimals[i]->avgLength
						<< setw(14) << vectorArcticAnimals[i]->population
						<< setw(14) << YorN << setw(14)
						<< vectorArcticAnimals[i]->foodSource << endl;
			}
			break;
		case 'x':
			cout << "Exiting the program" << endl;
			programRun = false;
			break;
		default:
			cout << "**Error, please enter a valid menu entry." << endl;
			break;

		}

	}

	inputFile.close();

	for(int i = 0; i < vectorArcticAnimals.size(); i++){
		vectorArcticAnimals[i] = 0;
	}
	vectorArcticAnimals.clear();



	cout << "Program ending, have a nice day!" << endl; // prints Program ending, have a nice day!
	return 0;
}
