#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *next;
    Node()
    {
        info=0;
        next=NULL;
    }

};
class list1
{
private:
    Node *head,*temp,*temp1;
public:
    list1()
    {
        head=temp1=temp=NULL;
    }

    void add()
    {
    //int choice;
    //cout<<"If you want to add in head press 1 or in array press 0"<<endl;
    //cin>>choice;
    

    if(head==NULL)
    {
        head=new Node;
        cout<<"Enter a value from users"<<endl;
        cin>>head->info;
        head->next=NULL;   
        return;
    }
    
     
    int i=1;
        temp=head;
        while (temp->next!=NULL)
        {
            cout<<"for checing test "<<i<<endl;
            temp=temp->next;
            i++;
        }
        
                    temp1=new Node;
                    cout<<"Enter a new value"<<endl;
                    cin>>temp1->info;
                    temp1->next=NULL;
                    temp->next=temp1;
                    temp=temp1;
                    return;
                    
    }

    void insert()
    {
        int choice,key;
        cout<<"Do you want add value in head"<<endl;
        cin>>choice;
        if(choice==1)
        {

            temp1=new Node;
            cout<<"enter a new node value"<<endl;
            cin>>temp1->info;
            temp=head;
            head=temp1;
            head->next=temp;
            return;
            

        }else if(choice==0)
        {
            temp=head;
            cout<<"after which value you want to enter"<<endl;
            cin>>key;
            while (temp!=NULL)
            {
                if(temp->info==key)
                {
                    temp1=new Node;
                    cout<<"enter a new node value"<<endl;
                    cin>>temp1->info;
                    temp1->next=temp->next;
                    temp->next=temp1;
                 return;   
                }
                temp=temp->next;
            }
            

        }
    }    
    
    void delete1(){
	temp = head;
	int delekey;
	int choice;
	if(temp==NULL){
		cout << "List is Empty. " << endl;
		return ;
	}
	cout<<"for delete in head press 1 and for whithin array press 0"<<endl;
	cin>>choice;
	cout << "Plz enter value which you want to delete. " << endl;
	cin >> delekey;

	if (choice==1){
	if(head->info==delekey)
	{
		cout<<"You are going to delete head"<<endl;
		temp=head->next;
		delete head;
		head=temp;

	}}	
	else if (choice==0)
	{
	temp=head;
	
//	cout << "Plz enter value which you want to delete. " << endl;
//	cin >> delekey;
	while(temp!=NULL){
		if(temp->next->info==delekey)
		{
			temp1=temp->next;
			temp->next=temp1->next;
			delete temp1;
			return;
		}
		
		temp=temp->next;
	}
	} 

	}



    void print()
    {
       // if(head->next=temp)
        //cout<<temp->info;

         temp=head;
         while (temp!=NULL)
         {
             cout<<temp->info;
             temp=temp->next;
         }
        
    
        //cout<<head->next->info;}
    }

 ~list1();
};


list1::~list1()
{
    delete temp1 ;
}


int main()
{
    list1 obj;
    obj.add();
    obj.add();
    obj.add();
    obj.insert();
    obj.delete1();
     obj.print();


}
/*
    int loop,choice;
    cout<<"How many time want to run a loop"<<endl;
    cin>>loop;
    cout<<" 1 -->add \
            2-->delete \
            3-->search \
            4-->print \
            5 --> exit "<<endl;
    cout<<"For which function you want to call"<<endl;
    cin>>choice;
    for(int i=0; i<choice; i++)
    {

        switch(choice)
        {
        case 1:
            add();
        case 2:
            delete1();
        case 3:
            search1();
        case 4:
            print();
        case 5:
            break;
        }

    }*/
