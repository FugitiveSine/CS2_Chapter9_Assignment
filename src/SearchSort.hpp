#ifndef SEARCHSORT_HPP_
#define SEARCHSORT_HPP_
#include <iostream>
#include <vector>
using namespace std;

struct ArcticAnimal{
	string name;
	int avgWeight;
	int avgLength;
	int population;
	bool endangered;
	string foodSource;
};
void clearCin(void);
void bubbleSort(vector<ArcticAnimal*> &vectorArcticAnimals, char DorA);
void selectSort(vector<ArcticAnimal*> &vectorArcticAnimals, char DorA);
bool intLinearSearch(vector<ArcticAnimal*> ArcticAnimals, int population);
bool intBinSearch(vector<ArcticAnimal*> ArcticAnimals, int population);


#endif /* SEARCHSORT_HPP_ */
