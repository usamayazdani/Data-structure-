#include<iostream>
using namespace std;

struct Node
{
int info;
Node *left,*right;
};

class Heap
{
private:
    int height;
    int local_height;
    int countNode;
    Node *temp;
public:
    Node *root;
    int number;
    int flag;
    Node *del_temp;
    Node *search_temp;

    Heap();
    ~Heap();

    void insertion(Node *,int key);
    //void deletion(Node *,int key);
    int power(int ,int);
    void del(Node *temp);
	void search(Node *temp);
	void lowerBubble(Node *temp);
    void inorder(Node *);
		void delAll(Node *temp);

};

Heap::Heap()
{
    root=temp=NULL;
    height=0;
    local_height = 0;
	countNode = 0;
	flag = 0;
	number=0;


}

Heap::~Heap()
{
delAll(root);
}


void Heap::delAll(Node *temp)
{
	if (temp->left!=NULL)
		delAll(temp->left);
	if (temp->right!=NULL)
		delAll(temp->right);
	delete temp;
}

void Heap::inorder(Node *temp)
{
if (temp!=NULL)
{
    inorder(temp->left);
    cout<<temp->info<<" ";
    inorder(temp->right);
}

}


void Heap::insertion(Node *temp,int key)
{


    if(temp==root)
    {flag=0;}

    if(root==NULL)
    {
        temp=new Node;
        temp->info=key;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        height=0;
        countNode+=1;

        return;


    }

    //doing a swaping
    if(temp->info<key)
        {
            cout<<"fd";
            int swap=key;
            key=temp->info;
            temp->info=swap;

        }


    

    
	if (((power(2,height+1))-1) == countNode) 
    {
        cout<<"2";

        //only for checking simply swaping
        while (temp->left!=NULL)
        {
            if(temp->info<key)
            {
                int swap=key;
                key=temp->info;
                temp->info=swap;

            }
            temp=temp->left;
        }
            temp=temp->left;

        Node *temp2=new Node;
        temp2->info=key;
        temp2->left=NULL;
        temp2->right=NULL;
        temp->left=temp2;
        countNode+=1;
        height+=1;
        flag=1;

        if(temp->info<temp->left->info)
        {
            temp->left->info=temp->info;
            temp->info=key;
        }
        return;


    }
    if((height-local_height==1) && (temp->left!=NULL) && (temp->right==NULL))
    {

        Node *temp2=new Node;
        temp2->info=key;
        temp2->left=NULL;
        temp2->right=NULL;
        temp->right=temp2;
        countNode+=1;
        flag=1;
        if (temp->info < temp->right->info)
		{
			temp->right->info = temp->info;
			temp->info = key;
		}

		return;


    }
    if ((height-local_height == 1) && (temp->left == NULL) && (temp->right == NULL))
	{

		Node *temp2 = new Node;
		temp2->info = key;
		temp2->right = NULL;
		temp2->left = NULL;
		temp->left = temp2;
		countNode += 1;
		flag = 1;
		if (temp->info < temp->left->info)
		{
			temp->left->info = temp->info;
			temp->info = key;
		}
		return;
	}


    if(flag==0 && temp->left!=NULL)
    {

        local_height+=1;
        insertion(temp->left,key);
        local_height-=1;

    }
    if(flag==0 && temp->right!=NULL)
    {
        local_height+=1;
        insertion(temp->right,key);
        local_height-=1;

    }
    if(temp==root)
    {
        flag=0;
    }
    return;



}
int Heap::power(int key,int key1)
{
    int result=1;
    for(int i=0; i<key1; i++)
    {
        result=result*key;
    }
    
    return result;
    
}


int main()
{
Heap obj;
obj.insertion(obj.root,70);
obj.insertion(obj.root,60);
obj.insertion(obj.root,40);
obj.insertion(obj.root,50);
obj.insertion(obj.root,55);
obj.insertion(obj.root,39);
obj.insertion(obj.root,37);
obj.insertion(obj.root,30);
obj.insertion(obj.root,31);
obj.inorder(obj.root);


return 0;
}
