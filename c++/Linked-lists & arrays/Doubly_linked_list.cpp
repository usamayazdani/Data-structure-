#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *next, *prev;
};
class List
{
private:
    Node *head, *temp, *temp1;

public:
    List()
    {
        head = temp = temp1 = NULL;
    }
    void add()
    {
        if (head == NULL)
        {
            head = new Node;
            cout << "Enter a node from users" << endl;
            cin >> head->info;
            head->next = NULL;
            head->prev = NULL;
            return;
        }
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp1 = new Node;
        cout << "Enter a value from users" << endl;
        cin >> temp1->info;
        temp1->next=NULL;
        temp->next=temp1;
        temp1->prev= temp->next;
        temp = temp1;
        return;
    }
    void insertion()
    {

        if (head == NULL)
        {
            cout << "WE cannot find a array" << endl;
        }
        int choice, key;
        cout << "if you want to add in head press 0 or else press 1";
        cin >> choice;
        if (choice == 0)
        {
            temp1 = new Node;
            cout << "eNter a value here" << endl;
            cin >> temp1->info;
            temp = head;
            head = temp1;
            head->next = temp;
            temp->prev = head->next;
            return;
        }
        else if (choice == 1)
        {
            temp = head;
            cout << "Enter a key here after which" << endl;
            cin >> key;

            while (temp != NULL)
            {
                if (temp->info == key)
                {
                     temp1=new Node;
                     cout<<"enter a new value here "<<endl;
                     cin>>temp1->info;
                     temp1->prev=temp;
                     temp1->next=temp->next;
                     temp->next->prev=temp1->next;
                     temp->next=temp1;


                     return;
                }
                temp = temp->next;
            }
        }
    }
    void delete1()
    {
        int deletekey;
        cout<<"Enter a delete value : ";
        cin>>deletekey;
        temp=head;
        while (temp!=NULL)
        {
            if (temp->next->info==deletekey)
            {
                temp1->next->prev=temp;

                temp->next=temp1->next;
            delete temp;
            }
            temp=temp->next;
        }
       
    }
    //code off teacher
    void delete2()
    {
        int key;
        cout<<"enter a key : ";
        cin>>key;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->next->info==key)
            {
                temp1=temp->next;
                temp1->next->prev=temp;
                temp->next=temp1->next;
                delete temp1;
                temp1=temp;
                return;

            }
            temp=temp->next;
        }
    }
    void print()
    {
        Node *te;
        te= head;
        while (te != NULL)
        {
            cout << te->info << " " << endl;
            te = te->next;
        }
    }
    
    ~List()
    {
        delete temp1, head, temp;
    }
};

int main()
{
    List L1;
    L1.add();
    L1.add();
    L1.add();
    //L1.insertion();
    L1.delete2();
    L1.print();

    return 0;
}