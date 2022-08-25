#pragma once
#include <vector>
class BHeap
{
private:
	std::vector<int> heap;

	int parent(int i);
	int left(int i);
	int right(int i);

	void siftUp(int i);
	void siftDown(int i);

	
	

public:

	unsigned int heapSize();
	bool isEmpty();
	void push(int key);
	void pop();

	int top(); //does not pop the heap, pretty much a peek function


};

