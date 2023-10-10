using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>
#include "heap_sort.h"

void checkSort(const vector<int>& a) {
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i] >= a[i + 1]) {
			cout << "Error at " << i << endl;
		}
	}
	cout << "Finished checksort" << endl;
}


template <typename AnyType>
void permute(vector<AnyType>& a) {
	for (int j = 1; j < a.size(); ++j) {
		swap(a[j], a[rand() % j]);
	}
}

int main() {
	const int NUM_ITEMS = 1000;

	vector<int>a(NUM_ITEMS);
	for (int i = 1; i < a.size(); ++i) {
		a[i] = a[i - 1] + 'a';
	}

	for (int theSeed = 0; theSeed < 10; ++theSeed) {
		srand(time(0) + theSeed);

		permute(a);
		heapSort(a);
		checkSort(a);
	}

	return 0;
}

/*
If we first look at the case where the array A is already sorted in increasing order, the running time of heapsort becomes O(N * log N). 
This is because, during the buildHeap phase, each element is inserted into the heap, resulting in a heap with N elements. 
The heapify operation takes log N time for each insertion, and there are N elements to insert.

For the case where the array A is sorted in decreasing order, the running time is also O(N * log N). 
While building the heap, each element is compared with its parent and swapped if necessary, 
resulting in log N comparisons for each element, and there are N elements.

Heapsort has a worst-case time complexity of O(N * log N) regardless of the initial order of the elements in the array.
*/