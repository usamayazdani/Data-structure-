#include<iostream>
#define size1 4
using namespace std;
class Node
{
    public:
    int info;
    Node *next;
    Node(){
    info=0;
    next=0;
    }
    Node(int el,Node *ptr=0)
{
    info=el;
    next=ptr;
}

};
class linkedlist
{
public:
    Node *head,*temp,*temp1;

    linkedlist()
    {
        head=temp=temp1=NULL;
    }
        int isempty()
        {
            return head==0;

        }
        //~linkedlist();

void addToHead(int);
 void addToTail(int);
 int deleteFromHead(); // delete the head and return its info;
 int deleteFromTail(); // delete the tail and return its info;
 //void deleteNode(int);
 //bool isInList(int) const;
 void print()
 {
     cout<<head->info;
     cout<<tail->info;
 }
};
/*
linkedlist::~linkedlist()
{
    for(Node * p,!isempty())
    {
        p=head->next;
        delete head;
        head=p;
    }

}*/

void linkedlist ::addToHead(int el)
{
    head=new Node(el,head);
    if (tail==0)
    {

     tail=head;

    }
}
void linkedlist::addToTail(int el)
{
    if(tail!=0)
    {
        tail->next=new Node(el);
        tail=tail->next;
    }else
    head=tail=new Node(el);
}
int linkedlist::deleteFromHead() {
 int el = head->info;
 Node *tmp = head;
 if (head == tail) // if only one node in the list;
 head = tail = 0;
 else head = head->next;
 delete tmp;
 return el;
}
/*int IntSLList::deleteFromTail() {
 int el = tail->info;
 if (head == tail) { // if only one node in the list;

 delete head;
 head = tail = 0;
 }
 else { // if more than one node in the list,
 Node *tmp; // find the predecessor of tail;
 for (tmp = head; tmp->next != tail; tmp = tmp->next);
 delete tail;
 tail = tmp; // the predecessor of tail becomes tail;
 tail->next = 0;
 }
 return el;
 */
int main()
{
    int a[]={1,2,3,4};

    //a[0]=new Node();
    //a[1]=new Node();
    //a[3]=new Node();
    //a[4]=new Node();
    linkedlist l1;
l1.addToHead(5);
l1.addToTail(4);
l1.print();

}
