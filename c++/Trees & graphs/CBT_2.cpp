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
	int *arr=new int[10];


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


		if(temp->left==NULL && key<temp->data)
		{
			temp->left=new Node;
			temp->left->data=key;
			temp->left->left=NULL;
			temp->left->right=NULL;
			return;
		}if (temp->left!=NULL && key<temp->data && temp->right!=NULL)
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
		}if (temp->left==NULL && key<temp->data)
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
	obj.insertion(obj.root,17);
	obj.insertion(obj.root,14);
	obj.insertion(obj.root,19);
	obj.insertion(obj.root,12);
	obj.insertion(obj.root,16);
	obj.insertion(obj.root,18);
	obj.insertion(obj.root,20);
	obj.insertion(obj.root,11);
	obj.insertion(obj.root,13);
	obj.insertion(obj.root,15);

	//obj.inorder(obj.root);
	obj.preorder(obj.root);
	obj.array_fun(1);
	cout<<endl;
    obj.printTree(obj.root, NULL, false);

	return 0;
}

/*


#include <iostream>
using namespace std;



struct node{
	int info;
	node *left;
	node *right;
};


class Complete_Binary_Tree{
	private:
		node *temp;
		int node_counter;
		int local_height;
		int height;
		int flag;
	public:
	node *root;
	int key;
	Complete_Binary_Tree(){
		root = NULL;
		temp = NULL;
		flag = 0;
		node_counter = 0;
		local_height = 0;
		height = 0;
		int key;
	}
	int power_computation(int Base, int Exp)
	{
		int Storing =1;
		for(int i=0; i<Exp; i++)
		{
			Storing  = Base * Storing;
		}
		return Storing;
	}

	int insertion (node *temp)
	{

		if (root == NULL)
			{
				root = new node;
				root -> info = key;
				root-> left = NULL;
				root ->right = NULL;
				node_counter++;
			}
		else
		{
			if( power_computation(2,height+1)-1 == node_counter)
			{
				if (temp->left != NULL)
				{
					local_height++;
					insertion(temp->left);
					local_height--;
				}
				else
				{
					cout <<temp->info << " : Temp ->left " << endl;
					temp->left = new node;
					temp->left->info = key;
					temp->left->left = NULL;
					temp->left->right = NULL;
					node_counter++;
					height ++;
					return 0;
				}
			}
			else{

				if (local_height == height-1 && temp ->left == NULL)
				{
					
					cout <<temp->info << " : Temp->left " << endl;
					temp->left = new node;
					temp->left->info = key;
					temp->left->left = NULL;
					temp->left->right = NULL;
					node_counter++;
					return 0;
				}

				if(local_height == height-1 && temp ->right == NULL)
				{
					cout <<temp->info << " Temp->right " << endl;
					temp ->right = new node;
					temp->right->info = key;
					temp->right->left = NULL;
					temp->right->right = NULL;
					node_counter++;
					return 0;
				}

				if (temp->left != NULL)
				{
					local_height++;
					insertion(temp->left);
					local_height--;
				}
				if (temp->right != NULL)
				{
					local_height++;
					insertion(temp->right);
					local_height--;
				}
				return 0;
			}
		}



	}

	int Printing(node *temp)
	{
		if(temp->left != NULL)
		{
			Printing(temp->left);
		}
		// if (key != temp->info)
		// {
			cout << temp->info << " " ;
		//}

		if (temp->right != NULL)
		{
			Printing(temp->right);
		}
	}
};

int main ()
{
	Complete_Binary_Tree C1;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the value " << endl;
		cin >> C1.key;
		C1.insertion(C1.root);
	}
	C1.Printing(C1.root);
}
/*
#include<iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node{
	int no;
	node *left,*right;
	int noode;
};

class Complete_Binary_Tree{

	public:
		node *root;
		int key,height,node_count,local_height,one_inser;
		Complete_Binary_Tree();
		~Complete_Binary_Tree();
		int power_fun(int x,int n);
		void insertion(node *);
		void options();
		void destory(node *);
		void in_order(node *);
		void delete_node(node *);
		void dele_last(node *);

};

Complete_Binary_Tree::Complete_Binary_Tree(){
	root=NULL;
	height=node_count=local_height=0;
	one_inser=1;
}

void Complete_Binary_Tree::insertion(node *temp){
	if(root==NULL){
		root=new node;
		root->no=key;
		root->left=NULL;
		root->right=NULL;
		node_count++;
		root->noode=node_count;
		return;
	}

	if( temp->no==key ){
		cout<<" \n Given numbe r is already present in tree.\n";
		return;
	}

	if(power_fun(2,height+1)-1== node_count)
	{
    	if( temp->left!=NULL )
       	{
       		local_height++;
			insertion(temp->left);
			local_height--;
			return;
       	}
      	else
       	{
	 		temp->left=new node;
	 		temp->left->no = key;
	 		temp->left->left=NULL;
	 		temp->left->right=NULL;
	 		node_count++;
	 		temp->left->noode=node_count;
	 		height++;
	 		return;
       	}
   	}
   	if(power_fun(2,height+1)-1 > node_count){

		if(one_inser){

			if (local_height==height-1){

	   			if( temp->left==NULL ){
	   				temp->left=new node;
		 			temp->left->no = key;
		 			temp->left->left=NULL;
		 			temp->left->right=NULL;
		 			node_count++;
		 			temp->left->noode=node_count;
		 			one_inser=0;
		 			return;

	       		}

	       		if( temp->right==NULL ){
	       			temp->right=new node;
		 			temp->right->no = key;
		 			temp->right->left=NULL;
		 			temp->right->right=NULL;
		 			node_count++;
		 			temp->right->noode=node_count;
		 			local_height=height;
		 			one_inser=0;
		 			return;

	       		}

	       		return;
			}

			if( temp->left!=NULL ){
				local_height++;
				insertion(temp->left);
				local_height--;
			}

			if(	temp->right!=NULL){
				local_height++;
				insertion(temp->right);
				local_height--;
			}

			return;

		}else{	return;}
	}

	cout<<"wrong side...!"<<endl;
	return;
}



void Complete_Binary_Tree:: options()
{
 	cout<<"\n\n ************** Select Option *****************.\n";
 	cout<<"\n Enter any of choices.\n";
 	cout<<"\n 0 : Quitting the Program.\n";
 	cout<<"\n 1 : Print the whole BST .\n";
 	cout<<"\n 2 : Adding (inserting) node in BST.\n";
 	cout<<"\n 3 : Delete (deleting) node in BST.\n";
 	cout<<"\n------------------------------\n";
 	cout<<"height        : "<<height<<endl;
	cout<<"local_height  : "<<local_height<<endl;
	cout<<"Nodes         : "<<node_count<<endl;
	cout<<"------------------------------\n";
}//--------------------------------------------------------------


void Complete_Binary_Tree:: in_order(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if( temp->left!=NULL ){
  	cout<<"("<<temp->no<<")left->";
  	in_order(temp->left);
  }

  cout<<temp->no<<"  ";
  if( temp->right!=NULL ){
  	cout<<"("<<temp->no<<")right->";
  	in_order(temp->right);
  }

  return;
}//----------------------------    PROGRAM ENDS HERE  ---------------------------------------
/////--------------power function --------//////
int Complete_Binary_Tree::power_fun(int x,int n){
	int mul=1;
	for(int i=1; i<=n; i++){
		mul=mul*x;
	}
	return mul;
}
/////--------------power function --------//////




//----------------------- destory tree Function Starts  -----------------------

Complete_Binary_Tree::~Complete_Binary_Tree(){
	destory(root);
	cout<<"Done "<<endl;
}

void Complete_Binary_Tree::destory(node *temp){
	if(temp->left!=NULL && temp->right!=NULL){
		destory(temp->left);
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}


	if(temp->left!=NULL && temp->right==NULL){
		destory(temp->left);
		delete temp;
		temp=NULL;
		return;
	}

	if(temp->left==NULL && temp->right!=NULL){
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}

	else{
		delete temp;
		temp=NULL;
		return;
	}
	root=NULL;
}



////-------------------destory function ends -----------//////

//////--------------delete Node--------------////////////

void Complete_Binary_Tree::delete_node(node *temp){
	if(temp==NULL)
		return;

	if(root->no==key){
		if(root->left==NULL){
			delete root;
			root= NULL;
			node_count--;
		}else{
			dele_last(root);
			root->no=key;
		}
		return;
	}


	if(temp->no==key){
		if(temp->noode==node_count){
			dele_last(root);
			return;
		}
		dele_last(root);
		temp->no=key;
		return;
	}

	if(temp->left!=NULL && temp->right!=NULL){
		delete_node(temp->left);
		delete_node(temp->right);
		return;
	}

	if(temp->left!=NULL && temp->right==NULL){
		delete_node(temp->left);
		return;
	}

	if(temp->left==NULL && temp->right==NULL){
		return;
	}
	return;
}

void Complete_Binary_Tree::dele_last(node *temp){
	if(temp->left->noode==node_count){
		key=temp->left->no;
		delete temp->left;
		temp->left=NULL;

		if(power_fun(2,height) == node_count){
			height--;
		}

		node_count--;
		return;
	}

	if(temp->right->noode==node_count){
		key=temp->right->no;
		delete temp->right;
		temp->right=NULL;
		node_count--;
		return;
	}

	if(temp->left!=NULL && temp->right!=NULL){
		dele_last(temp->left);
		dele_last(temp->right);
		return;
	}

	if(temp->left!=NULL && temp->right==NULL){
		dele_last(temp->left);
		return;
	}

	if(temp->left==NULL && temp->right==NULL){
		return;
	}
	return;
}

//////--------------delete Node--------------////////////



int main(){
	char ch;
  	Complete_Binary_Tree obj;
  	while( 4 )
  	{
    obj.options();
    ch=getch();
    switch(ch)
     {
       	case '0':
       		obj.destory(obj.root);
			cout<<"Done "<<endl;
			exit(0);
			break;

		case '1':
			obj.in_order(obj.root);
			break;
		case '2':
			cout<<"Enter key : ";
			cin>>obj.key;
			obj.one_inser=1;
			obj.insertion(obj.root);
			obj.local_height=0;
			break;
		case '3':
			cout<<"Enter key to delete: ";
			cin>>obj.key;
			obj.delete_node(obj.root);
			break;
       	default :
			exit(0);
			break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------

*/


