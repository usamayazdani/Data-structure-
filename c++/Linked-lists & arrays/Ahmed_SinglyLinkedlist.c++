#include<iostream>
using namespace std;
int  main() {
    int ans=1;
    for(int i=5; i>0; i--)
    {
        if(i==0 || i==1)
        {
            return 1;
        }else
            {
                ans=ans*i;
            }
    }
    cout<<"df"<<ans<<endl;

}
/*#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class linkedlist
{
    private:
        node *head , *temp , *temp1;
    public:
        linkedlist();
        ~linkedlist();
        void set();
        void Multiple_insert();
        void insert_in_the_start();
        void insert_in_the_end();
        void Multiple_del();
        void del_in_the_start();
        void del_in_the_end();
        void search();
        void duplicate();
        void print();
};
                                            // Constructor ;
linkedlist::linkedlist()
{
    head = NULL;
    temp = NULL;
    temp1 = NULL;
}
                                            // Create linkedlist;

void linkedlist::set()
{
    if(head == NULL)
    {
        temp = new node;
        cout<<"Enter the value of first node ";
        cin>>temp->data;
        temp->next=NULL;
        head = temp;
        return ;
    }

    temp1 = new node;
    cout<<"Enter the value of new node ";
    cin>>temp1->data;
    temp->next = temp1;
    temp1->next=NULL;
    temp = temp1;
}

                                             // Insert function;

void linkedlist::Multiple_insert()
{
    if(head == NULL)
    {
        cout<<"Empty list"<<endl;
        return;
    }

    int key;
    temp = head;
    cout<<"Enter the key which is you want to insert ";
    cin>>key;

    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            temp1 = new node;
            cout<<"Enter the value of node which is you want to insert ";
            cin>>temp1->data;
            temp1->next = temp->next;
            temp->next = temp1;
            return;
        }
        temp = temp->next;
    }

}

                                                //insert in the start;

void linkedlist::insert_in_the_start()
{
    if(head == NULL)
    {
        cout<<"Empty list"<<endl;
        return;
    }

    temp = head;

    temp1 = new node;
    cout<<"Enter the value of new node ";
    cin>>temp1->data;
    temp1->next = temp;
    head =  temp1;
    temp = head;
}

                                                //insert in the end;

void linkedlist::insert_in_the_end()
{
    if(head == NULL)
    {
        cout<<"Empty list"<<endl;
        return;
    }

    temp = head;
    while(temp!=NULL)
    {
        if(temp->next == NULL)
        {
            temp1= new node;
            cout<<"Enter the value of new node ";
            cin>>temp1->data;
            temp->next = temp1;
            temp1->next = NULL;
            return;
        }
        temp = temp->next;
    }
}
                                                // Print function;

void linkedlist::print()
{
    if(head == NULL)
    {
        cout<<"Linkedlist is empty "<<endl;
        return ;
    }

    temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

                                             // Delete function;

void linkedlist::Multiple_del()
{
    if(head == NULL)
    {
        cout<<"Empty linkedlist "<<endl;
        return ;
    }

    int key;
    cout<<"Enter the value which is you want to delete ";
    cin>>key;
    temp = head;

    while(temp!=NULL)
    {
        if(temp->next->data == key)
        {
            temp1 = new node;
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            return;
        }
        temp = temp->next;
    }
}

                                                //Delete function in end;

void linkedlist::del_in_the_end()
{
    if(head == NULL)
    {
        cout<<"Empty linkedlist "<<endl;
        return ;
    }

    temp = head;
    temp1 = temp;
    while(temp!=NULL)
    {
        if(temp->next->next == NULL)
        {
            temp1 = temp->next->next;
            temp->next=NULL;
            delete temp1;
            return;
        }
        temp = temp->next;
    }

}

                                                //Delete function in the start;

void linkedlist::del_in_the_start()
{
    if(head == NULL)
    {
        cout<<"Empty list "<<endl;
        return;
    }

    temp = head;

    head = temp->next;
    delete temp;
}

                                                //Search function;

void linkedlist::search()
{
    int key;
    cout<<"Enter the Key which is you want to search ";
    cin>>key;
    temp = head;

    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            cout<<"Key is Exist "<<endl;
        }
        else
        {
            cout<<"sorry \"Key is not exist\""<<endl;
        }
        temp = temp->next;
    }
}

                                            //Duplicate function

void linkedlist::duplicate()
{
    if(head == NULL)
    {
        cout<<"Empty list "<<endl;
        return ;
    }
    int count;
    temp = head;
    int value;
    while(temp!=NULL)
    {
        temp1 = temp;
        while(temp1!=NULL)
        {
            if(temp->data == temp1->data)
            {
                value = temp1->data;
                count++;
            }
            temp1= temp->next;
        }
        temp = temp->next;

        if(count >= 1)
        {
            cout<<"Duplicate node is "<<value <<" and it's repeat "<<count<<" time"<<endl;
        }
    }
}

                                                // Destructor function;

linkedlist::~linkedlist()
{
    delete temp, temp1;
}

int main()
{
    linkedlist L;
    int press;
    while(true)
    {
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Press 1 for  set linkedlist:"<<endl;
        cout<<"Press 2 for Insert node in the start: "<<endl;
        cout<<"Press 3 for insert node in the end: "<<endl;
        cout<<"Press 4 for Insert node in the middle of linkedlist:"<<endl;
        cout<<"Press 5 for delete node in the middle of linkedlist:"<<endl;
        cout<<"Press 6 for delete node in the end of linkedlist:"<<endl;
        cout<<"Press 7 for delete node in the start of linkedlist:"<<endl;
        cout<<"press 8 for print linkedlist:"<<endl;
        cout<<"Press 9 for searching: "<<endl;
        cout<<"Press 0 for duplicate node: "<<endl;
        cout<<"Press 10 to exit ";
        cout<<endl;
        cout<<endl;
        cout<<"Enter the Value ";
        cin>>press;
        cout<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<endl;
        if(press == 1)
        {
            int y;
            cout<<"How many times you want to set node ";
            cin>>y;
            for(int x = 0; x<y; x++)
            {
                L.set();
            }

        }
        else if(press == 2)
        {
            L.insert_in_the_start();
        }
        else if(press == 3)
        {
            L.insert_in_the_end();
        }
        else if(press == 4)
        {
            L.Multiple_insert();

        }
        else if(press == 5)
        {
            L.Multiple_del();

        }
        else if(press == 6)
        {
            L.del_in_the_end();
        }

        else if(press == 7)
        {
            L.del_in_the_start();
        }
        else if(press == 8)
        {
            L.print();

        }
        else if(press == 9)
        {
            L.search();
        }
        else if(press == 0)
        {
            L.duplicate();
        }
        else if(press == 10)
        {
            break;
        }
        else
        {
            cout<<"No linkedlist"<<endl;
            break;
        }

    }
    return 0;
}*/
