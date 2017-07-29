/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                               *
 * Author: Jonathan Pennington                                   *
 *                                                               *
 * A simple program that reverses a linked list using pointers.  *
 *                                                               *
 * Implemented in C                                              *
 *                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>

#define LIST_MEM  600
#define LIST_SIZE 200

// Just a sample struct with an int to prove it works
struct linkedList {
	int number;
	struct linkedList * next;
};

int main(int argc, char ** argv) {

	// We will use all these pointers to point to various parts of the list
	struct linkedList *list = malloc(LIST_MEM);
	struct linkedList *beginningList=list;
	struct linkedList *currentNode;
	struct linkedList *reverseList;
	struct linkedList *beginningReverse;
	struct linkedList *previousNode;
	int numberofNodes = 0;
	int i=0;

	// Populate the linked list. No cheating with arrays
	for (i = 0; i < LIST_SIZE; i++) {
	    currentNode = list;
	    currentNode->number = i;
	    list += sizeof(struct linkedList);
	    if (i < LIST_SIZE-1) currentNode->next = list;
	}

	currentNode = beginningList;

	// Print out the list to prove it works
	while (currentNode != 0x0) {
		printf("%d\n",currentNode->number);
		currentNode = currentNode->next;
	}

	currentNode=beginningList;
	previousNode=beginningList;

	// Now we find the last node, keeping track of its previous
	while(currentNode->next!=0x0){
		previousNode=currentNode;
		currentNode=currentNode->next;
		numberofNodes++;
	}

	// Set up the first node in reverseList
	reverseList=currentNode;
	beginningReverse=currentNode;
	reverseList->next=previousNode;
	reverseList=reverseList->next;
	currentNode=beginningList;
	numberofNodes--;

	// Continue going to the end of the linked list and adding
	// the last node to the reversed list until there are no more
	// Appears to be in O(n!)...very inefficient
	while(numberofNodes!=0){
		for(i=0;i<numberofNodes-1;i++){
			currentNode = currentNode->next;
		}
		reverseList->next=currentNode;
		reverseList=reverseList->next;
		currentNode=beginningList;
		numberofNodes--;
	}

	// Set the last node to a null address space
	reverseList->next=0x0;

	// Print out the results to prove it works
	reverseList=beginningReverse;
	while(reverseList!=0x0){
		printf("%d\n",reverseList->number);
		reverseList=reverseList->next;
	}

	return 0;
}
