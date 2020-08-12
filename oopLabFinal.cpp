/*Write a workplace management program. This program should have the following features;

You have three classes named work, staff and items. The staff and items classes are derived from the work class.
Let there be a 10-element array named id in the work class. This id array can be accessed from the staff and items arrays, but this array should not be copied in the staff and items classes.
staff class has name and authority arrays. Only "1" or "2" values can be stored in the authority array.
items class has name and item_type arrays. Only "consumables" or "fixture" values can be stored in the item_type array.
When the program is run, “What would you like to add? (s:staff, i:item, 0:exit)” question should be asked. Answers can be “s”, “i” or “0”.
According to the answer given, you need the id, name and authority informations or id, name and item_type informations.
Add operations should continue until the answer to the question in step 5 is given "0" or there is no room in the id array.
If id array has no room “id array is full.” warning should be written and program will be finished. When the program finished all the data added so far will be written.
When the answer is 0, all the data added so far will be written and the program will be finished.*/
#include <iostream>
#include <string>

using namespace std;

//for modifying purposes
#define MAX 10





//CLASSES
class Work{

protected:	
int id[MAX];
};

class Staff:protected Work{
private:
string staff_name[MAX];
int staff_authority[MAX];

public:
void get_staff(int &counter_staff);
void set_staff(int &counter_staff);
};

class Item:protected Work{
private:
string item_name[MAX];
char item_type[MAX];
public:
void get_item(int &counter_item);
void set_item(int &counter_item );	
};

//SET
void Staff::set_staff(int &counter_staff){

int temp_id;
string temp_name;
int temp_authority;
//id
cout<<"What is staff id?"<<endl;
cin>>temp_id;
id[counter_staff]=temp_id;
//name
cout<<"What is staff name?"<<endl;
cin>>temp_name;
staff_name[counter_staff]=temp_name;

//limiting input
do {
    cout<<"What is staff authority?(1 or 2)"<<endl;
    cin>>temp_authority;
	    
    }while(temp_authority!= 1 && temp_authority!= 2 );

staff_authority[counter_staff]=temp_authority;
}

void Item::set_item(int &counter_item){
int temp_id;
string temp_name;
char temp_type;
//id
cout<<"What is item id?"<<endl;
cin>>temp_id;
id[counter_item]=temp_id;
//name
cout<<"What is item name?"<<endl;
cin>>temp_name;
item_name[counter_item]=temp_name;

//limiting input
do{

  cout<<"What is item type?(c:consumable,f:fixture)"<<endl;
  cin>>temp_type;

}while(temp_type!='c' && temp_type!='f');

item_type[counter_item]=temp_type;

}



//GET
void Item::get_item(int &counter_item){

int i;


for(i=0;i<counter_item;i++){
//item id
cout<<id[i]<<" ";
//item name
cout<<item_name[i]<<"		";
//item type
 if(item_type[i]=='c'){
 cout<<"Consumable"<<endl;
    }
 else if(item_type[i]=='f'){
 cout<<"Fixture"<<endl;
    }
 }
}




void Staff::get_staff(int &counter_staff){

int i;

//staff id
for(i=0;i<counter_staff;i++){
//id
cout<<id[i]<<" ";
//name
cout<<staff_name[i]<<"    ";
//authority
cout<<staff_authority[i]<<endl;
}

}


int main() {
	char option;
	
	//objects
	Staff obj_staff;
	Item obj_item;
	
	int counter_staff=0;
    int counter_item=0;
	
	
	while(option !='0'){
		//is array full
		if(counter_staff+counter_item==MAX){
		   cout<<"WARNING: id array is full!"<<endl;
		   cout<<"Exiting now..."<<endl;
		   cout<<endl<<"--------------------------------------------------------"<<endl;
		   break;
		}
		
		
		cout<<"What would you like to add?(s:staff, i:item, 0:exit)"<<endl;
	    cin>>option;
		switch(option){
		case 's':
			
			obj_staff.set_staff(counter_staff);
			counter_staff++;
		  break;
		
		case 'i':
			
			obj_item.set_item(counter_item);
			counter_item++;
		  break;
		
		case '0':
			cout<<"Exiting now..."<<endl;
			cout<<endl<<"--------------------------------------------------------"<<endl;
		  break;
		
		default:
		cout<<"Please type only s, i or 0(s:staff, i:item, 0:exit)"<<endl;
		break;		
	    }
	}
	
	obj_staff.get_staff(counter_staff);
	obj_item.get_item(counter_item);
	
	return 0;
}
