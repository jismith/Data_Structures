#include "BHeap.h"
#include <stdexcept>
#include <iostream>

//NOTE: this is an implementation of a MAX HEAP, so the top will be the max element.


//helper functions to compute locations of parents and children in vector
int BHeap::parent(int i)
{
	return (i - 1) / 2;
}
int BHeap::left(int i)
{
	return 2 * i + 1;
}
int BHeap::right(int i)
{
	return 2 * i + 2;
}

unsigned int BHeap::heapSize() {
	return heap.size();
}


void BHeap::siftUp(int i) {
	//check if node at i and its parent violate heap property
	if (i && heap[parent(i)] < heap[i]) {
		//if so, swap the elements and sift up on the parent
		std::swap(heap[i], heap[parent(i)]);
		siftUp(parent(i));
	}
}

void BHeap::siftDown(int i) {
	int left = BHeap::left(i);
	int right = BHeap::right(i);

	int largest = i;

	//compare node at i against its children to find the largest
	if (left < heap.size() && heap[left] > heap[i]) {				//explicitly, if the node's left child's index is in bounds
		largest = left;												//and the value of the left child is larger than the current node's value
	}																//set the largest to the left node's index

	if (right < heap.size() && heap[right] > heap[largest]) {		//similar processing for the right child
		largest = right;
	}

	if (largest != i) {												//if the largest node is not the current node's index
		std::swap(heap[i], heap[largest]);							//swap the current node and the largest node (whether it was the left or right child)
		siftDown(largest);											//recursively call siftDown on the largest node
	}
}

//check if heap is empty
bool BHeap::isEmpty() {
	return heap.size() == 0;
}

//push new node onto heap
void BHeap::push(int key) {
	//use built in vector function to push a key 
	BHeap::heap.push_back(key);

	//index will be at the end of the vector (remember, vectors start at zero)
	int index = BHeap::heap.size() - 1;
	//move the element into its correct position
	siftUp(index);
}

void BHeap::pop() {
	try {
		//if the heap is empty, throw exception
		if (heap.size() == 0) {
			throw std::out_of_range("Vector<X>::at() :"
				"index is out of range(Heap underflow)");
		}

		//replace the root with the last element in the heap
		heap[0] = heap.back();
		heap.pop_back();

		//now heapify down from the root
		siftDown(0);

	}
	//catch block for exception
	catch (const std::out_of_range& oor) {
		std::cout << std::endl << oor.what();
	}

}

int BHeap::top() {
	try {
		//if the heap is empty, throw exception
		if (heap.size() == 0) {
			throw std::out_of_range("Vector<X>::at() :"
				"index is out of range(Heap underflow)");
		}
		//otherwise return the root
		return heap.at(0);
	}
	catch (const std::out_of_range& oor) {
		std::cout << std::endl << oor.what();
	}
}

