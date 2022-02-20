#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *left;
    Node *right;
    int leftflag;
    int rightflag;

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
class TBT
{
    public:
    Node *root,*dummy;
    TBT();
    void insertion(Node *,int);
    void inorder(Node *);
    void showTrunks(Trunk *);
    void printTree(Node * &,Trunk *,bool);
    void delete1(int,Node *);
    Node* find_successor(Node *,Node * &);
    void delete_node(Node *,Node *);
};
void TBT::delete1(int key,Node *temp)
{
    if(root==NULL)
    {
        cout<<"Tree is empty ";
        return;
    }
    if (temp->left->info==key)
    {
        delete_node(temp->left,temp);
        return;
    }
    if((temp !=dummy)&&(temp->right->info==key))
    {
        delete_node(temp->right,temp);
        return;
    }
    if(temp==dummy)
    {
        delete1(key,temp->left);
        return;
    }
    if((key>temp->info)&&(temp->rightflag==1))
    {
        delete1(key,temp->right);
        return;
    }
    if((key<temp->info)&&(temp->leftflag==1))
    {
        delete1(key,temp->left);
        return;
    }
    cout<<"value dosent exist";
    return;

}
void TBT::delete_node(Node *temp,Node *parent)
{
//case 1
//when both have child
if((temp->leftflag==1) && (temp->rightflag==1))
{

    Node *successor_parent=temp;
    Node *successor=find_successor(temp->right,successor_parent);
    temp->info=successor->info;
    delete_node(successor,successor_parent);
    return;
}
    //case 2
    //when left is child
    if((temp->leftflag==1)&&(temp->rightflag==0))

    {
        if(temp->info<parent->info)
        {
            parent->left=temp->left;
            parent->leftflag=temp->leftflag;
        }
        else
        {
            parent->right=temp->left;
            parent->rightflag=temp->leftflag;

        }
    Node *temp2=temp->left;
        while (temp2->rightflag!=0)
        {
            temp2=temp2->right;
        }
        temp2->right=temp->right;
        delete temp;
        return;

    }

    //case 3
    //when left is nothing
    if((temp->leftflag==0)&&(temp->rightflag==1))
    {


        if (temp->info>parent->info)
        {
            parent->right=temp->right;
            parent->rightflag=temp->rightflag;
        }else
        {
            parent->left=temp->right;
            parent->leftflag=temp->rightflag;
        }
        Node *temp2=temp->right;
        while (temp2->rightflag!=0)
        {
            temp2=temp2->right;
        }
        temp2->right=temp->right;
        delete temp;
        return;



    }





    //case 4
    //leaf node
    if(temp->leftflag==0 && temp->rightflag==0)
    {
        //case 1
        if(parent->left==temp)
        {
            parent->left=temp->left;
            parent->leftflag=0;

        }
        //case 2
        if(parent->right==temp && parent!=dummy)
        {
            parent->right=temp->right;
            parent->rightflag=0;
        }


        //case 3 if dele is root or not
        if(temp==root)
        {
            root=NULL;
            dummy->left=dummy;
            dummy->leftflag=0;
        }
        delete temp;
        return;
    }

}
Node* TBT::find_successor(Node *temp,Node * &parent)
{
    if(temp->leftflag==0)
    {
        return temp;
    }
    parent=temp;
    return find_successor(temp->left,parent);

}






// Helper function to print branches of the binary tree
void TBT::showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}
void TBT::printTree(Node *&root, Trunk *prev, bool isRight)
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
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}


TBT::TBT()
{
    dummy=new Node;
    dummy->left=dummy->right=dummy;
    dummy->leftflag=0;     //thread 0 child 1
    dummy->rightflag=1;
    root=NULL;
}



void TBT::insertion(Node *temp,int key)
{
    if(root==NULL)
    {
     root=new Node;
     root->info = key;
     root->left=dummy;
     root->right=dummy;
     root->rightflag=0;
     root->leftflag=0;
     dummy->left=root;
     dummy->leftflag=1;  //for child
     temp=root;
     return;

    }
    if(temp->info==key)
    {
        cout<<"\t i got you: same value gain naaa!! \n chlo wapis !\n";
        return;
    }
    if(key<temp->info)
    {
        if(temp->leftflag==0)
        {

            Node *temp3=new Node;
            temp3->info=key;
            temp3->left=temp->left;  //predecessor
            temp3->right=temp;
            temp3->leftflag=temp->leftflag;
            temp3->rightflag=0;
            temp->leftflag=1;
            temp->left=temp3;
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
            Node *temp3=new Node;
            temp3->info=key;
            temp3->left=temp;
            temp3->leftflag=0;
            temp3->rightflag=temp->rightflag;
            temp3->right=temp->right;  //successor
            temp->right=temp3;
            temp->rightflag=1;
            return;
        }else
        {
            insertion(temp->right,key);
        }

    }
}

void TBT::inorder(Node *temp)
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
int main()
{
    TBT obj;
    obj.insertion(obj.root,6);
    obj.insertion(obj.root,3);
    obj.insertion(obj.root,5);
    obj.insertion(obj.root,1);
    obj.insertion(obj.root,7);
    obj.insertion(obj.root,8);
    obj.insertion(obj.root,11);
    obj.insertion(obj.root,9);
    obj.insertion(obj.root,13);
    obj.inorder(obj.root);
    //obj.printTree(obj.root,NULL,false);
    cout<<"\n";
    obj.delete1(1,obj.dummy);
        obj.inorder(obj.root);
    cout<<"\n";

    obj.delete1(3,obj.dummy);
    obj.inorder(obj.root);
        cout<<"\n";

    obj.delete1(7,obj.dummy);
    obj.inorder(obj.root);
    cout<<"\n";

    obj.delete1(6,obj.dummy);

    obj.inorder(obj.root);
    cout<<"\n";


    return 0;
}
