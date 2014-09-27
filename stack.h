
#define MAXSTACK 50
#define ROGUEVALUE -9999

// Define a type
typedef struct stackData
{
	char ch;
	int num;
} StackData;

// Define structs for StackType 
// and pointer to StackType (aka StackPtr)
typedef struct stack
{
	int top;
	StackData array[MAXSTACK];
} StackType, *StackPtr;

//Precondition: None
//Postcondition: A stack is initialized and accessible
StackPtr initStack(void);

//Precondition: A stack is initialized and accessible
//Postcondition: Returns if a stack is empty
bool isEmpty(StackPtr S);

//Precondition: A stack is initialized and accessible
//Postcondition: An item is pushed to the top of the stack
void push(StackPtr S, StackData n);

//Precondition: A stack is initialized and accessible
//Postcondition: Returns the data stored at an index
StackData peek(StackPtr S);

//Precondition: A stack is initialized and accessible
//Postcondition: An item is popped off the top of the stack
StackData pop(StackPtr S);

//Precondition: A stack is initialized and accessible
//Postcondition: The stack is emptied
void empty(StackPtr S);

//Precondition: A stack is initialized and accessible
//Postcondition: The stack is destroyed
void destroyStack(StackPtr S);