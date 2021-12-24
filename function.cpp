#include "header.h"
lll::lll()
{
  head = NULL;

}

int menu(int choice) //Menu function
{
  cout<<'\n'<<"Hello! "<<'\n'<<"Enter the number of the option you choose:"<<'\n'<<"(1) Insert a new item."<<'\n'<<"(2) Get items by priority. "<<'\n'<<"(3) Display all the items."<<'\n'<<"(4) To count the tasks you have entered."<<'\n'<<"(5) To remove a task by name"<<'\n'<<"What do you want to do: ";

  cin>>choice;
  cin.ignore(100,'\n');

  return choice;  //Return choice 
}

info::info(char* name,char* des,int pri,char*date) //Constructor
{
  name1 = new char[strlen(name)+1];
  strcpy(name1,name);
  description1 = new char[strlen(des)+1];
  strcpy(description1,des);
  priority1 = pri;
  date1 = new char[strlen(date)+1];
  strcpy(date1,date);
}

void lll::insert(info * myinfo) //Function that inserts in the lll
{
  if(!head)
  {
    head = new node;
    head->data =myinfo;
    head -> next = NULL;
    return;
  }
  node * current = head;
  while(current-> next)
  {
    current = current->next;
  } 
  node * temp = new node;
  temp -> data = myinfo;
  current -> next = temp;
  temp -> next = NULL;
  return;
}

void lll::display_priority() //Displaying depending on priority
{ 
  if(!head)
    return;
  node * current = head;
  int num; //user's chosen priority
  cout<<'\n'<<"What is the priority of the items you want displayed: ";
  cin>>num;
  cin.ignore(100,'\n');
  while(current)
  {
    if(current->data->get_priority() == num)
    {
      current->data->display();
    }
    current = current -> next;
  }
}

void lll::display_all() //Display all the items
{
  if(!head)
    return;
  node * current = head;
  while(current)
  {
    current->data->display(); 
    current = current -> next;
  }
}
// getting priority from the info class
int info::get_priority(){
  return priority1;
}
//getting name from the info class
char* info::get_name(){
  return name1;
}
//display the info
void info::display(){
  cout<<name1<<'\n'<<description1<<" The priority of this task is: "<<priority1<<". Should be done on: "<<date1;
}
//removing an item from lll
void lll::remove_item()
{
  if(!head){
    cout<<"You have no tasks!"<<'\n';
    return;
  }
  char remove[MAX];
  cout<<"What is the name of the item that you want to remove: ";
  cin.get(remove,MAX,'\n');
  cin.ignore(100,'\n');
  node * current = head;
  node * prev = head;
  char * name;
  while(current){
    

    if(strcmp(current->data->get_name(),remove)==0){
      if(head == current)
        head = NULL;
      else{
        //current = current -> next;
        delete(current);
        prev -> next = prev ->next->next;
      }
    }

  }
}
//Counting how many tasks the user entered
int lll::count_item()
{
  if(!head)
    return 0;
  node * current = head;
  int counter = 0;
  while(current)
  {
    counter = counter + 1;
    current = current -> next;
  }
  return counter;
}
//destructor
lll::~lll()
{
  
}
