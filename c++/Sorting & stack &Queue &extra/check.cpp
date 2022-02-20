#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left ;
    Node *right;
};
class Avl_tree{
    public:
            Node *root;

        Avl_tree()
        {
          root=NULL;

        }
        void insertion(int key , Node *&temp);
        int height(Node *temp);
        };
int Avl_tree::height(Node *temp){
    //cout<<temp->data;
    if(temp==NULL){
        return 0;
    }
    else{
        int left =height(temp->left);
        //cout<<left;
        int right = height(temp->right);
        //cout<<right;
        if(left>right){

            return left+1;

        }
        else{
            return right+1;
        }}}

void Avl_tree:: insertion(int key,Node *&temp){

    if(temp==NULL){
    temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    if(root==NULL)
    {
      root=temp;
          cout<<"The height of "<<root->data<<" is"<<height(root)<<endl;

    }
    return;
    }

    if(key<temp->data){
        insertion(key,temp->left);
        return;
        }
    if(key>temp->data){
        insertion(key,temp->right);
        return;
        }
        }
int main(){
    Avl_tree obj;
    obj.insertion(45 , obj.root);
    obj.insertion(66, obj.root);
    obj.insertion(22, obj.root);
    obj.insertion(11,obj.root);
    obj.insertion(3,obj.root);
    obj.insertion(2,obj.root);
    obj.insertion(1,obj.root);
    cout<<obj.height(obj.root->left);
}
/*#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T info;
    Node<T> *rlink;
    Node<T> *llink;
};
/*height of binary tree
 1: Height of left subtree
 2: height of right subtree
 3: find max
 4: add 1
 */
