//Evan Carroll
//CIS-277 Data Structures and Algorithms
//Prof. Aljamal
//11/15/2019
//Queue Implementation of Linked Lists
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
struct Queue{ //Declaring the queue structure.
	PT_NODE front; //Declaring the front pointer node.
	PT_NODE back; //Declaring the back pointer node.
};
//Function prototypes
void create_queue(Queue &); //Function prototype for create_queue.
bool are_empty(Queue); //Function prototype for are_empty.
void enqueue(Queue &); //Function prototype for enqueue.
void dequeue(Queue &); //Function prototype for dequeue.
void purge_queue(Queue &); //Function prototype for purge_queue.
void display_queue(Queue &); //Function prototype for display_queue.
//Main Function
int main()
{
	Queue q; //Declaring a Queue variable q.
	bool done = false;  //Declaring a variable to determine when the user wants to quit the program.
	int choice; //Declaring a variable to store the user choice of operations for the program.
	bool empty = false; //Declaring a variable to store if the queue is empty or not.
	while(!done) //While loop to display the options of operations until the user enters the number 7.
	{
		//Output section
		cout << setw(10) << "Hello! Welcome to queue linked List Implementation version.this!" << endl;
		cout << setw(10) << "Enter 1 to create the queue." << endl;
		cout << setw(10) << "Enter 2 to check if the queue is empty." << endl;
		cout << setw(10) << "Enter 3 to add a node to the queue." << endl;
		cout << setw(10) << "Enter 4 to remove a node from the queue." << endl;
		cout << setw(10) << "Enter 5 to purge the queue of it's nodes." << endl;
		cout << setw(10) << "Enter 6 to display all of the nodes in the queue." << endl;
		cout << setw(10) << "Enter 7 to exit the program." << endl;
		cin >> choice; //User input of choice.
		switch(choice) //Switch case based on the user's choice.
		{
			case 1 : //Case for creating the queue.
				create_queue(q); //Calling the function create_queue to create the queue.
				cout << setw(10) << "HOW INSANE. YOU. JUST. CREATED. THE. QUEUE." << endl; //Informing the user that they created the queue.
				break; //Breaking from the create queue case.
			case 2 : //Case for checking whether the queue is empty or not.
				empty = are_empty(q); //Calling the empty function to determine whether the queue is empty or not and storing it in the variable empty.
				if(empty == true) //If the queue is empty...
					cout << setw(10) << "Sadly, the queue is currently empty." << endl; //...we inform the user.
				else //If the queue isn't empty...
					cout << setw(10) << "WILD. The queue is not empty!" << endl; //...we inform the user.
				break; //Breaking from the empty queue case.
			case 3 : //Case for adding a new node to the queue.
				enqueue(q); //Calling the enqueue function to add a node to the queue.
				break; //Breaking from the enqueue case.
			case 4 : //Case for removing a node from the queue.
				empty = are_empty(q); //Calling the are_empty function to check if the queue is empty and storing the result in the empty variable.
				if(empty == false) //If the queue is empty an item is dequeued from the front of the queue.
					dequeue(q); //Calling the dequeue function to remove a node from the queue.
				else //When the queue IS empty we get this HOT message.
					cout << setw(10) << "Oh no the queue is empty, you should probably add some elements before trying to dequeue. It will cause an underflow." << endl; //Output.
				break; //Breaking from the dequeue case.
			case 5 : //Case for purging the queue.
				empty = are_empty(q); //Calling the are_empty function to check if the queue is empty and storing the result in the empty variable.
				if(empty == false) //If the queue is not empty...
					purge_queue(q); //Calling the purge_queue function to remove all the nodes from the queue.
				else //If the queue is empty
					cout << setw(10) << "The queue is empty and cannot be purged or else it will cause a queue underflow." << endl;
				break; //Breaking from the purge queue case.
			case 6 : //Case for displaying the queue.
				display_queue(q); //Calling the display_queue function to display the queue.
				break; //Breaking from the display queue case.
			case 7 : //Case for exiting the program
				done = true; //Done is set to true and the while loop ends, thus ending the program.
				break; //Breaking from the exit case.
			default : //Clarifying what happens when you put in wrong input.
				cout << setw(10) << "Please enter one of those choices. " << endl;
				break; //Breaking from default.
		}
	}
	return 0; //Ending program
}
//Function Definitions
//create_queue Function Definition
void create_queue(Queue &Q) //The create_queue function creates the list of the queue.
{
	Q.back = Q.front = NULL; //Setting both the front and back pointers to NULL.
}
//are_empty Function Definition
bool are_empty(Queue Q) //The are_empty function checks if the queue is currently empty.
{
	bool empt;
	if(Q.front == NULL) //If the queue is empty...
		empt = true; //Then the empt variable is set to true because the queue is empty.
	else //If the queue has nodes...
		empt = false; //Then the empt variable is set to false because the queue has nodes.
	return(empt); //Returning the result of whether the queue is empty or not back to the main.
}
//enqueue Function Definition
void enqueue(Queue &Q) //The enqueue function adds a new node to wherever the back pointer is in the list.
{
	PT_NODE temp = new Node; //Declaring a temporary Node variable called temp and making the necessary room for the Node.
	//Input/Output Section
	cout << setw(10) << "What is the name of the person in question?" << endl;
	cin >> temp->name;
	cout << setw(10) << "This may be rude, but what is the age of the person?" << endl;
	cin >> temp->age;
	cout << setw(10) << "What is the height of the person?" << endl;
	cin >> temp->height;
	temp->next = NULL; //Saying the next node in the queue is now NULL.
	if(Q.front == NULL) //If the front of the queue is actually the end of the list...
		Q.front = temp; //Then the front of the queue is now the node that was the template.
	else //If the back of the queue is actually the end of the list...
	{
		Q.back = Q.front; //Setting the back of the queue equal to what the front node of the queue.
		while(Q.back->next != NULL) //As long as the node behind the back pointer isn't NULL, this while loop will continue.
			Q.back = Q.back->next; //The new back will be the node before the NULL node.
		Q.back->next = temp; //The temp node is now the new node at the end of the queue.
	}
}
//dequeue Function Definition
void dequeue(Queue &Q) //The dequeue function removes a node from the front of the queue.
{
	PT_NODE temp; //Declaring a temporary Node variable called temp.
	temp = Q.front; //The temp variable is now assigned the value of the front of the queue.
	cout << setw(10) << "The person taken out from the queue was: " << temp->name << endl; //Letting the user know who was removed from the records.
	Q.front = Q.front->next; //The front node is moved to the next node.
	delete temp; //Removing the temp node from the front of the queue.
}
//purge_queue Function Definition
void purge_queue(Queue &Q) //The purge_queue function removes all the nodes in the queue.
{
	PT_NODE temp; //Declaring a temporary Node variable named temp.
	while(Q.front != NULL) //While the queue is not empty...
	{
		temp = Q.front; //Set the temp variable equal to the node in the front.
		Q.front = Q.front->next; //The node in the front is moved to the node next to it.
		delete temp; //The original node in the front is deleted.
	}
	cout << setw(10) << "The queue has been successfully purged." << endl; //Informing the user that the queue has been purged.
}
//display_queue Function Definition
void display_queue(Queue &Q) //The display_queue function displays all the current nodes in the queue.
{
	PT_NODE temp; //Declaring a temporary Node variable called temp.
	temp = Q.front; //temp is equal to the front of the queue.
	if((Q.front == NULL) && (Q.back == NULL)) //Checking to see if the queue has no elements.
		cout << setw(10) << "The queue is currently empty." << endl; //We let the user know the queue is empty and we don't attempt to display the queue.
	else //If the queue has elements...
	{
		cout << setw(10) << "The queue's nodes are: " << endl;
		while(temp != NULL) //While the next node in the queue isn't NULL...
		{
			cout << setw(10) << temp->name << setw(10) << temp->age << setw(10) << temp->height << endl; //Each record of the queue is printed.
			temp = temp->next; //The temp variable is moved to the next node.
		}
	}
}
