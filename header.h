#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


//This program is used for the user to enter the tasks that they want to do, each one of them is priortized as the user wants it

const int MAX = 100; //For the arrays of character

class info;
struct node //node structure
{
  info * data;
  node * next;
};

class info  //This class is going to hold the information for the data
{
  public:
    info(char * name, char* des,int pri, char * date);
    void display();
    char* get_name();
    int get_priority();

  private:
    char *name1;
    char *description1;
    int priority1;
    char *date1;
};


class lll //This class manages the linear link list
{
  public:
    lll();
    void insert(info*myinfo);
    void display_priority();
    void display_all();
    void remove_item();
    int count_item();
    ~lll();

  private:
    node * head;
};
