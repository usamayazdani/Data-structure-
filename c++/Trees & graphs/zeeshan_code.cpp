#include<iostream>
#include<conio.h>
using namespace std;

class list
{
	struct node
	{
		int info;
		node *next;
		node *previous;
	};
	node *head=NULL;
	
	public:
		void insert();
		void display();
		void del();
};

int main()
{
	list l;
	
	int choice;
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1:
	    	
	    	cout<<"\n\nInsert Record:";
	    	l.insert();
	    	break;
	    case 2:
	    	cout<<"\n\n\tDisplay Record:";
	    	l.display();
	    	break;
	    case 3:
	    	cout<<"\n\n\tDelete Record:";
	    	l.del();
	    	break;
	    case 4:
	    	exit(0);
		default:
			cout<<"\n\nWrong input:....";
	}

	
}

void list::insert()
{
  node*new_node=new node;
  new_node->next=NULL;
  new_node->previous=NULL;
  
  if(head==NULL)
  {
  	
  	head=new_node;
  	cout<<"\n\n\tEnter your value: ";
  	cin>>new_node->info;
  	new_node->next=NULL;
  	new_node->previous=NULL;
  	return;	
  }
  else
  {
  	int key,count=0;
  	node *tem=NULL,*tem1=NULL;
  	
  	cout<<"\n\n\tEnter your Exact node value to insert data after that node value OR before that node Value: ";
  	cin>>key;
  	tem=head;
  	while(tem!=NULL)
	  {
	  	if(tem->info==key)
		  {
		  	count++;
		  	int second_choice;
		  	cout<<"\n\n\tYour value is Matched Successfully";
		  	cout<<"\n\tTo Enter Node After that Node Press 1:";
		  	cout<<"\n\tTo Enter Node Before that Node Press 2:";
		  	cout<<"\n\n\tEnter your Choice: ";
		  	cin>>second_choice;
		  	switch(second_choice)
			{
			case 1:
		  	 if(tem->next==NULL)
			   {
			  	tem1=new_node;
			  	cout<<"\n\n\tYour value is Matched Successfully Now enter your new node value :  ";
			  	cin>>tem1->info;
			  	tem1->next=NULL;
			  	tem1->previous=tem;
			  	tem->next=tem1;
			  	cout<<"\n\n\tYour value is Inserted successfully....";
			  	return;
			   }
			  else
			  {
			  	tem1=new_node;
			  	cout<<"\n\n\tYour value is Matched Successfully Now enter your new node value:  ";
			  	cin>>tem1->info;
			  	tem1->next=tem->next;
			  	tem1->previous=tem;
			  	tem->next=tem1;
			  	tem1->next->previous=tem1->next;
			  	cout<<"\n\n\tYour value is Inserted successfully....";
			  	return;
			  }
			
			case 2:
		  	 if(tem->previous==NULL)
			   {
			  	tem1=new_node;
			  	cout<<"\n\n\tYour value is Matched Successfully Now enter your new node value:  ";
			  	cin>>tem1->info;
			  	tem1->previous=NULL;
			  	head=tem1;
			  	tem1->next=tem;
			  	tem->previous=tem1;
			  	cout<<"\n\n\tYour value is Inserted successfully....";
			  	return;
			   }
			  else
			  {
			  	tem1=new_node;
			  	cout<<"\n\n\tYour value is Matched Successfully Now enter your new node value:  ";
			  	cin>>tem1->info;
			  	tem1->previous=tem->previous;
			  	tem1->next=tem;
			  	tem->previous=tem1;
			  	tem1->previous->next=tem1->previous;
			  	cout<<"\n\n\tYour value is Inserted successfully....";
			  	return;
			  }
			  
			default:
				system("cls");
			    cout<<"\n\nWrong input:....";
			    getch();
			    break;
			}
		  }
	  	tem=tem->next;
	  }
	  if(count==0)
	  {
	  	cout<<"\n\n\tValue doesnot Matched...";
	  }
	  
  }
}

void list::display()
{
 if(head==NULL)
 {
 	cout<<"\n\n\tLinked List is Empty...";
 }
 else
 {
 	node *tem=head;
 	while(tem!=NULL)
	 {
	 	cout<<"\n\tValue = "<<tem->info;
	 	tem=tem->next;
	 }
	 
 }	
}


void list::del()
{
 int key,count=0;
 node *tem=head;
 node *tem1=NULL;
 if(head==NULL)
 {
 	cout<<"\n\n\tLinked List is Empty...";
 }
 else
 {
 cout<<"\n\n\tEnter a Exact value to delete  ";
 cin>>key;
 while(tem!=NULL)
 {
 	if(tem->info==key)
	 {
	 	if(tem->next=NULL)
		 {
		 	count++;
	 	    tem1=tem->previous;
	 	    tem->previous->next=NULL;
	 	    delete tem;
	 	    tem=tem1;
	 	    break;
		 }
		 
		 if(tem->previous=NULL)
		 {
		 	count++;
	 	    tem1=tem->next;
	 	    tem->next->previous=NULL;
	 	    delete tem;
	 	    tem=tem1;
	 	    head=tem;
		 }
	 	count++;
	 	tem1=tem->previous;
	 	tem->previous->next=tem->next;
	 	tem->next->previous=tem->previous;
	 	delete tem;
	 	tem=tem1;
	 	cout<<"\n\n\t Record is Deleted Successfully...";
	 	break;
	 }
 	else if(tem->next->info==key)
	 {
	 	count++;
	 	tem1=tem->next;
	 	tem->next=tem1->next;
	 	delete tem1;
	 	cout<<"\n\n\t Record is Deleted Successfully...";
	 	break;
	 }
	 tem=tem->next;
 }	
 if(count==0)
	  {
	  	cout<<"\n\n\tValue doesnot Matched...";
	  	
	  }
 
 }
 
}