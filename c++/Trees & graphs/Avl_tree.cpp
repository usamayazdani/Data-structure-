#include<iostream>
using namespace std;
struct Node{
 int info;
 Node *left,*right;
};
class avl
{
    public:
        int Balancefactor,h;
        Node *root;
        void insert1(Node* &temp,int key);
        //int height_of(Node *temp);
        //int height2(Node *temp);
        int height(Node *temp);
        void inorder(Node *temp);
        int Balancing_Factor(Node *temp);
};
void avl::inorder(Node *temp)
{

    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->info<<" ";
        inorder(temp->right);

    }
}
/*
//My first code of height
int avl::height(Node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    int lefti=height(root->left);
    int righti=height(root->right);
    if(left>right)
    {
        h=1+lefti;
    }else
    {
        h=1+righti;
    }
    return h;

}*/
//----------------//

int avl::Balancing_Factor(Node *temp){
	int left = 0;
	int right = 0;
	if(temp != NULL){
		if(temp->left != NULL){
		left = height(temp->left);
	}
	if(temp->right != NULL){
		right = height(temp->right);
		
	}
}
		return left - right;
}
int avl::height(Node *temp){
	if(temp==NULL){
		return 0;
	}
	else{
		int left =height(temp->left);
		int right = height(temp->right);
		if(left>right){
			return left+1;
		}
		else{
			return right+1;
		}
	}
}






















//--------------------//

int avl::height_of(Node* temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
    int lefti=height_of(temp->left);
    int righti=height_of(temp->right);
    if(lefti>righti)
    {
        return lefti+1;

    }else
    {
        return righti+1;
        //h=1+righti;
    }
    }

}
/*
            ---cAse 1-------
-----> Left Left
right rotation
    single rotattion
Node *temp2=temp->left;
temp->left=temp2->right
temp2->right=temp;
temp=temp2;
------> right right
left rotation
Node *temp2=temp->ruhght
temp->right=temp2->left;
temp2->left=temp;
temp=temp2;
----right left
double rotation
rightrotation(temp->right)
leftrortaion(temp-);
*/

/*int avl::Balancefactor(Node *temp)
{
    int left=0;
    int right=0;
    if(!=NULL)

}*/

/*

int height2(Node *temp)
{

}*/
void avl::singlerightrotation(Node* &temp)
{
    Node *temp2=temp->left;
    temp->left=temp2->right;
    temp->right=temp;
    temp=temp2;
}
void avl::singleleftrotation(Node* &temp)
{
    Node *temp2=temp->right;
    temp->right=temp2->right;
    temp2->left=temp;
    temp=temp2;
}
void avl::insert1(Node* &temp,int key)
{
    if(temp==NULL)
    {
        //cout<<"hello world :";
        temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;
        if(root== NULL)
        {
            root = temp;
        }
    
    }
     if (key == temp->info)
    {
        cout << "Value Already Exists " << endl;
        return;
    }
    if (key < temp->info)
    {
        insert1( temp->left,key);
        return;
    }
    if (key > temp->info)
    {
        insert1( temp->right,key);
        return;
    }
    int b_f;
    b_f=Balancefactor(temp);
    if(b_f==2)
    {
        if(key<temp->left->info)
        {
            singlerightrotation(temp);
        }else
            {
                singlerightrotation(temp->right)
                singleleftrotation(temp);

            }
    else if (b_f==-2)

    {
        if(key<temp->right->info)    
        singleleftrotation(temp);
   
    }
    else 
    {
        singlerightrotation(temp->right);
        singleleftrotation(temp);
    }

    }

}
int main()
{
    avl obj;
    obj.insert1(obj.root,12);
    obj.insert1(obj.root,18);
    obj.insert1(obj.root,8);
    obj.insert1(obj.root,11);
    obj.insert1(obj.root,5);
    obj.insert1(obj.root,7);
    obj.insert1(obj.root,4);
    obj.insert1(obj.root,2);
    obj.insert1(obj.root,17);
    obj.inorder(obj.root);
    obj.height(obj.root);
    //cout<<l;

    return 0;
}
