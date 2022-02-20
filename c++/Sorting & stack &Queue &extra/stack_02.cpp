#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *Next;
    
};

class stack
{
    private:
       Node *top,*temp,*temp1;
    public:
    void push(){
    temp =new Node;
    cout<<"Enter a value from users: ";
    cin>>temp->info;
    temp->Next=top;
    top=temp;
    }
    void display()
    {
        temp=top;
        if(top==NULL)
        {
            cout<<"list is empty";
        }else 
            {
                while (temp!=NULL)
                {
                    cout<<temp->info;
                    temp=temp->Next;
                }
            
            }

    }
    void peek()
    {
        if(top==NULL)
        {
            cout<<"empty";
        }else
            cout<<top->info;
    }

void pop()
{
    temp=top;
    if(top==NULL)
    {
        cout<<"empty";
    }else
        cout<<top->info;
        top=temp->Next;
        delete temp;

}       
};



int main(){

stack obj;
obj.push();
obj.push();
obj.display();
return 0;
}