#include <iostream>

#include<queue>
using namespace std;
struct Edges
{
    char data;    // for weight
    int index;    // for indexing in further values //2 3 4
    Edges *next1=NULL; // further link with one vertex we ues this

};
struct vertex
{
    char data1;
    int weighted;
    int counter;   // number of verte
    Edges *link;   // link b/w edges
    vertex *next2; // connected withe other vetex
};


class Graph
{

public:
    vertex *head;
    vertex *tail;
    int *arr;     // our all main vertex
    int counter2; // for advance vertex counter after
    int count;
    Graph(/* args */);
    ~Graph();
    void BFS();
    void addvertex(char);
    void addEdge(char, char);
    void addhalfedges(vertex *, int);
    void display();
};

void Graph::addvertex(char info)
{
    vertex *temp = new vertex;
    temp->data1 = info;
    temp->counter = counter2; // now we have i vetex in first case
    temp->next2 = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        counter2 += 1; // now it become two but we have 1 vertex then we move
                       // counter2 +1 for next vertex
    }
    else
    {
        tail->next2 = temp;
        tail = temp;
        counter2 += 1;

    }
}
void Graph::addEdge(char info1, char info2)
{
    vertex *temp1, *temp2, *temp3;
    temp1 = temp2 = temp3 = NULL;
    temp1 = head;
    while (temp1 != NULL)
    {

        if (temp1->data1 == info1)
            temp2 = temp1;
        if (temp1->data1 == info2)
            temp3 = temp1;

        temp1 = temp1->next2;
    }
    if (temp2 != NULL && temp3 != NULL)
    {
        addhalfedges(temp2, temp3->counter);
        return;
    }
    else
    {
        cout << "Vertex not found!" << endl;
        return;
    }
}

void Graph::BFS()
{
    if(head==NULL)
    {
        cout<<"TEm ";
        return;

    }else
    {
        vertex *temp1,*temp2;
        temp1=head;
        queue<int> obj;
        cout<<"our quue size is"<<obj.size()<<"\n";
        obj.push(temp1->counter);
        arr =new int[counter2];
        int num=obj.pop();
        temp2=searindexvalue(temp1,num);
    }
    
}

Graph::Graph(/* args */)
{

    head = NULL;
    tail = NULL;
    counter2 = 1;
    count = 0;
}
Graph::~Graph()
{

    vertex *pre;
	vertex *query;
	query = head;
	while(query != NULL)
	{
		pre = query;
		query = query->next2;
		delete pre;
	}
	delete query;
	delete head;
}
void Graph::addhalfedges(vertex *temp, int index)
{
    Edges *ptr;
    if (temp->link == NULL)
        {ptr = new Edges;

                    ptr->index = index;
            ptr->next1 = NULL;
            temp->link = ptr; // for our first edges
            return;
        }
         ptr = temp->link;
    while (ptr->next1!= NULL)
    {
        ptr = ptr->next1;
    }
    ptr->next1 = new Edges;
    ptr->next1->index = index;
    ptr->next1->next1 = NULL;

}
void Graph::display()
{
    cout<<"ok";
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		// cout<<counter<<endl;
		int i = 1;
		vertex *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<temp->data1<<":";
			Edges *t = temp->link;
			while(t != NULL)
			{
				cout<<t->index<<" ";
				t = t->next1;
			}
			cout<<endl;
			temp = temp->next2;
			i++;
		}
	}
}


void Graph::BFS()
{
    vertex *temp;
    i
    temp=head;
    int index_of_visted=0,store_element;
    queue <int> obj;
    int *visted=new int[counter2];
    //main loop
    while (temp!=NULL)
    {
        
    
    

    obj.push(temp->data1);
    cout<<temp->data1;
    *(visted+index_of_visted)=obj.front();
    index_of_visted++;
    Edges *t;
    t=temp->link;
    while (t!=NULL)
    {
        obj.push(t->index);
        t=t->next1;
    }
    obj.pop();
    store_element=obj.front();
    for(int i=0; i<counter2; i++)
    {
        if(*(visted+i)==store_element)
        {
            obj.pop();
            break;
        }
        else
        {
            *(visted+index_of_visted)=store_element;
        }
        

    }
    cout<<obj.front();
    temp=temp->next2;
    }
    

}

/*
void Graph::display()
{

    if (head == NULL)
    {
        cout << "Nothing is there";
        return;
    }
    else
    {
        int i;
        i = 1;
        vertex *temp;
    temp=head;

        while (temp!=NULL)

        {
            cout << i << "value" << temp->data1;
            Edges *t;
            while (t->next1 != NULL)
            {
                                cout << t->index << " ";
                t = t->next1;

            }
            cout<<endl;
                temp=temp->next2;
                i++;
        }
    }
}

*/

int main()
{
    Graph obj;
    obj.addvertex('s');
    obj.addvertex('2');
    obj.addvertex('5');
    obj.addvertex('3');
    obj.addvertex('4');
    obj.addvertex('7');
    obj.addvertex('6');
    obj.addvertex('8');
    obj.addvertex('9');
    obj.addEdge('s', '2');
    obj.addEdge('s', '3');
    obj.addEdge('s', '5');
    obj.addEdge('2', '4');
    obj.addEdge('2', '5');
    obj.addEdge('3', '5');
    obj.addEdge('3', '6');
    obj.addEdge('4', '8');
    obj.addEdge('4', '5');
    obj.addEdge('5', '6');
    obj.addEdge('6', '7');
    obj.addEdge('6', '9');

    obj.addEdge('7', '5');
    obj.addEdge('7', '4');
    obj.addEdge('7', '8');
    obj.addEdge('9', '8');
    obj.addEdge('9', '7');
    obj.display();
}
