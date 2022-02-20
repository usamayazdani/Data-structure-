#include<iostream>
using namespace std ;
template<class t>
struct Node
{
    t info;
    Node<t> *link;
};
template<class t>
class Queue
{
    private:
        Node<t> *queuefront,*queuerear,*temp1;
        int counter;
    public:
    bool isfull();
    bool isEmpty();
    void initilize();
    ~Queue(){delete queuefront,queuerear;}
    void adqueue(t elem);
    void dequeue();

Queue()
{
    queuefront=NULL;
    queuerear=NULL;
}
void print();


        
};
template<class t>
void Queue<t>::adqueue(t elem)
{
    Node<t> *temp;
    temp=new Node<t>;
    temp->info=elem;
    temp->link=NULL;
    if(queuefront==NULL)
    {
        queuefront=temp;
        queuerear=temp;
    }
    else
        {
            queuerear->link=temp;
            queuerear=queuerear->link;
        }
    counter++;
}
template<class t>
void Queue<t>::dequeue()
{

    Node<t> *temp;
    if(!isEmpty()){
    temp=queuefront;
    queuefront=queuefront->link;
    delete temp;
    if(queuefront==NULL)
    {
        queuerear=NULL;
    }}
    else
        cout<<"under flow";
    counter--;
}


template<class t>
void Queue<t>::print()
{
    
    while(queuefront!=NULL)
    {
        cout<<queuefront->info;
        queuefront=queuefront->link;
    }
}





template<class t>
void Queue<t>::initilize()
{
    Node<t> *temp;
    while(queuefront!=NULL){
    temp=queuefront;
    queuefront=queuefront->link;
    delete temp;}
    queuerear=NULL;
}
template <class t>
bool Queue<t>::isEmpty()
{
    return (queuefront == NULL);
}
template <class t>
bool Queue<t>::isfull()
{
    return false;
}
int main()
{
    Queue<int> obj;
    obj.initilize();
    obj.adqueue(13);
    obj.adqueue(1);
    obj.adqueue(3);
    obj.adqueue(2);
    obj.dequeue();
    obj.print();

    return 0;
}