#include<iostream>
#include<queue>
using namespace std;
struct Node
{
	int data;
	Node *left,*right;

};
struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree


class CBT
{
public:
Node *root;
queue<int> ob;
void insertion(Node *,int);
void inorder(Node *);
void printTree(Node *&, Trunk *, bool );
void showTrunks(Trunk *);
void array_fun(int);
void preorder(Node *);
int calculate_node(Node *);
CBT()
{

    root=NULL;
}
};
void CBT::showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

void CBT::printTree(Node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

void CBT::inorder(Node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);

	}
}

void CBT::preorder(Node *temp)
{
	if(temp!=NULL)
	{

		ob.push(temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void CBT::array_fun(int index)
{
    int number=calculate_node(root);
	int *arr=new int[number];
    


	while (!ob.empty())
	{

		cout<<ob.front();
		ob.pop();
		index++;
	}
	for(int i=1; arr[i]='\0'; i++)
	{
		cout<<arr[i]<<" ";
	}

}
int CBT::calculate_node(Node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }else
    {
        return 1+calculate_node(temp->left)+calculate_node(temp->right);
    }
    

}
void CBT::insertion(Node *temp,int key)
{

	if(temp==NULL)
	{

		temp=new Node;
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		if(root==NULL)
		{
			root=temp;
		}

		return;
	}


		if(temp->left==NULL && key>temp->data)
		{
			temp->left=new Node;
			temp->left->data=key;
			temp->left->left=NULL;
			temp->left->right=NULL;
			return;

		}
		//first nested inserted from left sides
		if (temp->left!=NULL && key>temp->data && temp->right!=NULL)
		{
			insertion(temp->left,key);
			return;
		}if (temp->left!=NULL && key>temp->data && temp->right==NULL)
		{
			temp->right=new Node;
			temp->right->data=key;
			temp->right->left=NULL;
			temp->right->right=NULL;
			return;

		}

		if (temp->right!=NULL && key>temp->data)
		{
			insertion(temp->right,key);
			return;
		}if (temp->left==NULL && key>temp->data)
		{
			insertion(temp->left,key);
			return;
		}if (temp->left!=NULL && key >temp->data)
		{
			insertion(temp->right,key);
			return;
		}
		else
		{
			cout<<"This vlaue cannot inputed";
			return;
		}
}
int main()
{
	CBT obj;
	obj.insertion(obj.root,30);
	obj.insertion(obj.root,40);
	obj.insertion(obj.root,50);
	obj.insertion(obj.root,45);
	obj.insertion(obj.root,55);
	obj.insertion(obj.root,60);
	obj.insertion(obj.root,70);
	obj.insertion(obj.root,68);
	obj.insertion(obj.root,69);
	obj.insertion(obj.root,81);

	//obj.inorder(obj.root);
	obj.preorder(obj.root);
	//obj.array_fun(1);
	cout<<endl;
    obj.printTree(obj.root, NULL, false);
    cout<<endl;
    cout<<"Total no of nodes : "<<obj.calculate_node(obj.root);
	return 0;
}