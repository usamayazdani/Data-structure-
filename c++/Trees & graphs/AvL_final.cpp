#include<iostream>
using namespace std;
struct Trunk
{
    Trunk *prev;
    string str;
    Trunk(Trunk *prev,string str)
    {
        this->prev=prev;
        this->str=str;

    }
};
template<class T>
struct Node
{
    T data;
    Node *left;
    Node *right;
};
template<class T>
class Avl
{
public:
    Node<T> *root;
    T val;
    T height(Node<T> *);
    void insertion(T,Node<T>* &);
    void inoder(Node<T> *);
    T Balance_Factor(Node<T> *);
    Node<T> *Left_rotation(Node<T> *&);
    Node<T> *Right_rotation(Node<T> * &);
    void printTree(Node<T>* &,Trunk *prev,bool isRight);
    void showTrunks(Trunk *p);
    void Inorder(Node<T> *);
    Node<T> *deletion(Node<T> *,T);
    T second_search(T,Node<T> * &);
    Node<T> *search(T,Node<T>* &);
    Node<T> *successor(T);
    Avl()
    {
        root=NULL;
    }
    ~Avl()
    {
        delete root;
    }

};
template<class T>
Node<T> * Avl<T>::Right_rotation(Node<T> * &temp)
{
    Node<T> *temp2=temp->left;
    temp->left=temp2->right;
    temp2->right=temp;
    temp=temp2;
    return temp;
}
template<class T>
Node<T> *Avl<T>::Left_rotation(Node<T> * &temp)
{
    Node<T> *temp2=temp->right;
    temp->right=temp2->left;
    temp2->left=temp;
    temp=temp2;
    return temp;
}
template<class T>
T Avl<T>::height(Node<T> *temp)
{
    if(temp==NULL)
        {
            return 0;
        }
    else
        {
            int lefti=height(temp->left);
            int righti=height(temp->right);
            if(lefti>righti)
            {
                return lefti+1;
            }else
            {
                return righti+1;
            }
        }
}
template<class T>
T Avl<T>::Balance_Factor(Node<T> *temp)
{
    int left=0;
    int right=0;
    if(temp->left!=NULL)
    {
        left=height(temp->left);
    }
    if(temp->right!=NULL)
    {
        right=height(temp->right);
    }
    return left-right;
}
template<class T>
void Avl<T>::insertion(T key,Node<T>* &temp)
{
    if(temp==NULL)
    {
        temp=new Node<T>;
        temp->left=temp->right=NULL;
        temp->data=key;
        return;
    }
    if(temp->data==key)
    {
        cout<<"The key is already exist chlo baag jaou ";
        return;
    }
    else if(key<temp->data)
    {
        insertion(key,temp->left);
    }
    else if(key>temp->data)
    {
        insertion(key,temp->right);
    }
    T balance=Balance_Factor(temp);
    //case 1:
    if(balance>1 && key<temp->left->data)
    {
                //left left

        //single right rotation
         Right_rotation(temp);
        return;
    }
    //case 2:
    if(balance>1 && key>temp->left->data)
    {
        //left right
        //first left rotation then right rotation
        //and pass it like          before rotation
                 //        45         ; this is tree where 45 is temp       //
            //       11               ;  11 temp->left                  Left
        //                13          ; 13  temp->left->right                   Right
                        //pasing into temp->left  which means 11 and it will chng 13 then 13->left 11

                        Left_rotation(temp->left);
            //now right rotation b/w 13 and 45
             Right_rotation(temp);
             return;
                        //After rotation
        //           13
        //     11          45
    }
    // case 3:
    if(balance< -1 && key<temp->right->data)
    {
        //Right left case
        Right_rotation(temp->right);
        Left_rotation(temp);
        return;
    }
    //case 4:
    if(balance< -1 &&key >temp->right->data)
    {
        Left_rotation(temp);
        return;
    }
    return;
}

///Trunk code
template<class T>
void Avl<T>::showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}
// Recursive function to print binary tree
// It uses inorder traversal
template<class T>
void Avl<T>::printTree(Node<T> *&temp, Trunk *prev, bool isRight)
{
    if (temp == NULL)
        return;

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(temp->right, trunk, true);

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
    cout << temp->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(temp->left, trunk, false);
}
template<class T>
void Avl<T>::Inorder(Node<T> *temp)
{
    if(temp!=NULL)
    {
        Inorder(temp->left);
        cout<<temp->data<<" ";
        Inorder(temp->right);

    }
}

