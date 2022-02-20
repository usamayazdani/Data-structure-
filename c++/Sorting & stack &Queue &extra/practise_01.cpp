#include<iostream>
using namespace std;
struct  Node
{
  int info;
  Node *next;
  Node(int val=0)
  {
    info=val;
    next=NULL;
  }
};
class  Linked_list
{
private:
  Node *head,*temp,*temp1;
public:
  Linked_list();
  ~ Linked_list();
  void add(int val)
  {
  temp=new Node(val);
  //when there is no node in it
  if (head==NULL)
  {
    head=temp;
    
    return;
  }

//
while(temp->next==NULL)
{
  temp1->next=temp;

}
temp=temp->next;
}

  void display();
};
void Linked_list::display()
{

  cout<<"Here is the our list"<<endl;
  cout<<head->next;
}
 Linked_list:: Linked_list(/* args */)
{
head=temp1=temp=NULL;
}

 Linked_list::~ Linked_list()
{
  delete temp1;

}

int main(){

Linked_list obj;
obj.add(3);
obj.add(4);
obj.add(5);
obj.display();
return 0;
}
