//This code is not working , I couldn't debug it at the given time

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


void add();
void check();

int isEmpty();

void push(char);
void pop();
void display();

string STRING, STRING2; // global

struct Node { // node
	char data;
	struct Node* next;
};
struct Node* top;

int main()
{
	int menu = 1;
	int decision;

	while (menu)
	{
		cout << "1_Add,2_Check,3_List,4_Exit" << endl;
		cout << "Please enter your decision" << endl;
		cin >> decision;
		switch (decision)
		{
		case 1:
			add();
			system("pause");
			break;
		case 2:
			check();
			break;
		case 3:
			display();
			break;
		case 4:
			cout << " Thanks for using" << endl;
			system("pause");
			menu = 0;
			break;
		}
	}
	return 0;
}

void add() {
	int i;
	int m;
	cout << "Please enter a string only includes only 'a' and 'b'" << endl;
	cin >> STRING;
	for (i = 0; STRING[i] == STRING[i + 1]; i++) //push the character and i++ until character changes
	{
		push(STRING[i]);
	}
	for (m = 0; STRING[i + 1] != '\0'; i++) // read the second character string in STRING2
	{
		STRING2[m] = STRING[i + 1];
		m++;
	}
}
void check() {
	int len = (STRING2.size() - 1); // -1 because at the end of the string there is'\0'
	int i;
	int x, y;
	cout << "Please enter the coefficents of a and b(first a then b)" << endl;
	cin >> x >> y;
	display();
	while (!isEmpty() || STRING2[0]) // stack is not empty,string2 is not empty so keep working.One of them is empty and one of them is not means quit with failure
	{
		for (i = 0; i < x; i++) //pop from stack x times
		{
			pop();
			display();
		}
		for (i = 0; i < y; i++) //delete from second string y times
		{
			STRING2[len] = '\0'; //delete the last element
			len--; //decrement the length
		}
		if (!isEmpty())
		{
			if (STRING2[0] == '\0') // if string is empty
			{
				cout << "This expression is organized" << endl; // stack is empty, string2 is empty ,quit with success
			}

		}
		else cout << "This expression is not organized" << endl;
	}
}

int isEmpty()
{
	return top == NULL;
}

void push(char data)
{
	// create new node temp and allocate memory 
	struct Node* temp;
	temp = new Node();

	// check if stack (heap) is full. Then inserting an element would 
	// lead to stack overflow 
	if (!temp) {
		cout << "\nHeap Overflow";
		exit(1);
	}

	// initialize data into temp data field 
	temp->data = data;

	// put top pointer reference into temp link 
	temp->next = top;

	// make temp as top of Stack 
	top = temp;
}

void pop()
{
	struct Node* temp;

	// check for stack underflow 
	if (top == NULL) {
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else {
		// top assign into temp 
		temp = top;

		// assign second node to top 
		top = top->next;

		// destroy connection between first and second 
		temp->next = NULL;

		// release memory of top node 
		free(temp);
	}
}

// Function to print all the  
// elements of the stack  
void display()
{
	struct Node* temp;

	// check for stack underflow 
	if (top == NULL) {
		cout << "\nStack Underflow";
		exit(1);
	}
	else {
		temp = top;
		while (temp != NULL) {

			// print node data 
			cout << temp->data << " ";

			// assign temp link to temp 
			temp = temp->next;
		}
	}
}
