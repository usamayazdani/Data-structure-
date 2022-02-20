#include <iostream>
//#include<queue>
#include <queue>
using namespace std;

struct Node
{
    int info;
    Node *left, *right;
};
class Bst
{

public:
    //queue<int> obj4;
    queue<int> obj4;
    Node *temp;
    int val, st;
    Node *root;
    Bst();
    void insert(int key, Node *&temp);
    Node * successor(int value);
    Node *search(int key, Node *&temp);
    void inorder(Node *t);
    Node *delete_01(Node *temp, int info);
    int createqueue(queue<int> obj4);
    int Level_Of_Nodes(Node *,int,int);
    //void postorder(Node *t);
    int second_search(int key, Node *&temp);
};
void Bst::insert(int key, Node *&temp)
{

    if (temp == NULL)
    { // for first Node / root
        temp = new Node;
        temp->info = key;
        temp->left = temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }

        return;
    }

    if (key == temp->info)
    {
        cout << "Value Already Exists " << endl;
        return;
    }
    if (key < temp->info)
    {
        insert(key, temp->left);
        return;
    }
    if (key > temp->info)
    {
        insert(key, temp->right);
        return;
    }
}

Node * Bst::successor(int value)
{
    Node *point_01, *point_02;
    int success_01;
    point_01 = search(value, root);
    if (point_01 == NULL)
    {
        cout << "No value exist";
        return 0;
    }
    if (point_01->right != NULL)
    {
        point_01 = point_01->right;
        while (point_01->left != NULL)
        {
            point_01 = point_01->left;
        }
        return point_01;
    }
    /*
    else{
        point_02=root;
        while (point_02!=point_01)
        {
            if(point_02->info>point_01->info)
            {
            val=point_02;

            point_02=point_02->left;
            }
            else
            {
                f
            }
        }

    }*/

    //-----there is missing case I'll do it laters -------
    //pre decesssor
    // if (point_01->right == NULL)
    // {
    //    return second_search(value,Bst::root);

    // }
}
/*

int Bst::second_search(int key, Node *&temp)
{

    if ((temp->left != NULL) && (key < temp->info))
    {
        val = temp->info;
        return second_search(key, temp->left);
    }
    if ((temp->right != NULL) && (key > temp->info))
    {
        val = temp->info;
        return second_search(key, temp->right);
    }
    if (temp->info == key)
    {
        return val;
    }
    cout << "value is in every case ";
    return val;
}
*/
//----------------------------------------------In order----------------------
void Bst::inorder(Node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->info << " ";
        //succeesor=p->info;
        inorder(p->right);
    }
}

Node *Bst::search(int key, Node *&temp)
{
    if (root == NULL)
    {
        cout << "The Tree is Empty " << endl;
        return NULL;
    } // Search Function

    if (temp->info == key)
    {
        cout << "Value Found " << endl;
        return temp;
    }

    if ((key > temp->info) && (temp->right != NULL))
    {
        return search(key, temp->right);
    }

    if ((key < temp->info) && (temp->left != NULL))
    {
        return search(key, temp->left);
    }

    if ((temp->right == NULL) && (temp->left == NULL))
    {
        cout << "Value Not Found" << endl;
        return NULL;
    }
}
Bst ::Bst()
{
    root = NULL;
}

Node *Bst::delete_01(Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->info)
    {
        root->left = delete_01(root->left, data);
    }
    else if (data > root->info)
    {
        root->right = delete_01(root->right, data);
    }

    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case 2: One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else
        {
            Node *temp = successor(data);
            //Node *temp = FindMin(root->right);
            root->info = temp->info;
            root->right = delete_01(root->right, temp->info);
        }
    }
    return root;
}



int Bst::Level_Of_Nodes(Node *temp,int key,int level)
{
    if (temp==NULL)
        return -1;
    if (temp->info==key)
    {
        return level;
    }
    int l=Level_Of_Nodes(temp->left,key,level+1);
    if (l!=-1)
    {
        return l;
    }
    return Level_Of_Nodes(temp->right,key,level+1);


}

// void Bst::postorder(Node *p)
// {

//     if (p != NULL)
//     {
//         postorder(p->left);
//         postorder(p->right);
//         obj4.push(p->info);
//     }
// }
/*
int Bst::createqueue(queue<int> obj4)
{
    queue<int> obj;


    obj=obj4;


    while (!obj.empty())
    {
        st=obj.top();
        obj.pop();
        cout<<"ok:";
    }
    return st;

}
/*
void Bst::NewTree()
{

}*/


void Bst::level_order_traversal(Node *temp,0)
{
cout<<temp->info<<" ";
if(flag==1)
{
    return ;
}

if (temp->left!=NULL)
{
    level_order_traversal(temp->left,1);
}

if(temp->right!=NULL)
{
    level_order_traversal(temp->right,1);
}

}
int main()
{
    Bst obj, obj2;
    obj.insert(100, obj.root);
    obj.insert(150, obj.root);
    obj.insert(145, obj.root);
    obj.insert(155, obj.root);
    obj.insert(98, obj.root);
    obj.insert(95, obj.root);
    obj.insert(99, obj.root);
    obj.insert(94, obj.root);
    obj.inorder(obj.root);
    cout<<"Level"<<obj2.Level_Of_Nodes(obj.root,94,0);
//    obj.postorder(obj.root);
    //cout << "STAck last value";
    //cout << obj.obj4.back();
    //cout<<"sTacl elem: "<<   obj.createqueue(obj.obj4);

    //cout<<"Succes"<<obj.successor(18);
    //obj.deletion(15, obj.root);
    //    cout<<"Deletion 15"<<endl;
    //obj.delete_01(obj.root,155);
    //cout << " ss" << obj.successor(155);
    //cout << endl;
    //obj.inorder(obj.root);
    return 0;
}
