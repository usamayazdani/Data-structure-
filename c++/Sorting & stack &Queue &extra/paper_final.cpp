#include<iostream>
using namespace std;

struct Node_
{
    int info;
    Node_ *left,*right;
};
class Bst
{

public:
Node_ *root;
Bst()
{
    root=NULL;
}
void insertion(Node_ *,int );
void inorder(Node_ *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->info<<" ";
        inorder(temp->right);
    }
}
int function(Node_ *,int,int);
};




int Bst::function(Node_ *temp,int key,int node_counter)
{
    if (temp->info==key)
    {
        if(temp->left!=NULL)
        {
            function(temp->left,key,node_counter+1);
        }if (temp->right!=NULL)
        {
            function(temp->right,key,node_counter+1);

        }else
        {
            return node_counter;
        }

    }








}









void Bst::insertion(Node_ *temp,int key)
{
    if(root==NULL)

    {

        temp=new Node_;
    temp->info=key;
    temp->left=NULL;
    temp->right=NULL;

        root=temp;

    return;
    }

     if (key>temp->info )
    {
        if(temp->right!=NULL){
        insertion(temp->right,key);
        return;
        }
        else
         {
        temp->right=new Node_;
        temp->right->info=key;
        temp->right->right=NULL;
        temp->right->left=NULL;
        return;
        }
    }
    if (key<temp->info )
    {
        if(temp->left!=NULL){
        insertion(temp->left,key);
        return;
        }
        else
         {
        temp->left=new Node_;
        temp->left->info=key;
        temp->left->right=NULL;
        temp->left->left=NULL;
        return;
        }


    }


}



int main()
{

    Bst obj;
    obj.insertion(obj.root,10);
    obj.insertion(obj.root,4);
    obj.insertion(obj.root,1);
    obj.insertion(obj.root,8);
    obj.insertion(obj.root,9);
    obj.insertion(obj.root,12);
    obj.insertion(obj.root,24);
    obj.insertion(obj.root,13);
    //obj.inorder(obj.root);
    cout<<obj.function(obj.root,10,0);
    return 0;
}
