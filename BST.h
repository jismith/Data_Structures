#pragma once
#include <iostream>
class BST
{
public:

	BST();
	~BST();

	struct Node {
		int data;
		int instanceCount;
		Node* left;
		Node* right;
		Node(int data) : data(data), left(nullptr), right(nullptr), instanceCount(1) {}
		
	};

	Node* root;

	void Insert(Node*&, int);

	void inOrder(Node*);

	void postOrder(Node*);

	void preOrder(Node*);

	Node* deleteNode(Node* &, int value);

	//Node* maxValueNode(Node*);

	Node* minValueNode(Node*);

	Node* searchBST(int key);

	//Node* findPredecessor(Node* );

	//Node* findSuccessor(Node*);

	void removeSubTree(Node* node);

};

