//Goal: Writing a basic RSA Algorithm code for understanding the concept better.
#include <iostream>
#include <cstdlib>
#include <string>
#include<math.h>

using namespace std;

#define MAX 5



int encrypt(int temp_int,int e, int n)
{ 
int temp;
temp = pow(temp_int,e);
temp = temp % n;
return temp;
}

/*char decrypt(int temp_int,int e,int n)
{ 
 return;
}
*/

//checking if the number is prime
bool isPrime(int num)
{  
    int temp_bool=false;
     for(int i = 2; i <= num / 2; i++) 
     { 
       if(num==1){return;}
       if(num % i == 0)
       {  
          cout<<"F: FAILED_TEST"<<num; //You don't actually show these numbers
          cout<<endl;
          break;
       }
      else 
      {   
          cout<<"T: TRYING_TEST"<<num; //You don't actually show these numbers
          cout<<endl;
          temp_bool=true;
          
      }
    }
   if(temp_bool)
   {
       cout<<endl;
       cout<<"P: PASSED_TEST"<<num;
       cout<<endl;
    }
   return temp_bool;
}


int main()
{

  //always initialize values
  char array_char[MAX];
  int array_int[MAX];


int p=0;
int q=0;

  int n=0;
  int e=0;

  int phi=0;

  int menu,menu1=1;

  char temp_char='\0';
  int temp_int=0;

  //2 digit random variables randomly generated
  //checked if they are prime or not
  while(menu) 
  {
    p = rand()%100 + 1;
    if(p==isPrime(p)) menu=0;
  }
  while(menu1)
  { 
    q = rand()%100 + 1;
    if(q==isPrime(q)) menu1=0;
  }

  //multiplying prime numbers
  n = p * q;

  //phi is multiplication of those prime numbers
  phi = (p-1) * (q-1);

  //generating random number between 2 and phi
  e = 2 + (rand() % ( phi - 2 + 1 ));


  //reading the message letter by letter
  cout<<"Type your message(only"<<MAX-1<<"letters):\n";
  for(int i=0;i<MAX;i++)
  {  
    cout<<i+1<<". letter(than press enter):";
    cin>>array_char[i];
  }  

  //char array transferred to integer array 
  for(int i=0;i<MAX;i++)
  {  
    char temp_char = array_char[i];
    temp_int= int(temp_char);   //Transfering chars to ASCII values
    array_int[i] = encrypt(temp_int,e,n);   //encrypting by RSA
    array_char[i]='\0';   //deleting the char array for security
  }
  temp_char='\0';

  //printing the encrypted text
  for(int i=0;i<MAX;i++)
  { 
      cout<<array_int[i]<<" ";
  } 
  cout<<endl;
  cout<<"e:"<<e<<"n:"<<n<<"phi:"<<phi;
  return 0;
}
