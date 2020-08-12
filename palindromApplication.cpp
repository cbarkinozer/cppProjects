//I couldn't make this code work unfortunately
/*
Application includes queue and stack data structure by double linked list implementation In every node character value will be stored in this format (‘a’,'b’,’1’,’2')

Adding:Data's will be read from file and add by the logic of queue using double linked list implementation Check: In the linked list, values will be check if they are equal starting from the head and if they are equal they will be delete from linked list.At the end if there is a single or no element in the linked list warn the user by "this expression is palindrome" if not warn the user by printing "this expression is not palindrom".

example ifade-1: abcdcba 1. adım: bcdcb 2. adım: cdc 3. adım: d Tek elaman var, dolayısıyla palindromdur edit: if the expression is not palindrom the first element will be delete automaticly and add the last elements value
*/
Listing:print by the queue structure
#include<iostream> //input output
#include<cstdlib> // standart library
#include<fstream> // for file operations
#include<string>

using namespace std;



class QNode { //node
public:
	char data;
	QNode* next;
	QNode* prev;
};

class Queue { // head and rear
public:
	QNode* head;
	QNode* rear;
};

QNode* newNode(char k) // creating a new node
{
	QNode* temp = new QNode();
	temp->data = k;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

Queue* createQueue() // creating queue
{
	Queue* q = new Queue();
	q->head = NULL;
	q->rear = NULL;
	return q;
}

//predefined functions
void add(Queue* q, char k);
void edit(Queue* q);
void list(Queue* q);
int check(Queue* q);
void deleteHead(Queue* q);
void deleteRear(Queue* q);

int main()
{
	int menu = 1;
	int decision;

	Queue* q = createQueue();

	string STRING;
	ifstream infile;
	infile.open("string.txt"); // opening the file

	while (!infile.eof) // To get you all the lines.
	{
		getline(infile, STRING); // Saves the line in STRING.

	}
	infile.close(); //closing the file

	while (menu)
	{
		cout << "1_Add,2_Check,3_Edit,4_List,5_Exit" << endl;
		cout << "Please enter your decision" << endl;
		cin >> decision;
		switch (decision)
		{
		case 1:

			for (int i = 0; i < STRING.size(); i++) { // add string's characters to the queue
				add(q, STRING[i]);
			}

			system("pause");

			break;
		case 2:
			if (check(q))
			{
				cout << "This expression is palindrome" << endl;
			}
			else cout << "This is not palindrome" << endl;
			break;
		case 3:
			edit(q);
			break;
		case 4:
			list(q);
			break;
		case 5:
			cout << " Thanks for using" << endl;
			system("pause");
			menu = 0;
			break;
		}
	}
	return 0;
}

void add(Queue* q, char k) {
	// Create a new LL node 
	QNode* temp = newNode(k);

	// If queue is empty, then 
	// new node is front and rear both 
	if (q->rear == NULL) {
		q->head = temp;
		q->rear = temp;
		return;
	}

	// Add the new node at 
	// the end of queue and change rear 
	q->rear->next->prev = q->rear;
	q->rear->next = temp;
	q->rear = temp;
}

void edit(Queue* q) {
	char temp;
	while (!check(q)) // while string is not a palindrome
	{   // delete head,add the rear to front
		deleteHead(q);
		temp = q->rear;
		add(q, temp);

	}
	cout << "The string is now a palindrome :" << endl;
	list(q);
}


void list(Queue* q)
{
	QNode* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}

	int check(Queue * q)
	{
		char temp1, temp2;
		temp1 = q->head;
		temp2 = q->rear;
		while (temp1 == temp2) // while head and rear is equal
		{
			deleteHead(q); // delete them
			deleteRear(q);
			temp1 = temp1->next; // next from head
			temp2 = temp2->prev; // prev from rear
			if (temp1->next = NULL && temp2->next = NULL) //both both of them reach to null
			{
				return 1; // success
			}
		}
		if (temp1 != temp2) // they end up not equal
		{
			return 0; // failure
		}
		else return 1; // else succes
	}

	void deleteHead(Queue * q) {
		// If queue is empty, return NULL. 
		if (q->front == NULL)
			return NULL;

		// Store previous front and 
		// move front one node ahead 
		QNode* temp = q->front;
		delete(temp);

		q->front = q->front->next;

		// If front becomes NULL, then 
		// change rear also as NULL 
		if (q->front == NULL)
			q->rear = NULL;
	}

	void deleteRear(Queue * q)
	{
		if (q->rear == NULL) { return NULL; }

		// Store previous front and 
		// move front one node ahead 
		QNode* temp = q->rear;
		delete(temp);

		q->rear = q->rear->prev;

		// If rear becomes NULL, then 
		// change front also as NULL 
		if (q->rear == NULL) { q->front = NULL; }
	}