template<class T>
Node<T> *Avl<T>::successor(T data)
{
    Node<T> *point_01, *point_02;
    T success_01;
    point_01 = search(data,root);
    if (point_01 == NULL)
    {
        cout << "Nodata exist";
        return 0;
    }
     if (point_01->right != NULL)
    {
        point_01 = point_01->right;
        while (point_01->left!=NULL)
        {
            point_01=point_01->left;
        }
        return point_01;
    }
     //pre decesssor

    /*if (point_01->right == NULL)
    {
        cout << " HERe i'm reacehed" << endl;
        second_search(data, root);
        return val;
    }*/
}
template<class T>
T Avl<T>::second_search(T key, Node<T> *&temp)
{

    if ((temp->left != NULL) && (key < temp->data))
    {
        val = temp->data;
        return second_search(key, temp->left);
    }
    if ((temp->right != NULL) && (key > temp->data))
    {
        val = temp->data;
        return second_search(key, temp->right);
    }
    if (temp->data == key)
    {
        return val;
    }
    cout << "data is in every case ";
    return val;
}
template<class T>
Node<T> *Avl<T>::search(T key, Node<T> *&temp)
{
    if (temp == NULL)
    {
        cout << "The Tree is Empty " << endl;
        return NULL;
    } // Search Function

    if (temp->data == key)
    {
        cout << "data Found " << endl;
        return temp;
    }

    if ((key > temp->data) && (temp->right != NULL))
    {
        return search(key, temp->right);
    }

    if ((key < temp->data) && (temp->left != NULL))
    {
        return search(key, temp->left);
    }

    if ((temp->right == NULL) && (temp->left == NULL))
    {
        cout << "data Not Found" << endl;
        return NULL;
    }
}

template<class T>
Node<T> * Avl<T>:: deletion(Node<T> * temp, T key) {
    // base case
    if (temp == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    else if (key < temp ->data) {
      temp -> left = deletion(temp -> left, key);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > temp ->data) {
      temp -> right = deletion(temp -> right, key);
    }
    // if key is same as root's key, then This is the node to be deleted
    else {
      // node with only one child or no child
      if (temp -> left == NULL) {
        Node<T> * temp2 = temp -> right;
        delete temp;
        return temp2;
      } else if (temp -> right == NULL) {
        Node<T> * temp2 = temp -> left;
        delete temp;
        return temp2;
      } else {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<T> * temp2 = successor(key);
        // Copy the inorder successor's content to this node
        temp ->data = temp2 ->data;
        // Delete the inorder successor
        temp -> right = deletion(temp -> right, temp2 ->data);
        //deletion(temp->right, temp-data);
      }
    }

    T bf = Balance_Factor(temp);
    // Left Left Imbalance/Case or Right rotation
    if (bf == 2 && Balance_Factor(temp -> left) >= 0)
      return Right_rotation(temp);
    // Left Right Imbalance/Case or LR rotation
    else if (bf == 2 && Balance_Factor(temp -> left) == -1) {
      temp -> left = Left_rotation(temp -> left);
      return Right_rotation(temp);
    }
    // Right Right Imbalance/Case or Left rotation
    else if (bf == -2 && Balance_Factor(temp -> right) <= -0)
      return Left_rotation(temp);
    // Right Left Imbalance/Case or RL rotation
    else if (bf == -2 && Balance_Factor(temp -> right) == 1) {
      temp -> right = Right_rotation(temp -> right);
      return Left_rotation(temp);
    }

    return temp;
  }
int main()
{
    Avl<float>  obj;
	obj.insertion(1.2 , obj.root);
	obj.insertion(2.2, obj.root);
	obj.insertion(3.3, obj.root);

	/*obj.insertion(11,obj.root);
	obj.insertion(3,obj.root);
	obj.insertion(2,obj.root);
	obj.insertion(1,obj.root);
	obj.insertion(56,obj.root);
	//obj.insertion(45,obj.temp);
	obj.insertion(89,obj.root);
	obj.insertion(99,obj.root);
	obj.insertion(12,obj.root);
	obj.insertion(54,obj.root);
	*/
    obj.printTree(obj.root, NULL, false);
    //obj.deletion(obj.root,45);
    cout<<"after deletion the tree is \n";
    obj.printTree(obj.root, NULL, false);

    return 0;
}
