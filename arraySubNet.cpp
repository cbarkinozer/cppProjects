//C++ sub array comparing program Not finished yet
#include<iostream>
#include<cstdlib>
using namespace std;

const int SIZE = 20;

void create();
void change_element();
void change_add();
void change_delete();
void compare();
void sort();
void display();

//These variables are globally defined
int array1[SIZE];
int array2[SIZE];
int length1;
int length2;

int main()
{
	int menu = 1;
	int decision2;
	int decision;
	while (menu)
	{
		cout << "1_Start,2_Change,3_Exit" << endl;
		cout << "Please enter your decision" << endl;
		cin >> decision;
		switch (decision)
		{
		case 1:
			create();
			sort();
			display();
			compare();

			break;
		case 2:
			cout << "How do you want to change?\n Change single element:1?\n Add new element:2\n Delete single element:3 " << endl;
			cin >> decision2;
			switch (decision2)
			{
			case 1:
				change_element();
				break;
			case 2:
				change_add();
				break;
			case 3:
				change_delete();
				break;

			}
			sort();
			display();
			compare();

			break;
		case 3:
			cout << " Thanks for using" << endl;
			menu = 0;
			break;
		}
	}

	return 0;
}
void create()
{
	int i;
	int m;
	cout << "For the first array(bigger array) " << endl;
	cout << "How many elements do you want to enter?(bigger array) " << endl;

	do{	
		cin >> length1;
		if (length1 < 0) { cout << "Please enter a size greater than zero" << endl; } //be sured to array's size is > zero
	}while (length1 <= 0);

	for (i = 0; i < length1; i++)
	{
		cout << "Please enter the" << i << ". element" << endl; //reading the first array
		cin >> array1[i];

	}

	cout << "For the second array(smaller array) " << endl;
	cout << "How many elements do you want to enter?(smaller array) " << endl;
	
	do {
		cin >> length2;
		if (length2 < 0) { cout<<"Please enter a size greater than zero"<<endl; } //be sured to array's size is >zero
	} while (length2 <= 0);

	for (m = 0; m < length2; m++)
	{
		cout << "Please enter the" << m <<". element" << endl; //reading the second array
		cin >> array2[m];

	}
}



void change_element()
{
	int menu;
	int new_data;
	int array_number;
	int choose;
	cout << "Which array you want to add to 1 or 2" << endl;
	cin >> choose;
	do {
		switch (choose)
		{
		case 1:
			cout << "Which array do you want to change?(zero based)" << endl;
			cin >> array_number;
			cout << "Please enter the new data" << endl; //changing only a existing element's data from array
			array1[array_number] = new_data; //writing the data on the new element
			break;
		case 2:
			cout << "Which array do you want to change?(zero based)" << endl;
			cin >> array_number;
			cout << "Please enter the new data" << endl;
			array2[array_number] = new_data;
			break;
		}
		cout << "Would you like to change more data? yes:1 no:0" << endl;
		cin >> menu;
	} while (menu);
}

void change_add()
{
	int menu;
	int i;
	int new_data;
	int array_number;
	int choose;
	cout << "Which array you want to add to  1 or 2" << endl;
	cin >> choose;
	do {
		switch (choose)
		{
		case 1:
			cout << "Where do you want to add to?" << endl;
			cin >> array_number;
			cout << "What is the new element's data?" << endl;
			cin >> new_data;
			for (int i = length1; i < array_number; i--)
			{
				array1[i] = array1[i - 1]; // adding between the elements for the purpose of creating a new element
			}
			array1[array_number] = new_data; //data is writed on the new element
			length1 = length1 + 1; // size is bigger now
			break;
		case 2:
			cout << "Where do you want to add to?" << endl;
			cin >> array_number;
			cout << "What is the new element's data?" << endl;
			cin >> new_data;
			for (int i = length2; i < array_number; i--)
			{
				array2[i] = array2[i - 1]; 
			}
			array2[array_number] = new_data;
			length2 = length2 + 1;
			break;
		}
		cout << "Would you like to delete more data? yes:1 no:0" << endl;
		cin >> menu;
	} while (menu);
}

void change_delete()
{
	int menu;
	int i;
	int new_data;
	int array_number;
	int choose;
	cout << "Which array you want to delete from  1 or 2" << endl;
	cin >> choose;
	do {
		switch (choose)
		{
		case 1:
			cout << "Which array do you want to delete?" << endl;
			cin >> array_number;
			for (int i = array_number; i < length1; i++)
			{
				array1[i] = array1[i + 1]; // deleting the choosed element from array
			}                                  // passed array to the left
			array1[length1]='\0'; //deleted the last element
			length1 = length1 - 1; // decremented the size
			break;
		case 2:
			cout << "Which array do you want to delete?" << endl;
			cin >> array_number;
			for (int i = array_number; i < length2; i++)
			{
				array1[i] = array1[i + 1];
			}
			array2[length2]='\0';
			length1 = length1 - 1;
			break;
		}
		cout << "Would you like to delete more data? yes:1 no:0" << endl;
		cin >> menu;
	} while (menu);
}

void compare()
{
	int i;
	int j;
	int k=0;

	for (i = 0; i < length2; i++)
	{
		for (j = 0; j < length1; j++)
		{
			if (array2[i] == array1[j]) //checking that if array2's any element does exist at the array1 or not
			{
				k = 1;
			}
		}
	}
	if (k == 1) { cout << "Array2 is subset of Array1" << endl; }
	else if(k==0) { cout << "Array2 is not a subset of Array1" << endl; }
}

void sort()
{
	cout<<"Now sorting"<<endl;
	
	int temp;
	int i, j;
	//for array1
	for (i = 0; i < length1; i++)
	{
		for (j = 0; j < (length1 - i - 1); j++)
		{
			if (array1[j] > array1[j + 1]) // if the element is greater than the next element change their place
			{
				temp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = temp;
			}
		}
	}
	//for array2
	for (i = 0; i < length2; i++)
	{
		for (j = 0; j < (length2 - i - 1); j++)
		{
			if (array2[j] > array2[j + 1])
			{
				temp = array2[j];
				array2[j] = array2[j + 1];
				array2[j + 1] = temp;
			}
		}
	}

}

void display()
{
	cout << "First array(bigger)" << endl; //displaying arrays
	for (int i = 0; i < length1; i++)
	{
		cout << i << ".element =" << array1[i] << endl;
	}

	cout << "Second array(smaller)" << endl;
	for (int i = 0; i < length2; i++)
	{
		cout << i << ".element =" << array2[i] << endl;
	}

}
