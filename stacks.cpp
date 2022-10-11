//Evan Carroll
//CIS-277 Data Structures and Algorithms
//Prof. Aljamal
//Stacks Project
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
//declaring constant variables
const int SIZE = 10;
//structure definitions
//Inforec structure
struct Inforec
{
	int number; //number of records
};
//Stack structure
struct Stack
{
	Inforec i[SIZE]; //size of records of type Inforec
	int top; //top of the stack
};
//function prototypes
void create_stack(Stack &); //function prototype for creating a stack
int empty(Stack &); //function prototype for checking to see if the stack is empty
int top(Stack &); //function prototype for returning the element on the top of the stack
void pop(Stack &, Inforec &); //function prototype for popping the top element off the stack
void push(Stack &); //function prototype for pushing a new element onto the stack
void purge(Stack &); //function prototype for purging the stack of all of it's elements
//main function
int main()
{
	Stack stck; //creating stack variable
	int choiceS, choice1, choice2; //creating choice variables
	Inforec count = -1; //creating the variable that points to which record we are on in the stack and initializing it to -1 so when we push an element onto the stack it gets put on element 0, which is the first number in the inforec array
	//starting the menu
	cout << setw(10) << "Are you excited to see some stacktastic stack manipulations?" << endl;
	cin >> choice1; //the user can input anything and it will go to the next part of the program, just a little joke if anything
	do
	{
		cout << setw(10) << "Excellent! Lets get started!" << endl; 
		do //do while input verification loop
		{
			cout << setw(10) << "1 to create a stack, 2 to push an element onto the stack, 3 to pop an element off the stack, 4 to completely annihilate the stack, and 5 to see the top of the stack." << endl; //letting the user know what their options are
			cin >> choice1; //inputting user choice
			if((choice1 != 1 && choice1 != 2) && ((choice1 != 3 && choice1 != 4) && choice1 != 5)) //if statement to check if the user put in a number between 1-5
				cout << setw(10) << "I know it isn't that exciting, but you must choose a number between 1-5." << endl; //message letting user know that they must choose a number between 1-5
		}while((choice1 != 1 && choice1 != 2) && ((choice1 != 3 && choice1 != 4) && choice1 != 5)); //while loop to make sure the user put in a number between 1-5
		switch(choice1) //starting a switch case based on what the user chooses
		{
			case 1 : //case for creating the stack
				create_stack(stck); //calling the stack function to create the stack
				break; //breaking from the create stack case
			case 2 : //case for pushing an element onto the stack
				if(count < 9) //Checking to see if the stack is full
				{
					push(stck); //calling the stack function to push an element onto the stack
					break; //breaking from the push element case
				}
				else //sends this message to output if the stack is full
				{
					cout << "Stack overflow, pop an element or purge the stack before trying to add a new element." << endl; //message to output
					break; //breaking from this case
				}
			case 3 : //case for popping an element off of the stack
				if(count > -1) //If statement to check to see if there are any elements on the stack
				{
					pop(stck, count); //Calling the pop function to take the element off of the top of the stack
					break; //Breaking from the pop element case
				}
				else //if the stack has no elements on it this message displays to output
				{
					cout << "Stack underflow, push an element onto the stack before trying to remove any elements." << endl; //Message to output
					break; //Breaking from this case
				}
			case 4 : //Case for purging the stack
				purge(stck); //The stack is gone... it will never be seen again...
				break; //breaking from the purge stack case
			case 5 : //Case for looking at the top element of the stack
				if(count == -1) //Checking to see if the stack was made
				{
					cout << "Excuuuuuusssseeee me. But you must actually create the stack in order to see the top element." << endl;
					break;
				}
		}
		cout << setw(10) << "If you want to exit enter 0, and if you want to start again enter 1." << endl;
		cin >> choice2;
	}while(choice2 == 1);
	return 0; //ending program
}
//function definitions
void create_stack(Stack &s) //function defintion for creating the stack
{
	s.top = -1; //when creating the stack the intial top is at -1
	cout << "How exciting, your stack has been created." << endl; //Little bit of output confirming that your stack has been created
}
void push(Stack &s) //function definition for putting an element onto the stack
{
	int val; //creating a variable to store the user input of what value they want to add to the stack
	cout << "What number do you want to put onto the stack?" << endl; //Message letting the user know that they can enter a number onto the stack
	cin >> val; //User input of that element
	s.i[s.top] = val; //Assigning the top element of the stack the value the user inputted
}
void pop(Stack &s, Inforec item) //function definition for popping an element off of the stack
{
	item.number = s.i[s.top--]; //The total number of items in the info record is decremented by 1 by setting it equal to the stack and decrementing the array within the stack by 1
}
int top(Stack s&) //function definition for seeing the top of the stack
{
	cout << "The top of the stack is: " << s.i[0] << endl; //Message displaying what the top element of the stack is
}
void purge(Stack &s) //Function definition for purging the stack of all of its elements
{
	while(s.i != -1) //While loop to check if the index of the stack is at -1 yet, if it isn't the element on the top of the stack is popped
		pop(&s, item); //Popping each element if it isn't equal to -1
	if(s.i == -1)//If the stack is empty, a message to output will be displayed
		cout << "The stack is empty." << endl; //Informing the user that the stack is empty.
}