/*template <class T>
class BinaryTree
{
public:
    Node<T> *root;
    T succeesor;
    bool isempty();
    void inorder(Node<T> *p);
    void preorder(Node<T> *p);
    void postorder(Node<T> *p);
    int treeheight(Node<T> *p);
    int treeNodescount(Node<T> *P);
    int treeleavescount(Node<T> *P);
    void insertion(T value,Node<T>* &P);
    //void delete(Node<T>* P);
    void deleteNode(T &ele);
    void destroyTree();
    bool search(T value, Node<T> *current);
    binaryTree(const BinaryTree<T> &obj);
    BinaryTree();
    ~BinaryTree();
};
template <class T>
void delete(Node<T>* p)
{
Node<T> *current;//pointer to traverse the tree
Node<T> *trailCurrent; //pointer behind current
Node<T> *temp; //pointer to delete the node
if (p == NULL)
cerr << "Error: The node to be deleted is NULL." << endl;
else if(p->llink == NULL && p->rlink == NULL)
{
temp = p;
p = NULL;
delete temp;
}
else if(p->llink == NULL)
{
temp = p;
p = temp->rlink;
delete temp;
}
else if(p->rlink == NULL)
{
temp = p;
p = temp->llink;
delete temp;
}
else
{
current = p->llink;
trailCurrent = NULL;
while (current->rlink != NULL)
{
trailCurrent = current;
current = current->rlink;
}//end while
p->info = current->info;
if (trailCurrent == NULL) //current did not move;
//current == p->llink; adjust p
p->llink = current->llink;
else
trailCurrent->rlink = current->llink;
delete current;
}//end else
}//end deleteFromTree
template <class T>
void BinaryTree<T>::deleteNode(const T& deleteItem)
{
Node<T> *current; //pointer to traverse the tree
Node<T> *trailCurrent; //pointer behind current
bool found = false;
if (root == NULL)
cout << "Cannot delete from the empty tree." << endl;
else
{
current = root;
trailCurrent = root;
while (current != NULL && !found)
{
if (current->info == deleteItem)
found = true;
else
{
trailCurrent = current;
if (current->info > deleteItem)
current = current->llink;
else
current = current->rlink;
}
}//end while
if (current == NULL)
cout << "The delete item is not in the tree." << endl;
else if (found)
{
if (current == root)
deleteFromTree(root);
else if (trailCurrent->info > deleteItem)
deleteFromTree(trailCurrent->llink);
else
deleteFromTree(trailCurrent->rlink);
}//end if
}
}//end deleteNode

template<class T>
void BinaryTree<T>::delete(T value,Node<T> *p)
{
        Node<T> *current;  //traverse the tree
        Node<T> *temp;    //using delte items from tree
        Node<T> *trailcurrent;  //pointer behind tree
        T swapi;
    if(p==NULL)
        {
            cout<<"There is no node how you can remove the values";
            retrun;
        }
    if(p->info==value)
    {
        if(p->llink==NULL && p->rlink==NULL)
        {
            temp=p;
            p=NUll;
            delete temp;
            return;
        }
    }
    if(value<P->info)
    {
        if(p->llink->info!=value)
        {
            delete(value,p->llink);
        }if(p->llink->info==value)
        {
            //for haaaaaaving no child
            if(p->llink->llink==NULL && p->rlink->rlink==NULL)
            {
                temp=p;
                p=NULL;
                delete temp;
                retrun;
            }
            if(p->llink->rlink==NULL && p->llink->llink!=NULL)
            {
                temp=p->llink;
                p->llink=p->llink->llink;
                delete temp;
                //swapi=p->llink->llink->info;
                //p->llink->info=swapi;
                return;
            }
               if(p->rlink->rlink!=NULL && p->llink->llink==NULL)
            {
                temp=p->llink;
                p->llink=p->llink->rlink;
                delete temp;
                //swapi=p->llink->llink->info;
                //p->llink->info=swapi;
                return;
            }
               if(p->rlink->rlink!=NULL && p->llink->llink!=NULL)
            {
                temp=p->llink;
                p->llink=p->llink->llink;
                delete temp;
                //swapi=p->llink->llink->info;
                //p->llink->info=swapi;

            }



        }
    }
    if(p->link==NULL)
    {
            temp=p;

    }





}

template <class T>
void BinaryTree<T>::insertion(T value,Node<T> *&P)
{
    Node<T> *temp;
    if (root == NULL)
    {
        root = new Node<T>;
        root->info = value;
        root->llink = root->llink = NULL;

        return;
    }
    if (value == p->info)
    {
        cout << "Duplicate beta g nhe allowed ";
        return;
    }

    if (value > p->info)
    {
        if (p->llink != NULL)
        {
            insertion(T value, p->rllink);
            return;
        }

        else
        {
            P->rlink = new Node<T>;
            p->rlink->info = value;
            p->rlink->rlink = NULL;
            p->rlink->rlink = NULL;
            return;
        }
        if (value < p->info)
        {
            if (p->llink != NULL)
            {
                insertion(T value, p->lllink);
                return;
            }

            else
            {
                P->llink = new Node<T>;
                p->llink->info = value;
                p->llink->llink = NULL;
                p->llink->llink = NULL;
                return;
            }
        }
    }
}
/*


template <class T>
bool BinaryTree<T>::search(T &value, Node<T> *current) //taking a value
{
    bool found = false;

    if (root == NULL)
    {
        cout << "there is no value ";
        return found;
    }
    else if (value == current->info)

    {
        found = true;
        return found;
    }
    else if (value > current->info)
    {
        search(T & value, current->rlink);
        return found;
    }
    else if (value < current->info)
    {
        search(T value, current->llink);
        return found;
    }

}


// template <class T>
// bool BinaryTree<T>::isempty()
// {
//     root == NULL;
// }

template <class T>
BinaryTree<T>::BinaryTree()
{
    root == NULL;
}

template <class T>
int height(Node<T> *p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}?
template <class T>
void BinaryTree<T>::inorder(Node<T> *p)
{
    if (p != NULL)
    {
        inorder(p->llink);
        //cout << p->info << " ";
        succeesor=p->info;
        inorder(p->rlink);
    }
}
template <class T>
void BinaryTree<T>::preorder(Node<T> *p)
{
    if (p !=NULL)
    {
        cout << p->info << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}
template <class T>
void BinaryTree<T>::postorder(Node<T> *p)
{
    if (p !=NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }
}
/*
int main()
{
    BinaryTree<int> obj;
    int choice;
    while (1)
    {
        cout << "-----*--------*------*-*----------*-----------*-----" << endl;
        cout << "Press 1 for  insertion:" << endl;
        cout << "Press 2 for deletion : " << endl;
        cout << "Press 3 for Inorder  : " << endl;
        cout << "Press 4 for Post order :" << endl;
        cout << "Press 5 for pre order :" << endl;
        cout << "Press 6 for tree Height :" << endl;
        cout << "Press 7 for Tree Nodes count :" << endl;
        cout << "press 8 for Tree leaves count :" << endl;
        cout << "Press 9 for searching a element in it: " << endl;
        cout << "Press 10 to exit ";
        cout << endl;
        cout << endl;
        cout << "Enter the Value ";
        cin >> choice;
        cout << endl;
        cout << "\nChup hn mahi chup hn ranjannn bola kesa yeah ranjaan\n"
             << endl;
        cout << endl;

        switch (choice)
        {
        case 1:
            obj.insertion(obj.root);
            break;
        case 2:
            //obj.deleteNode();
        case 3:
            obj.inorder(obj.root);
            break;
        case 4:
            obj.postorder(obj.root);
            break;
        case 5:
            obj.preorder(obj.root);
            break;
        case 6:
            obj.treeheight(obj.root);
            break;
        case 7:
            obj.treeNodescount(obj.root);
            break;
        case 8:
            obj.treeleavescount(obj.root);
            break;
        case 9:
            int value;
            cout << "Enter a value you want to search :";
            cin >> value;
            obj.search(value, obj.root);
            break;

        default:
            break;
        }
    }
}
*/
