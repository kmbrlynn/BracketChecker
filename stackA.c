#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

StackPtr initStack(void)
{
	StackPtr sp = (StackPtr)malloc(sizeof(StackType));
	sp-> top = -1; //Because 1st index will be 0
	return sp;
}

bool isEmpty(StackPtr S)
{
	if(S-> top == -1)
		return true;
	else
		return false;
}

void push(StackPtr S, StackData n)
{
	if(S-> top == MAXSTACK-1) // keep in bounds
	{
		fprintf(stderr, "Stack overflow!\n");
		exit(1);
	}
	++(S-> top); //push a space to the top
	S-> array[S-> top] = n; //fill that space with n passed
}

StackData peek(StackPtr S)
{
	StackData peekedDataHolder;
	peekedDataHolder = S-> array[S-> top];
	return peekedDataHolder;
}

StackData pop(StackPtr S)
{
	StackData poppedDataHolder;
	if(isEmpty(S))
	{
		fprintf(stderr, "Stack is already empty!\n");
		exit(1);
	}	
	poppedDataHolder = S-> array[S-> top]; //save the data that is stored
										   // in element about to be popped
	--(S-> top); //pop space off the top
	return poppedDataHolder; //return the saved data
}	

void empty(StackPtr S)
{
	StackData dummyData;

	if(isEmpty(S))
	{
		//printf("Stack is already empty!\n");
		return;
	}
	else
	{
		while(S-> top > -1)
		{
			dummyData = pop(S);
		}
		return;
	}
}

void destroyStack(StackPtr S)
{
	if(!isEmpty(S))
	{
		empty(S);
	}

	free(S);

	return;
}





