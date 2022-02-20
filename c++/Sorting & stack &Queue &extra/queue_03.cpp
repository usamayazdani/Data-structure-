#include<iostream>
using namespace std;

class queue
{
	private:
		int *rear=NULL;
		int *front=NULL;
		int *que;
	public:
		int value;
		int size ;
		queue()
		{
				cout<<"enter size : ";
				cin>>size;
				que = new int [size];	
				rear = front = que ;			
		}
		void enque()
		{
		if ( rear == que+(size - 1 ))
        {
            cout << "Queue is full"<<endl ;
            return ;
        }
        if ( rear + 1 == front)
        {
        	cout<<"queue is full "<<endl;
        	return ;
		}
        cout<<"enter a value : "<<endl;
        cin>>value;
        rear++ ;
     	que[*rear] = value ;
		}
		
		
		int deque()
		{	int data;
			if (rear == NULL)
			{
				cout<<"queue is empty ::"<<endl;
				return  0;
			}
			if (front == que +(size)-1)
			{
				data = que[*front] ;
        		que[*front] = 0 ;
        		front = que ;
			}
			data = que[*front] ;
        	que[*front] = 0 ;
        	if ( front == rear )
                front = rear = NULL ;
        	else
                front++ ;

	        return  data ;
		}
		void print()
		{
			if (rear == NULL)
			{
				cout<<"queue is empty ::"<<endl;
				return  ;
			}
			int *temp=front;
		for(int i=0;i<size;i++){
			if(temp==que+(size-1)){
				cout<<*(temp)<<" ";
				temp=que;
			}
			cout<<*(temp)<<" "<<endl;
			temp++;
		}	
			
		}
};
int main()
{
	queue q;
	int i =0;

	q.print();
	q.deque();
	q.deque();
	q.print();
	
		
}