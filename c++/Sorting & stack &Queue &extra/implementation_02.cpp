#include <iostream>
using namespace std;


class STACK 
{
    private:
        int *MAx_top;
        int *list;
        int size;
    
    public:
        STACK()    //Constructor
        {
            MAx_top = NULL;
            cout <<"Enter the limit of stack :  ";
            cin>> size;
            cout <<endl;
            list = new int[size];
            
        }

        void push()
        {
            if (MAx_top == NULL)
            {
                MAx_top=list;
                cout <<"ENTER FIRST VALUE IN STACK : ";
                cin>>*MAx_top;
                cout <<endl;
                return;
            }
            

            if (list+(size-1) == MAx_top)
            {
                cout <<"Stack overflow";
                return ;
            }
            MAx_top++;
            cout<<"ENTER THE VALUE :    ";
            cin >>*MAx_top;
    
            cout <<endl;
            return;
        }

        void pop()
        {
            
            if (MAx_top == NULL)
            {
                cout <<"STACK UNDERFLOW"<<endl;
                return;
            }
            
            if (MAx_top == list)
            {
                MAx_top= NULL;
                return;
            }
            MAx_top--;
            return;
        }

        void print ()
        {
            
            if (MAx_top== NULL)
            {
                cout <<"UNDERFLOW!..."<<endl;
            }
            while (MAx_top != NULL )
            {
                cout <<*MAx_top<<"\t";
                pop();
            }
        } 


};

int main ()
{
    STACK obj;
    obj.push();
    obj.push();
    obj.push();
    obj.push();
    obj.print();
    obj.pop();
    obj.print();
    return 0;
}

