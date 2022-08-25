#include "BST.h"
#include <iostream>

BST::BST() {
	root = nullptr;
	std::cout << "BST constructor executed\n";
};
BST::~BST() {
	std::cout << "BST Destructor executed\n";
	removeSubTree(root);
}



void BST::Insert(Node* &root, int data) {
		if (root == nullptr) {
			root = new Node(data);		//when the function reaches a nullptr node, we create a new node here
			return;
		}

		if (data > root->data) {			//if the data we want to add is larger than the data in the current node,
			Insert(root->right, data);	//recurse to the right
		}
		else if (data < root->data) {		//if the data we want to add is smaller than the data in the current node,
			Insert(root->left, data);		//recurse to the left
		}
		else if (root->data == data) {		//if the data we want to add is the same as the current node's data
			root->instanceCount++;			//increase the count (to represent the number of duplicates)
			return;
		}
		
}

//the next three functions all work pretty much the same, we just recurse differently for each version of traversal
//remember, you need a breakpoint in recursive functions, so the root == nullptr must be true eventually in order to stay out of an infinite loop
void BST::inOrder(Node* root) {
	if (root == nullptr) {
		return;
	}
	inOrder(root->left);
	std::cout << root->data << std::endl;
	inOrder(root->right);
}

void BST::preOrder(Node* root) {
	if (root == nullptr) {
		return;
	}
	std::cout << root->data << std::endl;
	preOrder(root->left);
	preOrder(root->right);
}

void BST::postOrder(Node* root) {
	if (root == nullptr) {
		return;
	}
	postOrder(root->right);
	std::cout << root->data << std::endl;
	postOrder(root->left);
}


//helper function to aid in deletion
BST::Node* BST::minValueNode(Node* node) {
	Node* temp = node;
	if (node->left != nullptr) {	//if the left child isn't null
		minValueNode(node->left);	//recurse down left
	}
	return temp;					//return the node (presumably the smallest child of the subtree of the node you pass into the function)
}


BST::Node* BST::deleteNode(Node*& root, int key) {
	if (root == nullptr) return root; //base case

	if (key > root->data) {								//if the key is greater than the current node's data
		root->right = deleteNode(root->right, key);	//recurse to the right
	}
	else if (key < root->data) {						//if the key is less than the current node's data
		root->left = deleteNode(root->left, key);		//recurse down the left
	}
	else {

		if (root->instanceCount > 1) {	//if the node has an instance count above 0, just remove 1 from the instance count
			root->instanceCount--;
			return root;
		}
		else if (root->left == nullptr && root->right == nullptr) {	//if the node had no children, just delete and return a nullptr to replace it
			
			delete root;
			return nullptr;
		}
		else if (root->left != nullptr && root->right == nullptr)	//if the current node has only a left child
		{
			Node* temp = root->left;						//create a copy of the child
			delete root;									//delete the current node
			return temp;									//return the copy of the child to replace the deleted node
		}
		else if (root->left == nullptr && root->right != nullptr) {	//if the current node only has a right child
			Node* temp = root->right;						//create a copy of the right child
			delete root;									//delete the current node
			return temp;									//return the copy of the child to replace the deleted node
		}
		else if (root->left != nullptr && root->right != nullptr) {	//if the current node has two children
			Node* temp = minValueNode(root->right);				//get the inOrder successor (pass in the right child, then recurse all the way down to the left)
			root->data = temp->data;								//copy the data of the successor into the current node, essentially replacing it
			root->instanceCount = temp->instanceCount;				//copying data...

			temp->instanceCount = 0;								//set the successor's count to zero just to be sure it gets deleted

			root->right = deleteNode(root->right, temp->data);	//now, recurse down to the successor and delete it.
		}

	}
	return root;
}

void BST::removeSubTree(Node* node) {		//use this function to delete entire subtrees. Pass in root to delete entire tree;
	if (node != nullptr) {
		if (node->left != nullptr) {
			removeSubTree(node->left);
		}
		if (node != nullptr) {
			if (node->right != nullptr) {
				removeSubTree(node->right);
			}
		}
		std::cout << "Deleting the node that contained the key " << node->data << std::endl;
		delete node;
	}
	
}



	