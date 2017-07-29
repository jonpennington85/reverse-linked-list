#include <stdio.h>
#include <stdlib.h>

struct linkedList {
	int number;
	struct linkedList * next;
};

int main(int argc, char ** argv) {

	struct linkedList *list = malloc(600);
	struct linkedList *beginningList=list;
	struct linkedList *currentNode;
	struct linkedList *reverseList;
	struct linkedList *beginningReverse;
	struct linkedList *previousNode;
	int numberofNodes = 0;
	int i=0;

	for (i = 0; i < 2000; i++) {
	    currentNode = list;
	    currentNode->number = i;
	    list += sizeof(struct linkedList);
	    if (i < 1999) currentNode->next = list;
	}

	currentNode = beginningList;

	while (currentNode != 0x0) {
	printf("%d\n",currentNode->number);
		currentNode = currentNode->next;
	}

	currentNode=beginningList;

	previousNode=currentNode;

	while(currentNode->next!=0x0){
		previousNode=currentNode;
		currentNode=currentNode->next;
		numberofNodes++;
	}

	reverseList=currentNode;
	beginningReverse=currentNode;
	reverseList->next=previousNode;
	reverseList=reverseList->next;
	currentNode=beginningList;
	numberofNodes--;

	while(numberofNodes!=0){
		for(i=0;i<numberofNodes-1;i++){
			currentNode = currentNode->next;
		}
		reverseList->next=currentNode;
		reverseList=reverseList->next;
		currentNode=beginningList;
		numberofNodes--;
	}

	reverseList->next=0x0;

	reverseList=beginningReverse;
	while(reverseList!=0x0){
		printf("%d\n",reverseList->number);
		reverseList=reverseList->next;
	}

	return 0;
}
