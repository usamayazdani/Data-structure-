#include<iostream>
//#include<queue>
#include"queuelinklist.cpp"
using namespace std;


struct list
{
	int index;
	list *next;
};


struct Node
{
	int data;
	int num;
	Node *next;
	list *listHead;
};

class graph
{
	public:
		Node *head;
		Node *tail;
		int counter;
		int *arr;
		int count;
		graph();
		~graph();
		void addVertex(int info);
		void addEdge(int info1, int info2);
		void addHalfEdge(Node *temp, Node *);
		void delVertex(int info);
		void delEdge(int info1, int info2);
		 void searchVertex(int info);
		void searchEdge(int info);
		void breadthFirst();
		Node* searchingIndexInVertex(Node *temp, int);
		int search(int info);
		void display();
        void adjancey_Matrix();
        void BFS();

};

void graph::adjancey_Matrix()
{
    Node *temp1=head;
    int *arr=new int [7];
    int **two_d_array=new int*[7];
    for(int i=0; i<7; i++)
    {
        two_d_array[i]=new int [7];
    }

    for(int i=0; i<7; i++)
    {
        arr[i]=temp1->data;
     //   cout<<arr[i]<<" ";
        temp1=temp1->next;
    }

    Node *temp2=head;
    for (int i=0; i<7; i++)
    {
        list *t=temp2->listHead;
        while (t!=NULL)
        {
            for (int j = 0; j < 7; j++)
            {
                if(arr[j]==t->index)
                {
                    two_d_array[i][j]=1;
                    cout<<two_d_array[i][j]<<" ";

                }else
                {
                    two_d_array[i][j]=0;
                    cout<<two_d_array[i][j]<<" ";
                }

            }
            cout<<endl;
            t=t->next;

        }
        temp2=temp2->next;

    }

    delete [] arr;
    delete [] two_d_array;

}

/*
void graph::adjancey_Matrix(Node *temp)
{
    // int** arr = new int*[counter];

    // for (int i = 0; i < counter; i++) {

    //     // Declare a memory block
    //     // of size n
    //     arr[i] = new int[counter];
    // }
   // int arr[counter][counter];
        if(head==NULL)
        {
            cout<<"it empty";
        }else
        {
            Node *temp3;
            temp3=head;
            while(temp3!=NULL){
            for(int i=0; i<counter; i++)
            {
            list *t = temp->listHead;
            while(t != NULL)
			{
            for(int j=0; i<counter; j++)

                if(temp3->data=t->index)
                {
                    cout<<"ok";
                    arr[i][j]=1;
                }else
                {
                    arr[i][j]=0;
                }

				t = t->next;
			}

            }
        }


        }

        for(int i=0; i<counter; i++)
        {
            for(int j=0; j<counter; j++)
            {

                cout<<arr[i][j];
            }
        }

}



*/
graph::graph()
{
	head = NULL;
	tail = NULL;
	counter = 1;
	count = 0;
}

graph::~graph()
{
	Node *pre;
	Node *query;
	query = head;
	while(query != NULL)
	{
		pre = query;
		query = query->next;
		delete pre;
	}
	delete query;
	delete head;
}




void graph::addVertex(int info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->num = counter;
	temp->next = NULL;
	temp->listHead = NULL;

	if(head == NULL)
	{
		head = temp;
		tail = temp;
		counter += 1;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		counter += 1;
	}

}

void graph::addEdge(int info1, int info2)
{

	if(head==NULL)
	{
		cout<<"graph is empty"<<endl;
	}
	else
	{
		Node *temp;
		temp = head;
		Node *temp1 = NULL;
		Node *temp2 = NULL;
		while(temp != NULL)
		{
			if (temp->data == info1)
				temp1 = temp;
			if (temp->data == info2)
				temp2 = temp;
			temp = temp->next;
		}
		if (temp1 != NULL && temp2 != NULL)
		{
			addHalfEdge(temp1,temp2);
			// addHalfEdge(temp2, temp1);
			return;
		}
		else
		{
			cout<<"Vertex not found!"<<endl;
			return;
		}
	}

}

