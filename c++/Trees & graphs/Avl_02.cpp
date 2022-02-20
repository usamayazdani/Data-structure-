/*
that's lamo destroying logic
yrr actually in c++ jo sir reference variable use kr raha insertion mn agr wo na use kr is it work fine ?
mny pehla ref.. ko use kr kia tu root wo next time bnTa hn jb second insertion call ho
if mn ref.. ka bhghair call karo tu root wo first insertion mn hi bna leta
ab mujy smj nhe aa rahi which is better...sir fazel basit without Reff ka use kr rahe tha🥴
*/
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
    void insertion(Node* temp,int key);
    void inorder(Node *temp);
    int height(Node *temp);

};
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
/*
int height(Node *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    else
    {
        int left=height(temp->left);
        int right=height(temp->right);
        if(left>right)
        {
                return left+1;

        }else
        {
            return right+1;
        }
    }
}
*/

void Avl_02::insertion(Node* temp,int key)
{
    if(temp==NULL)
    {
        temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;
        cout<<"hello"<<i<<endl;
        i++;
        cout<<"value in temp null is : "<<temp->info<<"\n";
        if(root==NULL)
        {
            root=temp;
            cout<<"height of  root is : "<<temp->info<<" : is  : "<<height(temp)<<endl;


        }
        return;
    }
    if(key<temp->info)
    {
        cout<<"hello inside the less"<<i<<endl;

        insertion(temp->left,key);
        cout<<"value is :  "<<temp->info<<"\n";
        cout<<"height of : "<<temp->info<<" : is  : "<<height(temp)<<endl;
        return;
    }
    if(key>temp->info)
    {
         insertion(temp->right,key);

        return;
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

int main()
{
    Avl_02 obj;
    obj.insertion(obj.root,12);
    obj.insertion(obj.root,8);
    obj.insertion(obj.root,5);
    obj.insertion(obj.root,18);
    obj.insertion(obj.root,11);
    obj.inorder(obj.root);
    int k;
        k=obj.height(obj.root);
        cout<<"\nHeight of root is :\t "<<k;
    return 0;
}
