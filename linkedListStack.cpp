//Evan Carroll
//CIS-277 Data Structures and Algorithms
//Prof. Aljamal
//11/15/2019
//Stack Implementation of Linked Lists
//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;
//Defining Structures and User Defined Types
struct Node; //Declaring the Node structure so I can delcare a type.
typedef Node *PT_NODE; //Declaring a type of node that strictly points to the next node.
struct Node{ //Fleshing out the Node structure.
	string name; //Declaring the name of the node.
	int age; //Declaring the age of the person.
	float height; //Declaring the height of the person.
	PT_NODE next; //Declaring the pointer to the next node.
};
typedef PT_NODE Stack; //Declaring the Stack linked list.
//Function Prototypes
void create_stack(Stack &); //Function Prototype for creating the stack.
bool is_empty(Stack); //Function prototype for checking if the stack is empty.
void push(Stack &); //Function prototype for pushing a new node onto the stack.
void pop(Stack &); //Function prototype for popping a node from the stack.
void purge(Stack &); //Function prototype for purging the stack of it's nodes.
void top(Stack &); //Function prototype for seeing the top node of the stack.
void display_nodes(Stack &); //Function prototype for displaying all of the nodes in the stack.
//Main function
int main()
{
	Stack s; //Declaring a Stack variable.
	bool done = false; //Declaring a variable to determine when the user wants to quit the program.
	int choice; //Declaring a variable to store the user choice of operations for the program.
	bool empty = false; //Declaring a variable to store if the stack is empty or not.
	while(!done) //While loop to display the options of operations.
	{
		//Menu of program
		cout << setw(10) << "Welcome to the Stack Linked List Implementation fun, where we have fun with the linked list implementation of a stack." << endl; //Welcoming the user to the program.
		cout << setw(10) << "Enter 1 to create the stack." << endl;
		cout << setw(10) << "Enter 2 to check if the stack is empty." << endl;
		cout << setw(10) << "Enter 3 to push a node onto the stack." << endl;
		cout << setw(10) << "Enter 4 to pop a node off of the stack." << endl;
		cout << setw(10) << "Enter 5 to purge the stack of all of it's nodes." << endl;
		cout << setw(10) << "Enter 6 to see the top node of the stack." << endl;
		cout << setw(10) << "Enter 7 to display the entire stack." << endl;
		cout << setw(10) << "Enter 8 to close the program." << endl;
		cin >> choice; //User inputs their choice of what they want to do with the program.
		switch(choice) //Switch case based off of the user's choice.
		{
			case 1 : //Case for creating the stack.
				create_stack(s); //Calling the create_stack function to create a stack.
				cout << setw(10) << "The stack has been created." << endl; //Informing the user that the stack has been created.
				break; //Breaking from the create stack case.
			case 2 : //Case for checking if the stack is empty or not.
				empty = is_empty(s); //The is_empty function is called to check if the stack is empty and the result is stored in the variable empty.
				if(empty == true) //If the stack is empty...
					cout << setw(10) << "The stack is currently empty." << endl; //Informing the user the stack is empty.
				else //If the stack isn't empty...
					cout << setw(10) << "The stack is not empty." << endl; //Informing the user the stack is empty.
				break; //Breaking from the is empty case.
			case 3 : //Case for pushing a node onto the stack.
				push(s); //Calling the push function to push a node on Stack s.
				break; //Breaking from the push case.
			case 4 : //Case for popping an element from the stack.
				empty = is_empty(s); //Calling the is_empty function to determine if the stack is empty before trying to pop a node from it.
				if(empty == false) //If the stack is not empty...
					pop(s); //Popping the top node from the stack.
				else //If the stack is empty...
					cout << setw(10) << "The stack is currently empty. We cannot pop off a node or else it will cause a Stack Underflow." << endl; //Letting the user know the stack is empty so we cannot pop an element off.
				break; //Breaking from the pop node case.
			case 5 : //Case for purging the entire stack of all of it's nodes.
				empty = is_empty(s); //Calling the is_empty function to determine if the stack is empty before trying to purge it.
				if(empty == false) //If the stack is not empty...
					purge(s); //Purging the stack of its nodes.
				else //If the stack is empty...
					cout << setw(10) << "The stack is currently empty. We cannot purge the stack of nodes or else it will cause a Stack Underflow." << endl; //Letting the user know the stack is empty so we cannot purge.
				break; //Breaking from the purge case.
			case 6 : //Case for seeing the top node of the Stack.
				top(s); //Calling the top function to show the top node of the function.
				break; //Breaking from the top case.
			case 7 : //Case for displaying the entire stack.
				display_nodes(s); //Calling the display_nodes function to display all of the nodes in Stack s.
				break; //Breaking from the display case.
			case 8 : //Case for exitting the program.
				done = true; //The user is donezo.
				break; //Breaking from the program.
			default : //Case for whenever the user enters an option that isn't actually an option.
				cout << setw(10) << "Pretty please with sugar on top enter valid input." << endl; //Informing the user that they have to put in correct input.
				break; //Breaking from the default case.
		}
	}
	return 0; //Ending program.
}
//Function Definitions
//create_stack Function Definition
void create_stack(Stack &S) //create_stack takes a Stack Node as input and creates the first node.
{
	S = NULL; //The stack is created but since there are no entries in it, the initial node is NULL.
}
//is_empty Function Definition
bool is_empty(Stack S) //The is_empty function checks if a created stack is empty and returns a value to determine if it is empty.
{
	bool empt; //Declaring a variable to store whether the Stack is empty.
	if(S == NULL) //If S is NULL...
		empt = true; //Then the stack is empty so empty is set to true.
	else //If S has data...
		empt = false; //Then the stack has been created and empty is set to false.
	return(empt); //Returns the empty variable = 0 if it is NULL and a 1 if it isn't.
}
//push Function Definition
void push(Stack &S) //The push function pushes a new node to the top of the stack.
{
	PT_NODE temp; //Declaring a temporary node variable.
	temp = new Node; //Creating space in memory for the new Node temp.
	//Input/Output Section
	cout << setw(10) << "What is the name of this person?" << endl; //Asking the user for a name.
	cin >> temp->name; //User input of name.
	cout << setw(10) << "What is the age of this person?" << endl; //Asking the user for an age.
	cin >> temp->age; //User input of age.
	cout << setw(10) << "What is the height of this person?" << endl; //Asking the user for a height.
	cin >> temp->height; //User input of height.
	temp->next = S; //Saying the next node is equal to the initial node.
	S = temp; //The initial pointer is now pointing to the node at the front of the list.
}
//pop Function Definition
void pop(Stack &S) //The pop function removes the top node from the stack.
{
	PT_NODE temp; //Declaring a temporary pointer Node named temp.
	temp = S; //Setting temp equal to the first stack node.
	cout << setw(10) << "The next Node popped was the record of " << S->name << "." << endl; //Letting the user know what node will be popped off next.
	S = S->next; //Setting the node equal to the next node in the stack.
	delete temp; //Deleting the storage space used for the temporary Stack variable.
}
//purge Function Definition
void purge(Stack &S) //The purge function pops every node from the stack.
{
	while(!is_empty(S)) //A while loop to keep repeating the pop function as long as the is_empty function keeps returning full. 
		pop(S); //Popping every node from the Stack.
	cout << setw(10) << "The stack has been successfully purged." << endl; //Informing the user that the stack has been successfully purged.
}
//top Function Definition
void top(Stack &S) //The top function will show the top node of the stack.
{
	PT_NODE top; //Declaring a temporary pointer Node named top meant to be the top node of the stack.
	if(S == NULL) //If the stack is NULL...
		cout << setw(10) << "The stack is currently empty so there is no top node." << endl; //Guess what, the stack is empty.
	else //If the stack has elements...
	{
		top = S; //Assigning the top Node the same value as the first value in the Stack list.
		cout << setw(10) << "The top node of the stack is: " << top->name << ", " << top->age << ", " << top->height << endl; //Output for what the top element of the stack is and what information it holds.
	}
}
//display_nodes Function Definition
void display_nodes(Stack &S) //Displays the top node of the Stack.
{
	PT_NODE temp; //Declaring a temporary pointer Node named temp.
	if(S == NULL) //If the top of the Stack is NULL...
		cout << setw(10) << "The stack is empty." << endl;
	else //If the stack isn't null...
	{
		temp = S; //Assigning the temp variable the same value as the node on top of the Stack.
		cout << setw(10) << "The stack's nodes are: " << endl;
		while(temp != NULL) //While the node isn't NULL...
		{
			cout << setw(10) << temp->name << setw(10) << temp->age << setw(10) << temp->height << endl; //Displaying all the user inputted data for the specific node that the loop is on.
        	temp = temp->next; //Set the temp Node equal to the Node after it.
		}
	}
}
