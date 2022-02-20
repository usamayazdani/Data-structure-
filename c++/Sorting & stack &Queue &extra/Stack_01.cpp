/*A stack is a linear data structure.
Lifo -> last in/first out 
■ clear()—Clear the stack.
■ isEmpty()—Check to see if the stack is empty.
■ push(el)—Put the element el on the top of the stack.
■ pop()—Take the topmost element from the stack.
■ topEl()—Return the topmost element in the stack without removing it.
--------->only for information<--------
delimeters ==== {},[](),// " "
---------------------------------------
-->overflow =If the stack elemnts is full the resulting condition is called overflwow
-->underflow=remove elemts from emtpy stack theresulting condition is called underflow
*/
#include<iostream>
using namespace std;

template <class Type>
class stackADT
{
public:
virtual void initializeStack() = 0;

virtual bool isEmptyStack() const = 0;

virtual bool isFullStack() const = 0;

virtual void push(const Type& newItem) = 0;

virtual Type top() const = 0;

virtual void pop() = 0;

};
template <class Type>
class stackType: public stackADT<Type>
{
public:
const stackType<Type>& operator=(const stackType<Type>&);
void initializeStack();

bool isEmptyStack() const;


bool isFullStack() const;

void push(const Type& newItem);

Type top() const;

void pop();

stackType(int stackSize = 100);

stackType(const stackType<Type>& otherStack);

~stackType();

private:
int maxStackSize; //variable to store the maximum stack size
int stackTop; //variable to point to the top of the stack
Type *list; //pointer to the array that holds the stack elements
void copyStack(const stackType<Type>& otherStack);

};
template <class Type>
void stackType<Type>::initializeStack()
{
stackTop = 0;
}//end initializeStack
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
return(stackTop == 0);
}//end isEmptyStack
template <class Type>
bool stackType<Type>::isFullStack() const
{
return(stackTop == maxStackSize);
} //end isFullStack
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
if (!isFullStack())
{
list[stackTop] = newItem; //add newItem at the top
stackTop++; //increment stackTop
}
else
cout << "Cannot add to a full stack." << endl;
}//end push
// template <class Type>
// Type stackType<Type>::top() const
// {
// assert(stackTop != 0); //if stack is empty, terminate the
// //program
// return list[stackTop - 1]; //return the element of the stack
// //indicated by stackTop - 1
// }//end top
template <class Type>
void stackType<Type>::pop()
{
if (!isEmptyStack())
stackTop--; //decrement stackTop
else
cout << "Cannot remove from an empty stack." << endl;
}//end pop
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
delete [] list;
maxStackSize = otherStack.maxStackSize;
stackTop = otherStack.stackTop;

list = new Type[maxStackSize];
//copy otherStack into this stack
for (int j = 0; j < stackTop; j++)
list[j] = otherStack.list[j];
} //end copyStack
template<class Type>
stackType<Type>::stackType(int stackSize)
{
if (stackSize <= 0)
{
cout << "Size of the array to hold the stack must "
<< "be positive." << endl;
cout << "Creating an array of size 100." << endl;
maxStackSize = 100;
}
else
maxStackSize = stackSize; //set the stack size to

stackTop = 0; //set stackTop to 0
list = new Type[maxStackSize]; //create the array to
}//end constructor
template <class Type>
stackType<Type>::~stackType() //destructor
{
delete [] list; //deallocate the memory occupied
}//end destructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
list = NULL;
copyStack(otherStack);
}//end copy constructor
template <class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack)
{
if (this != &otherStack) //avoid self-copy
copyStack(otherStack);
return *this;
} //end operator=


int main(){
stackType<int> obj;
obj.initializeStack();
obj.isEmptyStack();
obj.isFullStack();

obj.push(44);

obj.push(23);
obj.pop();
return 0;
}