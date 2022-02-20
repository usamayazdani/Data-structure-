#include <iostream>
using namespace std;
template <class t>
class Queue
{
private:
    int max;
    int count;
    int queuefront; //first elemen
    int queuerear;  //last elements
    t *list;

public:
    bool isEmpty();
    bool isfull();
    void initialize();
    t front();
    t back();
    void enqueue(t elem);
    void dequeue();
    Queue(t queueSize)
    {
        if (queueSize <= 0)
        {
            cout << "Size of the array to hold the queue must "
                 << "be positive." << endl;
            cout << "Creating an array of size 100." << endl;
            max = 100;
        }
        else
            max = queueSize; //set maxQueueSize to
        //queueSize
        queuefront = 0;      //initialize queueFront
        queuerear = max - 1; //initialize queueRear
        count = 0;
        list = new t[max]; //create the array to
    }
    ~Queue();
    void print()
    {
        for(int i=0; i<count; i++)
        {
            cout<<list[i]<<" "<<endl;
        }
    }
};
template <class t>
bool Queue<t>::isEmpty()
{
    return (count == 0);
}
template <class t>
bool Queue<t>::isfull()
{
    return (count == max);
}
template <class t>
void Queue<t>::initialize()
{
    queuefront = 0;
    queuerear = max - 1; //it poiting to zero index when we enqueue function
                         // be focus
    count = 0;
}
template <class t>
void Queue<t>::enqueue(t elem)
{
    if (!isfull())
    {
        queuerear = (queuerear + 1) % max;
        count++;
        list[queuerear] = elem;
    }
    else
        cout << "CAnnot add to full queue ";
}
template <class t>
void Queue<t>::dequeue()
{
    if (!isEmpty())
    {
        count--;
        queuefront = (queuefront + 1) % max;
    }
    else
        cout << "queue underflow";
}
template <class t>
t Queue<t>::front()
{
    //assert :: it used when we want test a progeam  at runtime
    //when in our progeam some logical mistake then assert gave us a usefull error rather then simple
    //here we use assert for if user try to acces empty queue
    assert(!isEmpty());
    return list[queuefront];
}
template <class t>
t Queue<t>::back()
{

    assert(!isfull());
    return list[queuerear];
}

template <class t>
Queue<t>::~Queue<t>()
{
    delete [] list;
}

int main()

{
    Queue<int> obj(5);
    obj.initialize();
    obj.enqueue(12);
    obj.enqueue(13);
    obj.enqueue(11);
    obj.enqueue(15);
    obj.enqueue(16);
    obj.print();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.print();
    return 0;
}