#include<iostream>
using namespace std;
/*
Left case= if left is not there it points to predecessor  means small
right case= if right is null it point to sucessor
case 3 :
        when there is no predecsesor and successor
        its point to dummy

*/
class Node
{
    public:
    int info;
    Node *left;
    Node *right;
    int leftflag;
    int rightflag;

};
class Threaded_Tree
{
    public:
    Node *temp,*root,*dummy;
    Threaded_Tree()
    {
        dummy=new Node;
        dummy->left=dummy->right=dummy;
        dummy->leftflag=0;     //thread 0 child 1
        dummy->rightflag=1;
        root=temp=NULL;
    }
    void insertion(Node * ,int);
    void inorder(Node *);
    Node * Inorder_Loop_sub_code(Node *);
    void Inorder_Loop(Node *);
};
void Threaded_Tree::insertion(Node * temp,int key)
{
    if (root==NULL)
    {
            root=new Node;
            root->info=key;
            root->left=root->right=dummy;
            root->leftflag=0;
            root->rightflag=0;
            dummy->left=root;
            dummy->leftflag=1;
            temp=root;
            return;
    }
        if(temp->info==key)
        {
            cout<<"Duplication ";
            return;
        }

        if (key<temp->info)
        {

            if(temp->leftflag==0)
            {
             
                Node *temp3=new Node;
                temp3->info=key;
                temp3->left=temp->left;
                temp3->leftflag=temp->leftflag;
                temp3->right=temp;
                temp3->rightflag=0;
                temp->left=temp3;
                temp->leftflag=1;

                //temp->left->info=temp3->info;
                return;

            }else
            {
                insertion(temp->left,key);


            }
        }
        if(key>temp->info)
        {
            if(temp->rightflag==0)
            {
                Node *n=new Node;
                n->info=key;
                n->right=temp->right;
                n->rightflag=temp->rightflag;
                n->left=temp;
                n->leftflag=0;
                temp->right=n;
                temp->rightflag=1;
                return;

            }else
            {
            insertion(temp->right,key);

            }
    }
    }
void Threaded_Tree::inorder(Node *temp)
{

    if(temp==NULL)
    {
        cout<<"nothing";
        return;
    }

        if (temp->leftflag!=0)
        {

            inorder(temp->left);
        }
        cout<<temp->info<<" ";

        if(temp->rightflag!=0)
        {
         inorder(temp->right);
        }

    }
 /*
void Threaded_Tree::loop_iterative(Node *temp)
{

}
*/
Node* Threaded_Tree::Inorder_Loop_sub_code(Node*temp)
{
  if(temp->rightflag == 0){
  	return(temp->right);
  }

  else {
    temp = temp->right;
    while(temp->leftflag ==1)
      temp = temp->left;
    return temp;
  }
}
void Threaded_Tree::Inorder_Loop(Node* temp)
{
	while(  ( temp=Inorder_Loop_sub_code(temp) ) != dummy ){
		cout << temp->info<<" ";
	}

}

void deleteion(Node *key,Node *temp)
{

if(root==NULL)
{
    cout<<"Nothing";
    return;
}
if(temp->left->info==key)
{
    delete_node(temp->left,temp);
}


}



int main() {

    Threaded_Tree obj;
    obj.insertion(obj.root,6);
    obj.insertion(obj.root,3);
    obj.insertion(obj.root,5);
    obj.insertion(obj.root,1);
    obj.insertion(obj.root,7);
    obj.insertion(obj.root,8);
    obj.insertion(obj.root,11);
    obj.insertion(obj.root,9);
    obj.insertion(obj.root,13);
    //obj.inorder(obj.root);
    obj.Inorder_Loop(obj.dummy);
    return 0;
}
