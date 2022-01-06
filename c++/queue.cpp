#include<iostream>
using namespace std;

class Queue
{
    private:
        
        int *front,*rear;
        int size;
        int *que;
    public:
        Queue()
        {
    
            cout<<"Enter the size of array :";
            cin>>size;
            front=rear=NULL;
            que=new int [size];
        }
        void enqueue()
        {
            if (rear==NULL)         //first check queue is empty
            {
                front=rear=que;
                cout<<"Enter the value :";
                cin>>*rear;       
                return;
            }
            if(((rear==(que+(size-1)))&&(front==que))|| (rear+1==front))
            {
 
                    cout<<"Queue is full"<<endl;
                    return;
                    
            }
            if(*(rear+1)==size)     //when rear is pointing to last index and our first indx  is empty then move rear ther add value
            {
                if(front==que)
                {
                    cout<<"overflow";
                }else
                {

                rear=que;
                }
            }
                        rear++;

            cout<<"Enter new value :";
            cin>>*rear;
            return;
        }
        void dequeue()
        {
            if(front==NULL)
            {
                cout<<"Its empty"<<endl;
                return;
            }
            if(front==rear)
            {
                front=rear=NULL;
                return;

            }
            if(front==((size-1)+que))
            {
                front=que;
                return;
            }
            // if(*(front+1)==size)
            // {
            //     front=0;
            // }
            front++;
            return;
        }
        void print()
        {
            int *val=front;
            while(val!=rear)
            {
                cout<<*val<<endl;
                val++;
            }
            cout<<*val<<endl;
        }
        ~Queue()
        {
            delete [] que;
        }

};
int main()
{
    Queue obj;
    //cout<<"dequeue call"<<endl;
    obj.dequeue();
    obj.enqueue();
    //cout<<"dequeue call"<<endl;
    obj.dequeue();
    obj.enqueue();
    obj.enqueue();
    obj.enqueue();
    obj.enqueue();
    obj.enqueue();
    //cout<<"dequeue call"<<endl;
    obj.dequeue();
    //cout<<"dequeue call"<<endl;
    obj.dequeue();
    obj.enqueue();
    obj.print();

    //--------usefull case -----------//
    //cout<<"dequeue call"<<endl;
    //obj.dequeue();
    //cout<<"dequeue call"<<endl;
    //obj.dequeue();
    //cout<<"dequeue call"<<endl;
    //obj.dequeue();
    //cout<<"dequeue call"<<endl;
    //obj.dequeue();

    return 0;
}
