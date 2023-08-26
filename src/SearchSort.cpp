#include "SearchSort.hpp"
void clearCin(void) {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void bubbleSort(vector<ArcticAnimal*> &vectorArcticAnimals, char DorA){


	if(DorA == 'D'){
		int maxElement;
		for(maxElement = vectorArcticAnimals.size() - 1; maxElement > 0; maxElement--){
			for(int i = 0; i < maxElement; i++){
				if(vectorArcticAnimals[i]->population < vectorArcticAnimals[i + 1]->population){
					swap(vectorArcticAnimals[i], vectorArcticAnimals[i + 1]);
				}
			}
		}

	}else if(DorA == 'A'){
		int maxElement;
		for (maxElement = vectorArcticAnimals.size() - 1; maxElement > 0; maxElement--) {
			for (int i = 0; i < maxElement; i++) {
				if (vectorArcticAnimals[i]->population > vectorArcticAnimals[i + 1]->population) {
					swap(vectorArcticAnimals[i], vectorArcticAnimals[i + 1]);
				}
			}
		}
	}else{
		cout << "**Error please enter a valid option" << endl;
	}
}

void selectSort (vector<ArcticAnimal*> &tempAnimal, char DorA) {
    int size = tempAnimal.size();
    if (tolower(DorA) == 'a') {
        int i, j, minIndex;
        for (i = 0; i < size - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < size; j++) {
                if (tempAnimal[j]->population < tempAnimal[minIndex]->population) {
                minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(tempAnimal[minIndex], tempAnimal[i]);
            }
        }
    }else if (towlower(DorA) == 'd') {
        int i, j, maxIndex;
        for (i = 0; i < size - 1; i++) {
            maxIndex = i;
            for (j = i + 1; j < size; j++) {
                if (tempAnimal[j]->population > tempAnimal[maxIndex]->population) {
                    maxIndex = j;
                }
            }
            if (maxIndex != i) {
                swap(tempAnimal[maxIndex], tempAnimal[i]);
            }
        }
    }else{
    	cout << "**Error please enter a valid option" << endl;
    }
}



bool intLinearSearch(vector<ArcticAnimal*> ArcticAnimals, int population){

	unsigned int index = 0;
	bool found = false;
	while(index < ArcticAnimals.size() && !found){
		if(ArcticAnimals[index]->population == population){
			found = true;

		}
		index++;
	}

	return found;
}

bool intBinSearch(vector<ArcticAnimal*> ArcticAnimals, int population){
	int first = 0;
	int last = ArcticAnimals.size() - 1;
	int middle;
	bool found = false;

	while(!found && first <= last){
		middle = (first + last) / 2;
		if(ArcticAnimals[middle]->population == population){
			found = true;
		}else if(ArcticAnimals[middle]->population > population){
			last = middle - 1;
		}else{
			first = middle + 1;
		}
	}
	return found;

}
