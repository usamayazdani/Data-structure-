#include<iostream>
using namespace std;
#define size 5          //pre-processor
void pause();
class Queue
{
private:
    int q[size];
    int in,out;
    bool is_empty,is_full;
    void inc(int *arrow);
public:
    Queue()         //constructor
    {
        for (int i = 0; i <size; i++)
        {
            q[i]=0;
        }
        in=out=0;
        is_empty=true;
        is_empty=false;
        
    }
    void enqueue(int val);
    int dequeue();
    void print_value();
};
void Queue::inc(int *arrow)
{
    if (*arrow + 1==size)       //if it reach end now get back to start
    {
        *arrow=0;
    }else
    {
        *arrow+=1;
    }
    
}
void Queue::enqueue(int val)
{
    if(is_full)         //Exception handling 
    {
        throw "Queue full .cannot enqueue";
    }
    q[in]=val;
    inc(&in);
    //check if we are full now
    if (in==out)
    {
        is_full=true;
    }
    //not empty any more
    is_empty=false;
}
int Queue::dequeue()
{
    if(is_empty)
    {
        throw "queue empty cannot dequeue";
    }
    int ret=q[out];
    inc(&out);
    if (in==out)
    {
        is_empty=true;
    }
    is_full=false;
    return ret;
}
void Queue::print_value()
{
    cout<<" [ \t";
    for (int  i = 0; i < size; i++)
    {
        cout<<q[i]<<"\t";
    }cout<<" ] "<<endl;
   cout<<" [ \t";
    for (int  i = 0; i < size; i++)
    {
        cout<<i<<"\t";
    }cout<<" "<<endl;
    cout<<" ";
    for (int  i = 0; i <= in; i++)
    {
        cout<<"\t";
    }cout<<" ^in "<<endl; 
    cout<<"  ";
    for (int  i = 0; i <=out; i++)
    {
        cout<<"\t";
    }cout<<" ^out "<<endl; 
    pause();
}

int main(){
Queue que;
que.print_value();

que.enqueue(1);
que.print_value();

que.enqueue(2);
que.print_value();

que.enqueue(3);
que.print_value();

que.enqueue(1);
que.print_value();

que.enqueue(33);
que.print_value();
            // why we use  when we reach end there is no value but our program run same 
            //we use error that there is no value left

    try
    {
        cout<<endl<<" NOw dequeue "<<endl;
        cout<<" Got VAlue : "<<que.dequeue()<<endl; que.print_value();
        cout<<" Got VAlue : "<<que.dequeue()<<endl; que.print_value();
        cout<<" Got VAlue : "<<que.dequeue()<<endl; que.print_value();
        cout<<" Got VAlue : "<<que.dequeue()<<endl; que.print_value();
        cout<<" Got VAlue : "<<que.dequeue()<<endl; que.print_value();
       // cout<<" Got VAlue : "<<que.dequeue()<<endl; que.print_value();


    }
    catch(const char *msg)          //ignore it 
    {
        cout << msg << endl;
    }
    

return 0;
}
void pause()
{
    getchar();
}