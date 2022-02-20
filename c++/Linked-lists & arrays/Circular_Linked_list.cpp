#include<iostream>
using namespace std;
struct Node
{
int info;
Node *next,*prev;

};
class List{
private:
Node *head,*temp,*temp1;

public:
    List()
    {
        head=temp1=temp=NULL;
    }
    void add()
    {
        if(head==NULL)
        {
            head=new Node;
            cout<<"Enter a value from users : ";
            cin>>head->info;
            head->next=head->prev=head;
            return;
        }
        temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
            cout<<"VAlue executed";
        }
        temp1=new Node;
        cout<<"Enter a value from usrs : ";
        cin>>temp1->info;
        temp1->next=head;
        temp1->prev=temp;
        temp->next=temp1;
        temp=temp1;
        return;

       
    }
    void insertion()
    {

        if (head == NULL)
        {
            head = new Node;
            cout << "Enter a value from users : ";
            cin >> head->info;
            head->next = head;
            head->prev = head;
            return;
        }

        // temp = head;
        // if (temp->next == head)
        // {
        //     temp1 = new Node;
        //     cout << "Enter a value from users :";
        //     cin >> temp1->info;
        //     temp1->next = temp->next;
        //     temp1->prev = temp;
        //     head->next = temp1;
        //     head->prev = temp1;

        //     return;
        // }
        int key;
        cout << "After which value you want to insert value :";
        cin >> key;
        temp = head;
        while (temp->next != head)
        {
            if (temp->info == key)
            {
                temp1 = new Node;
                cout << "Enter a new value : ";
                cin >> temp1->info;
                temp1->next = temp->next;
                temp1->prev = temp;
                temp->next  =  temp1;
                temp->next->prev = temp1;
                return;
            }
            temp = temp->next;
        }
        if (temp->next == head)
        {
            temp1 = new Node;
            cout << "Enter a value from users :";
            cin >> temp1->info;
            temp1->next = head;
            temp1->prev = temp->next;
            temp->next = temp1;
            temp->prev = temp1;

            return;
        }
    }
    void print()
    {
        temp=head;
        while (temp->next!=head)
        {
            cout<<temp->info<<" "<<endl;
            temp=temp->next;
        }
        cout<<temp->info<<endl;

    }
     ~List()
        {
            delete temp,temp1,head;
        }
};
int main(){
List L1;
L1.add();
//L1.add();
//L1.add();
//L1.add();
//L1.add();
L1.insertion();
L1.print();
return 0;
}