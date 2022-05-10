#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
using namespace std;

template <class U>
void selectionSort(U* list, const int length) {

	int index;
	int smallestIndex;
	int location;
	U temp;

	unsigned long long int l = length;

	for (index = 0; index < length - 1; index++) {
		//Step a
		smallestIndex = index;

		for (location = index + 1; location < length; location++) {
			if (*list[location] < *list[smallestIndex])
				smallestIndex = location;
		}
		//Step b

		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
	}
}


#endif

