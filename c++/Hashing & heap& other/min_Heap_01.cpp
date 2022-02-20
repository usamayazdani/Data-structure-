#include<iostream>
using namespace std;

struct Node_
{
    int data;
    Node_ *left,*right;
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

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class Min_Heap
{
    private:
    int Node__counter;
    int height;
    int local_height;
    Node_ *temp;
    int flag;
    public:
    Node_ *root;
    //------------constructor
    Min_Heap()
    {
        temp=root=NULL;
        Node__counter=height=local_height=0;
        flag=0;
    }
    //------------destructor
    void delAll(Node_ *temp)
    {
	if (root == NULL)
	{
		return;
	}
	if (temp->left!=NULL)
		delAll(temp->left);
	if (temp->right!=NULL)
		delAll(temp->right);
	    delete temp;
    }

    ~Min_Heap()
    {
    delAll(root);

    }

    void insertion(Node_ *,int);
    void inorder(Node_ *);
    int power(int ,int);
    void printTree(Node_ *,Trunk *,bool);



};
// It uses inorder traversal
void Min_Heap::printTree(Node_ *root, Trunk *prev, bool isRight)
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
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}


void Min_Heap::insertion(Node_ *temp,int key)
{

    //first bcz always zero
    if (temp==root)
    {
        flag=0;

    }

    if(root==NULL)
    {

        root=new Node_;
        root->data=key;
        root->left=NULL;
        root->right=NULL;
        height=0;
        Node__counter+=1;
        temp=root;
        return;
    }
    if(temp->data>key)
    {
        int swap=key;
        key=temp->data;
        temp->data=swap;
    }
    if(((power(2,height+1))-1)==Node__counter && temp->left==NULL)
    {

        while(temp->left != NULL)
		{
			if (temp->data > key)
			{
				int num = key;
				key = temp->data;
				temp->data = num;
			}
			temp = temp->left;
		}
        Node_ *temp2=new Node_;
        temp2->data=key;
        temp2->left=NULL;
        temp2->right=NULL;
        height+=1;
        flag=1;
        Node__counter+=1;
        temp->left=temp2;
        if(temp->data>temp->left->data)
        {

            temp->left->data=temp->data;
            temp->data=key;
        }
        return;

    }

    if(height-local_height==1 && temp->right==NULL && temp->left!=NULL)
    {

        Node_ *temp2=new Node_;
        temp2->data=key;
        temp2->left=NULL;
        temp2->right=NULL;
        Node__counter+=1;
        temp->right=temp2;
        flag=1;
        if(temp->data>temp->right->data)
        {
            temp->right->data=temp->data;
            temp->data=key;
        }
        return;
    }
     if(height-local_height==1 && temp->right==NULL && temp->left==NULL)
    {
        //cout<<key<<" ";
        Node_ *temp2=new Node_;
        temp2->data=key;
        temp2->left=NULL;
        temp2->right=NULL;
        Node__counter+=1;
        temp->left=temp2;
        flag=1;
        if(temp->data>temp->left->data)
        {
            temp->left->data=temp->data;
            temp->data=key;
        }

        return;
    }
    if(temp->left!=NULL && flag==0)
    {
        local_height+=1;
        insertion(temp->left, key);
        local_height-=1;
    }
     if(temp->right!=NULL && flag==0)
    {
        local_height+=1;
           // cout<<"OK"<<key<<" ";
        insertion(temp->right,key);
        local_height-=1;
    }
    if(temp==root)
    {
        flag=0;
    }



    return;

}
int Min_Heap::power(int num, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result = result * num;
	}
	return result;
}


void Min_Heap::deletion_with_array()
{
    int value;
    value=arr[0];
    arr[0]=arr[size-1]
    size-=1;
    delete value;
    ///if any maslta created in deletion or break the rules  
    for(int i=0; i<size; i++){
    if(arr[i]>arr[2i+1] || arr[i]>arr[2i+2])
    
    {
        if(arr[2i+1]<arr[2i+2]){
        int swap=arr[i];
        arr[i]=arr[2i+1];
        arr[2i+1]=arr[i];
        }else
        {
            int swap=arr[i];
            arr[i]=arr[2i+2];
            arr[2i+2]=swap;
        }
        
    }
    
    
    }
}
/*
///A recursive approch 
 void MinHeapify(int i) {
    int l = 2i+1;
    int r = 2i+2;
    int smallest = i;
    if (l < size && arr[l] < arr[i])
      smallest = l;
    if (r < size && arr[r] < arr[smallest])
      smallest = r;
    if (smallest != i) {
      swap( & harr[i], & harr[smallest]);
      MinHeapify(smallest);
    }
  }

*/

void Min_Heap::deletion(Node_ *temp,int key)
{

    //case when they have no child
    if(temp->data==key && temp->left==NULL && temp->right==NULL)
    {
        delete temp;
        return;
    }
    //left child
    if(temp->left->data==key && temp->left->left==NULL && temp->left->right==NULL)
    {
        Node_ *temp2=temp->left;
        temp->left=NULl;
        delete temp2;
        return;

    }
    //right child
    if()


}














int main()
{
    Min_Heap obj;
    obj.insertion(obj.root,1);
    obj.insertion(obj.root,8);
    obj.insertion(obj.root,7);
    obj.insertion(obj.root,5);
    obj.insertion(obj.root,3);
    obj.insertion(obj.root,2);
    obj.insertion(obj.root,9);
    obj.insertion(obj.root,6);
    obj.insertion(obj.root,4);
    obj.printTree(obj.root,NULL,false);
    return 0;
}
