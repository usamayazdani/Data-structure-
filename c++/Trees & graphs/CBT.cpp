#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *left;
    Node *right;
};
class CBT
{

    public:
        Node *root=NULL;
        int *arr=new int[8];

        int counter=0;
        void insertion(Node *temp, int key);
        int array(int ,int);
        int array_01(Node *,int);
        int NO_of_Nodes(Node *);
        int postorder(Node *,int &);
        int check_01(Node *,int *,int*);
};



void CBT::insertion(Node *temp,int key)
{
    if (temp==NULL)
    {
        temp=new Node;
        temp->info=key;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        return;
    }
    if(key<temp->info)
    {
        if(temp->left!=NULL)
        {   insertion(temp->left,key);
            return;
        }else
        {
            temp->left=new Node;
            temp->left->info=key;
            temp->left->right=NULL;
            temp->left->left=NULL;
            return;

        }
    }
    if(key>temp->info)
    {
        if(temp->right!=NULL)
        {
            insertion(temp->right,key);
            return;
        }else
        {
            temp->right=new Node;
            temp->right->info=key;
            temp->right->left=NULL;
            temp->right->right=NULL;
            return;
        }
    }
}

/*
int max_level(Node *temp)
{
    if(root==NULL)
    {
        cout<<"Nothing";
    }
    if((temp->left!=NULL)&&(temp->right!=NULL))
    {

        height++;
        max_level()
    }

}
/*
int  CBT::postorder(Node *p,int &counter)
{

    if(p!=NULL)
    {
        postorder(p->left,&(counter+1));
        postorder(p->right,&counter+1);
        cout<<counter;
        //cout<<p->info;
    }
        return counter;

}
/*
CBT::CBT()
{

    int arr=new int[20];
    root=NULL;
}
/*
void CBT::array(int key)
{

}
*/

int CBT::NO_of_Nodes(Node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    if(temp!=NULL)
    {
        return (1+NO_of_Nodes(temp->left)+NO_of_Nodes(temp->right));
    }
}


int CBT::array_01(Node *temp,int index)
{
    if(temp!=NULL)
    {
        array_01(temp->left,index++);
        array(temp->info,index);

                array_01(temp->right,index++);

    }
}
int CBT::array(int key,int index)
{
    arr[index]=key;
    cout<<"Index "<<index;
    //cout<<arr[2]<<" ";
    return index+1;
}











int CBT::check_01(Node *temp,int *lefti,int *righti)
{
    if(temp->left!=NULL)
    {
        check_01(temp->left,lefti,righti);
        return *(lefti)+1;

    }else if(temp->right!=NULL)
        {check_01(temp->right,lefti,righti);
        return *(righti)+1;
    }else
    {

        return *(lefti)+*(righti);
    }

}
int main()
{

    CBT obj;
    obj.insertion(obj.root,12);
    obj.insertion(obj.root,10);
    obj.insertion(obj.root,8);
    obj.insertion(obj.root,7);
    obj.insertion(obj.root,9);
    obj.insertion(obj.root,14);
    obj.insertion(obj.root,15);
    obj.insertion(obj.root,13);
   //cout<< "couner: "<<    obj.NO_of_Nodes(obj.root);
   /*int lefti=0;
   int righti=0;
   cout<< "couner: "<<  obj.check_01(obj.root->left,&lefti,&righti);
*/

cout<<obj.array_01(obj.root,0);

    return 0;
}
