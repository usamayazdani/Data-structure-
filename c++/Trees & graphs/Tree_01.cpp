// It is a sub type of Graph
//BT -which have two nodes or less 
//BST- left value is smaller and right value is greater 
//root -the first element

#include<iostream>

using namespace std;
struct Node
{
    int info;
    Node *right;
    Node *left;
};
class Tree{

    public:
    Tree()
{
    
    root=NULL;  
}
    Node * root;
    
    
    void insetion(int key,Node *&temp);   
    Node *search(int  key, Node *&temp);
};

void Tree::insetion(int key,Node *&temp)
{
    
    if(temp == NULL)
    {
        temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;
        if(root==NULL)      //for check root is null or not 
        {
            root=temp;
        }
        return;
    }
    //Duplication 
    if(temp->info==key)
    {
        cout<<"value is already there"<<endl;
        return;
    }
    //check for grater value  
    
    if(key>temp->info)
    {   //if(temp->left==NULL)
        //{
            insetion(key,temp->left);
            return;
        //}
  //      insetion(key,temp->left);
        
    }
    //check for smaller
    if(key <temp->info)
    {
        //if(temp->right==NULL)
        //{
            insetion(key,temp->right);
            return;

        //}
    //    insetion(key,temp->right);
    
    }
   // void Tree::search
}
Node *Tree::search(int key,Node *&temp)
{
    if(root==NULL){
    cout<<"Tree is empty";
    return NULL;
    }
    if(key=temp->info)
    {
        return temp;
    }
    if((temp->left!=NULL)&&(key<=temp->info))
    {
        return search(key,temp->left);
    }
     if((temp->right!=NULL)&&(key<=temp->info))
    {
        return search(key,temp->right);
    }

    cout<<"value not Found";
    return NULL;
}
int main()
{
    Tree obj;

    obj.insetion(100,obj.root);
    obj.insetion(15,obj.root);
    obj.insetion(17,obj.root);
    obj.search(13,obj.root);
}
/*
// It is a sub type of Graph
//BT -which have two nodes or less 
//BST- left value is smaller and right value is greater 
//root -the first element
#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *right;
    Node *left;
};
class Tree{

    public:
    Tree()
{
    
    root=NULL;  
}
    Node * root;
    
    
    void insetion(int key,Node *&temp);   
    void search(int  key, Node *temp);
};

void Tree::insetion(int key,Node *&temp)
{
    
    if(temp == NULL)
    {
        temp=new Node;
        temp->info=key;
        temp->left=temp->right=NULL;
        if(root==NULL)      //for check root is null or not 
        {
            root=temp;
        }
        return;
    }
    //Duplication 
    if(temp->info==key)
    {
        cout<<"value is already there"<<endl;
        return;
    }
    //check for grater value  
    
    if(key>temp->info)
    {   if(temp->left==NULL)
        {
            temp->left = new Node;
            temp->left->info=key;
            temp->left=temp->right=NULL;

            return;
        }
        else{
            insetion(key,temp->left);
        }
  //      insetion(key,temp->left);
        
    }
    //check for smaller
    if(key <temp->info)
    {
        if(temp->right==NULL){
            
                        temp->right = new Node;
                        temp->right->info=key;
                    temp->left=temp->right=NULL;
                    return;

        }else
            {
            insetion(key,temp->right);

            }
    //    insetion(key,temp->right);
    
    }
   // void Tree::search
}
int main()
{
    Tree obj;

    obj.insetion(100,obj.root);
    obj.insetion(15,obj.root);
    obj.insetion(17,obj.root);
}*/
/*
void Bst::insertion(int value,Node* &temp)
{
    Node *temp;
    if (root == NULL)
    {
        root = new Node;
        root->info = value;
        root->left = root->right= NULL;

        return;
    }
    if (value == temp->info)
    {
        cout << "Duplicate beta g nhe allowed ";
        return;
    }

    if (value > temp->info)
    {
        if (temp->left != NULL)
        {
            insertion(value, temp->right);
            return;
        }

        else
        {
            temp->right = new Node;
            temp->right->info = value;
            temp->right->right = NULL;
            temp->right->right = NULL;
            return;
        }
        if (value < temp->info)
        {
            if (temp->left != NULL)
            {
                insertion(value, temp->left);
                return;
            }

            else
            {
                temp->left = new Node;
                temp->left->info = value;
                temp->left->left = NULL;
                temp->left->left = NULL;
                return;
            }
        }
    }
}
*/
/*
void Bst :: insertion( Node *temp)
{
  if( root==NULL )
   {
     temp=new Node;
     temp->info = number;
     temp->left=NULL;
     temp->right=NULL;
     root=temp;
     return;
   }

  if( temp->info==number )
   {
      cout<<" \n Given number is already present in tree.\n";
      return;
   }
   if(temp->info > number)
   {
      if( temp->left!=NULL )
       {
		 insertion(temp->left);
		 return;
       }
      else
    {
	 temp->left=new Node;
	 temp->left->info = number;
	 temp->left->left=NULL;
	 temp->left->right=NULL;
	 return;
    }
   }
   if(temp->info < number)
   {
      if( temp->right!=NULL )
       {
		 insertion(temp->right );
		 return;
       }
      else
       {
	 temp->right=new Node;
	 temp->right->info = number;
	 temp->right->left=NULL;
	 temp->right->right=NULL;
	 return;
       }
   }


}*/
/*

Node *find_successor(int key)
{

}*/
/*
void Bst::deletion(int key, Node *&temp)
{
    Node *temp2 = search(key, temp);
    cout << "Val 1" << temp2->info << endl;
    //------case 1---------//
    if (temp2 == NULL)
    {
        cout << "The value dosent exist how you delete it";
        return;
    }
    //-------case 2-------//
    if (key == temp2->info)
    {
        //-----case 1-----//
        if ((temp2->left == NULL) && (temp2->right == NULL))
        {
            cout << "First case " << endl;
            delete temp2;
            temp2 = NULL;

            return;
        }
        if ((temp2->left != NULL) && (temp2->right == NULL))
        {
            cout << endl
                 << "2nd case " << endl;

            temp7 = temp2->left->left;
            temp2 = temp7;
            delete temp7;
        }
        if ((temp2->left == NULL) && (temp2->right != NULL))
        {
            cout << endl
                 << "3nd case " << endl;
            temp7 = temp2->right->right;
            temp2 = temp7;
            delete temp7;
        }
        if ((temp2->left != NULL) && (temp2->right != NULL))
        {
            //Node *Garbage;
            //Garbage=temp2;
            cout << endl
                 << "4  case " << endl;
            temp7 = successor(key);
            cout << "Suceessor is  " << temp7->info << endl;

            temp2->info = temp7->info;
            //delete temp7;
            return;
        }
    }
    //---------case 3------//
    if (key > temp2->info)
    {
        delete (key, temp2->right);
        return;
    }
    //--------case 4------//
    if (key < temp2->info)
    {
        delete (key, temp2->left);
        return;
    }
}*/
node* Binary_Tree::find_successor(int key){
	node *temp = search(key , root);
	node* successor=NULL;
	if(temp==NULL){
		cout<<"Key not Found "<<endl;
		return NULL;
	}
		if(temp->right != NULL){
			temp = temp->right;
		while(temp->left != NULL){
		temp=temp->left;
		}
		return temp;
	}
	
	else{
		node *temp2 = root;   
		while(temp2 != temp){
		              
		if(temp2->info > temp->info){
			successor = temp2;
			temp2 = temp2->left;
		}
		else{
			temp2 =  temp2->right;
		}
		
	}
	return successor;
}