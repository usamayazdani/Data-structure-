#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *left,*right;
};
class Avl_02
{

public:
    Node *root;
    int Balncefactor,h;
    int i=1;
    Avl_02();
    ~Avl_02();
    void insertion(Node* &temp,int key);
    void inorder(Node *temp);
    int height(Node *temp);
    int B_F(Node*temp);
    void SLR(Node *&temp);
    void SLL(Node *&temp);
};
//-----Balance Factor-------
int Avl_02::B_F(Node *temp)
{
    int lf=0;
    int rt=0;
    if(temp != NULL){
		if(temp->left != NULL){

		lf = height(temp->left);
    cout<<"LEft node height : "<<lf<<endl;
	}
	if(temp->right != NULL){
		rt = height(temp->right);

        cout<<"Right nodes height : "<<rt<<endl;
	}
}
		return lf - rt;
}
//--------Height----
int Avl_02::height(Node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    int lefti=height(temp->left);
    int righti=height(temp->right);
    if(left>right)
    {
        h=1+lefti;
    }else
    {
        h=1+righti;
    }
    return h;

}
void Avl_02::insertion(Node* &temp,int key)
{
    if(temp==NULL)
    {
        temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;

        if(root==NULL)
        {
            root=temp;

        }
        return;
    }
    else if(key<temp->info)
    {

        insertion(temp->left,key);

    }
    else if(key>temp->info)
    {
         insertion(temp->right,key);

    }
    int balance = B_F(temp);
	if(balance == 2){
		if(key < temp->left->info){
			 return SLR(temp);                 //single right rotation
		}
		else{
			///// left right
			SLL(temp->left);
			return SLR(temp);
		}
	}
	if(balance == -2){
		if(key < temp->right->info){
			//// right right
			return SLL(temp);     // left rotation
		}
		else{
			/// right left
			SLR(temp->right);
			return SLL(temp);
		}
	}
}
//------------Inorder----------------
void Avl_02::inorder(Node* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->info;
        inorder(temp->right);
    }
}

Avl_02::Avl_02()
{
    root=NULL;
}

Avl_02::~Avl_02()
{
    delete root;
}
/*
void Avl_02::SLR(Node *&temp){
			Node *temp2 = temp->left;
			 temp->left = temp2->right;
			 temp2->right = temp;
			 temp = temp2;
}
void Avl_02::SLL(Node *&temp){
			Node *temp2 = temp->right;
			temp->right = temp2->left;
			temp2->left = temp;           //left rotation
			temp = temp2;
}
*/
int main()
{
    Avl_02 obj;
    obj.insertion(obj.root,12);
    obj.insertion(obj.root,8);
    obj.insertion(obj.root,5);
    obj.insertion(obj.root,18);
    obj.insertion(obj.root,11);
    obj.inorder(obj.root);
    cout<<"The balancing factor is now is "<<obj.B_F(obj.root);


    return 0;
}
