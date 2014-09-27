#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

//Precondition: Stack is initialized and accessible
//Postcondition: (1) Returns true if brackets match
//				 (2) Returns false if brackets mismatch
bool isMatched(char openBracket, char closedBracket);

int main(int argc, char* argv[])
{
	int i = 0;
	char expression[MAXSTACK];
	StackPtr expressionStack;
	StackData expressionStackData;
	StackData peeked;
	StackData popped;
	bool match;
	bool balanced = true;
	char closedBracket;

	FILE* fp_input;
	char filename[] = "expressions.txt";

	fp_input = fopen(filename, "r");

	if (fp_input == NULL)
	{
		fprintf(stderr, "Could not find file: %s\n", filename);
		exit(1);
	}

	while(fgets(expression, MAXSTACK, fp_input) > 0)
	{
		// initialize the expression stack & ensure emptiness
		expressionStack = initStack();
		empty(expressionStack);
		
		// push each character from the expression into the stack
		for(i = 0; expression[i] != '\n'; i++)
		{
			// if no brackets, assume to be true
			if (isEmpty(expressionStack))
				balanced = true;

			switch(expression[i])
			{
				case '{':
				case '(':
				case '[':
					expressionStackData.ch = expression[i];
					push(expressionStack, expressionStackData);
					//printf("%c pushed to stack\n", expressionStackData.ch);
					break;
				case '}':
				case ')':
				case ']':
					if (isEmpty(expressionStack))
					{
						//printf("Closing bracket on an empty stack: \n");
						balanced = false;
						break;
					}
					else
					{
						closedBracket = expression[i];
						//printf("\nClosedBracket is %c\n", closedBracket);
						peeked = peek(expressionStack);
						match = isMatched(peeked.ch, closedBracket);
						if (!match)
						{
							//printf("Brackets don't match\n");
							balanced = false;
							break;
						}
						else if (match)
						{
							popped = pop(expressionStack);
							//printf("Brackets match, so %c popped from stack\n", popped.ch);
							
							if(!isEmpty(expressionStack))
							{ 
								//printf("stack is still not empty\n");
								balanced = false;
								break;
							}
							else
							{
								//printf("stack is now empty\n");
								balanced = true;
								break;
							}
						}
					}
			}
		}

		if (balanced == false)
			printf("\n%s -----------------------------> INCORRECT.\n", expression);
		
		else if (balanced == true)
			printf("\n%s -----------------------------> CORRECT.\n", expression);

		// destroy the expression stack
		destroyStack(expressionStack);
	}

	return 0;
}

bool isMatched(char openBracket, char closedBracket)
{
	if (openBracket == '{')
	{
		if (closedBracket == '}')
			return true;
	}

	if (openBracket == '(')
	{
		if (closedBracket == ')')
			return true;
	}

	if (openBracket == '[')
	{
		if (closedBracket == ']')
			return true;
	}

	return false;
}

