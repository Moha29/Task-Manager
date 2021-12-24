#include "header.h"

int menu(int choice);

int main()
{
  char name[MAX];
  char description[MAX];
  int priority;
  char date[MAX];
  int choice;
  int counter;
  lll mylll;


  

  while(choice != 6)  //Display option and will be closed if the user decided to 
  {
    choice = menu(choice);  //Return the user choice from menu
    
    if(choice == 1)
    {
      cout<<'\n'<<"What is the name of the item: ";
      cin.get(name,MAX,'\n');
      cin.ignore(100,'\n');
      cout<<'\n'<<"Write a brief description about the item: ";
      cin.get(description,MAX,'\n');
      cin.ignore(100,'\n');
      cout<<'\n'<<"On a scale from 1 to 10 what is the priorty of this task   (10 is highest):";
      cin>>priority;
      cin.ignore(100,'\n');
      cout<<"When do you want to complete the task: ";
      cin.get(date,MAX,'\n');
      cin.ignore(100,'\n');
      cout<<'\n';
      info * myinfo =new info(name,description,priority,date);

      mylll.insert(myinfo);  //If the user wants to enter a new item
      
    }

    if(choice == 2) //If the user wants to see items within a certain priority
    {
      mylll.display_priority();
    }

    if(choice == 3)
    {
      mylll.display_all();  //If the user decided to display all the items
    }

    if(choice == 4){
      counter = mylll.count_item();
      cout<<'\n'<<"The total of items you have entered is "<<counter<<'\n';
    }

    if(choice == 5){
      mylll.remove_item();
    }


  }

  return 0;


}

