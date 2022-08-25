// CodingExamples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BST.h"
#include "BHeap.h"


int main()
{
    std::cout << "Hello World!\n";


    BST* bst = new BST();
    
   
    std::cout << "before inserts\n" << bst->root << std::endl;
   
    
    bst->Insert(bst->root, 8);
    bst->Insert(bst->root, 3);
    bst->Insert(bst->root, 10);
    bst->Insert(bst->root, 1);
    bst->Insert(bst->root, 6);
    bst->Insert(bst->root, 14);
    bst->Insert(bst->root, 4);
    bst->Insert(bst->root, 7);
    bst->Insert(bst->root, 13);


   
   std::cout << "In order traversal\n";
   bst->inOrder(bst->root);
   std::cout << "Pre order traversal\n";
   bst->preOrder(bst->root);
   std::cout << "Post order traversal\n";
   bst->postOrder(bst->root);
   std::cout << "Deleting the node that contains 4 (has no children).\n";
   bst->deleteNode(bst->root, 4);
   std::cout << "Post Deletion\n";
   bst->inOrder(bst->root);
   std::cout << "now deleting 3 (has 2 children)\n";
   bst->deleteNode(bst->root, 3);
   std::cout << "post deletion\n";
   bst->inOrder(bst->root);
   std::cout << "Now deleting 14 (has one child)\n";
   bst->deleteNode(bst->root, 14);
   bst->inOrder(bst->root);

   delete bst;

   std::cout << "post tree deletion";
   
   std::cout << "=========================\n";
   
   BHeap bheap;

   bheap.push(3);
   bheap.push(2);
   bheap.push(15);

   std::cout << "Size of heap is: " << bheap.heapSize() << std::endl;

   std::cout << bheap.top() << " ";
   bheap.pop();

   std::cout << bheap.top() << " ";
   bheap.pop();

   std::cout << bheap.top() << " ";
   bheap.pop();

   std::cout << std::endl << std::boolalpha << bheap.isEmpty();

   bheap.top();
   bheap.top();
    return 0;
}

