#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include <stdexcept>
#include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeap {
  private:
	int currentSize;	        // Number of elements in heap
	vector<Comparable> array;	// The heap array

	void buildHeap();
	void minHeapify(int hole);

  public:
	BinaryHeap(int capacity = 100) : array(capacity + 1), currentSize(0) {};

	BinaryHeap(const vector<Comparable> &items) {
		array.resize(items.size() + 10);
		for (int i = 0; i < items.size(); ++i)
			array[i + 1] = items[i];
		buildHeap();
		currentSize = items.size() + 1;
	}

	bool isEmpty() const { return currentSize == 0; }

	void insert(const Comparable& x);
	const Comparable& findMin() const;
	void deleteMin();
	void deleteMin(Comparable& minItem);

};

#include "binary_heap.tpp"

#endif


/*template <typename Comparable>
void maxHeap (vector<Comparable> &array, int node, int n) {
	int child;
	Comparable tmp = std::move(array[node]);

	 // Continues on the left side of the tree until a leaf is found
	for (; node * 2 + 1 < currentSize; node = child) {
        child = node * 2 + 1;
		 // Find the larger child if the right child exists
        if (child != currentSize - 1 && array[child + 1] > array[child]) // Change the comparison to find the larger child
            ++child;
		 // If the larger child is greater than the current node, swap them
        if (array[child] > tmp)
            array[node] = std::move(array[child]);
        else
		 // if everything is as it should the heap will break
            break;
	}
	// Place the original value of the current node in its correct position
	array[node] = std::move(tmp);*/