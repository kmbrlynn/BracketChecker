#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(int argc, char* argv[])
{
	StackData n;
	StackData peeked;
	char answer = 'n';
	StackData popped;
	StackPtr S = initStack();

	printf("\n----------- Testing isEmpty() Function -----------\n");
	printf("\nTest if stack is empty? (y/n): ");
	scanf(" %c", &answer);
	
	if(answer == 'y')
	{
		if(isEmpty(S))
			printf("The stack is empty.\n");
		else
			printf("The stack is not empty.\n");

	}

	printf("\n----------- Testing push() Function -----------\n");
	printf("\nEnter up to 50 characters. Hit Q when you are done.\n\n");
	scanf(" %c", &n.ch);

	while(n.ch != 'Q')
	{
		push(S, n);
		printf("\t%c added to the stack.\n", n.ch);
		scanf(" %c", &n.ch);
	}

	printf("\n----------- Testing isEmpty() Function -----------\n");
	printf("\nTest if stack is empty? (y/n): ");
	scanf(" %c", &answer);
	
	if(answer == 'y')
	{
		if(isEmpty(S))
			printf("The stack is empty.\n");
		else
			printf("The stack is not empty.\n");

	}

	printf("\n----------- Testing peek() Function -----------\n");
	printf("\nPeek at the top element of the stack? (y/n): ");
	scanf(" %c", &answer);
	
	if(answer == 'y')
	{
		peeked = peek(S);
		printf("The top element of the stack contains: %c\n", peeked.ch);
	}

	printf("\n----------- Testing pop() Function -----------\n\n");
	while(!isEmpty(S))
	{	
		popped = pop(S);
		printf("Popped %c from the stack.\n", popped.ch);
	}

	printf("\n----------- Testing isEmpty() Function -----------\n");
	printf("\nTest if stack is empty? (y/n): ");
	scanf(" %c", &answer);
	
	if(answer == 'y')
	{
		if(isEmpty(S))
			printf("The stack is empty.\n");
		else
			printf("The stack is not empty.\n");

	}

	printf("\n----------- Testing empty() Function -----------\n");
	printf("\nDo you wish to empty the stack?? (y/n): ");
	scanf(" %c", &answer);
	
	if(answer == 'y')
	{
		empty(S);
	}

	destroyStack(S);

	return 0;
}