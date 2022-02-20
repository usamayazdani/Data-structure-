#include<iostream>
#define N 5
using namespace std;


class stack
{
private:
    int top=-1;
    int arr[5];
public:
    void push(int x)
    {if(top==N-1)
    {
        cout<<"over flow ";
    
    }else
       { top++;
       arr[top]=x;
       }


    }
    void pop()
    {
        int item;
        if(top==-1)
        {
            cout<<"under flow";
        }else
            {
                item=arr[top];
                top--;
            }
        cout<<"You have delted this item "<<item;
    }
    void peek()
    {
        if(top==-1)
        {
            cout<<"under flow ";
        }else 
            {
                cout<<"top of elements is "<<arr[top];
            }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)

        {
            cout<<"Traverse  "<<arr[i]<<" ";
        }
        
    }
};
int main(){

return 0;
}