void graph::addHalfEdge(Node *temp, Node *temp2)
{
	list *t;
	if (temp->listHead == NULL)
	{
		t = new list;
		t->index = temp2->data;
		t->next = NULL;
		temp->listHead = t;
		return;
	}
	t = temp->listHead;
	while(t->next != NULL)
	{
		t = t->next;
	}
	t->next = new list;
	t->next->index = temp2->data;
	t->next->next = NULL;
}






void graph::breadthFirst()
{
	if(head==NULL)
	{
		cout<<"graph is empty"<<endl;
	}
	else
	{

		Node *temp;
		Node *temp1;
		temp = head;

		queue obj(counter);
		obj.eQueue(temp->num);
        cout<<"value is"<<temp->num;
		arr = new int[counter];
		*(arr+count) = temp->num;
		count += 1;

		while(obj.checkSize() != counter)
		{
			int num = obj.dQueue();
			temp1 = searchingIndexInVertex(temp, num);
			// cout<<temp1->data<<endl;
			temp = head;
			list *t = temp1->listHead;
			while(t != NULL)
			{
				int num = t->index;

				temp1 = searchingIndexInVertex(temp, num);
				temp = head;
				if (search(temp1->num) == 0)
				{
					obj.eQueue(temp1->num);
					*(arr+count) = temp1->num;
					count += 1;
					cout<<temp1->data<<" ";
				}

				t = t->next;
			}
			cout<<endl;
			// cin>>num;
		}
	}
}

Node* graph::searchingIndexInVertex(Node *temp, int info)
{
	while(temp != NULL)
	{
		if (temp->num == info)
		{
			return temp;
		}
		temp = temp->next;
	}
}



int graph::search(int info)
{
	for (int i = 0; i <= count; i++)
	{
		if (*(arr+i) == info)
			return 1;
	}
	return 0;
}


/*

void graph::BFS()
{

    queue <int> obj;
    int *arr=new int[7];

    Node *temp4=head;


    //queue obj(7);
    int i=0;
    //while (temp4!=NULL)
    //{

        obj.push(temp4->data);
    //    for(int l=0; l<7; l++){
        //if(arr[l]!=temp4->data)
                 arr[i]=temp4->data;
    //    }




            while(temp4!=NULL)
       // cout<<t->index<<" ";
        list *t=temp4->listHead;
        temp4=temp4->listHead;
        while (t!=NULL)
        {
            for (int j=0; j<7; j++){
            if(arr[j]!=t->index || arr[j]!=temp4->data)
             {
                 i++;
                arr[i]=t->index;
                 obj.push(t->index);
              //  cout<<"Our queue"<<obj.front()<<"\n";
                //cout<<i<< " "<<arr[i];
            }

                    }
                                // cout<<i<<" ";

                t=t->next;
                }


               // cout<<obj.front()<<" ";
                obj.pop();
                //temp4=temp4->next;

    }





}*/

void graph::display()
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		// cout<<counter<<endl;
		int i = 1;
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<temp->data<<":";
			list *t = temp->listHead;
			while(t != NULL)
			{
				cout<<t->index<<" ";
				t = t->next;
			}
			cout<<endl;
			temp = temp->next;
			i++;
		}
	}
}



int main()
{
	graph obj;
	obj.addVertex(10);
	obj.addVertex(9);
	obj.addVertex(8);
	obj.addVertex(1);
	obj.addVertex(4);
	obj.addVertex(7);
	obj.addVertex(15);
	//obj.addVertex('8');
	//obj.addVertex('9');
	obj.addEdge(10,7);
	obj.addEdge(10,1);
	obj.addEdge(9,10);
    obj.addEdge(8,4);
	obj.addEdge(4,15);
	obj.addEdge(7,4);
	obj.addEdge(7,8);
	obj.addEdge(15,9);


	// obj.addEdge('4','5');
	// obj.addEdge('5','6');
	// obj.addEdge('6','7');
	// obj.addEdge('6','9');
	// obj.addEdge('7','5');
	// obj.addEdge('7','4');
	// obj.addEdge('7','8');
	// obj.addEdge('9','8');
	// obj.addEdge('9','7');
	//obj.display();
    //obj.adjancey_Matrix(obj.head);
//	obj.breadthFirst();
    obj.adjancey_Matrix();
	//obj.BFS();
	return 0;
}
