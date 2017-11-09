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
	struct linkedList *nodeList[LIST_SIZE];
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

	// Now we make an array of every node address
	while(currentNode->next!=0x0){
		nodeList[numberofNodes++]=currentNode;
		currentNode=currentNode->next;
	}

    // Set the beginning of the reverse order to the address of the last node
	beginningReverse=currentNode;
	reverseList=beginningReverse;

    // Reverse the order by moving backwards through the array
	for(i=numberofNodes;i>=0;i--){
		reverseList->next=nodeList[i-1];
		reverseList=reverseList->next;
	}

	// Print out the results to prove it works
	reverseList=beginningReverse;
	while(reverseList>0x100000000){
		printf("%d\n",reverseList->number);
		reverseList=reverseList->next;
	}

	return 0;
}
