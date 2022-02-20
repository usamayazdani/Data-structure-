void binary_tree::delete1(node *tem,int key)
{
	
    
    
	if(key>tem->data)
	{
		if(tem->right==NULL)
		{
			cout<<"NULL value not found";         
			return;
		}
		if(tem->right->data==key)
		{
	    
		if(tem->right->left==NULL &&tem->right->right==NULL)                               
		{  
		                                                                                                                                                             
		  node *tem1=tem->right;                                           
		  delete tem1;                            //alternative
		  tem1=NULL;
		  tem->right=NULL;
		  return;	
		}
		if(tem->right->left!=NULL && tem->right->right==NULL)
		{
		  node *tem2=tem->right;                                  //itha ponch gya 0
		  tem->right=tem2->left;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->right->left==NULL && tem->right->right!=NULL)
		{
		  node *tem2=tem->right;                                  //itha ponch gya 1
		  tem->right=tem2->right;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->right->left!=NULL && tem->right->right!=NULL)
		{
		  node* tem1=tem->right->right;
		  if(tem1->left==NULL)
		  {
		  	tem->right->data=tem1->data;
		  	if(tem1->right!=NULL)
			  { 
			    tem->right->right=tem1->right;      // if tem->right = NULL
			    delete tem1;
			    tem1=NULL;
			    return;
			  }
			  tem->right->right=NULL;
			  delete tem1;
			  tem1=NULL;
			  return;
			  
		  }
		  while(tem1->left->left!=NULL)
		  {
		    tem1=tem1->left;
		  }
		  tem->right->data=tem1->left->data;
		  if(tem1->left->right!=NULL)
		  {
		  	node* tem2=tem1->left;
		  	tem1->left=tem2->right;
		  	delete tem2;
		  	tem2=NULL;
		  	return;
		  }
		  node* tem2=tem1->left;
		  delete tem2;
		  tem2=NULL;
		  tem1->left=NULL;             //hello
		  return;
		}
    }
		if(tem->right!=NULL)
		{
			delete1(tem->right,key);                            
			return;
		}		
	}
	if(key<tem->data)
	{
		if(tem->left==NULL)
		{
			cout<<"NULL value not found";
			return;
		}
		if(tem->left->data==key)
	{
	    
		if(tem->left->left==NULL &&tem->left->right==NULL)                               
		{  
		                                                                                                                                                             
		  node *tem1=tem->left;                                           
		  delete tem1;                            //alternative
		  tem1=NULL;
		  tem->left=NULL;
		  return;	
		}
		if(tem->left->left!=NULL && tem->left->right==NULL)
		{
		  node *tem2=tem->left;                                  //itha ponch gya 0
		  tem->left=tem2->left;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->left->left==NULL && tem->left->right!=NULL)
		{
		  node *tem2=tem->left;                                  //itha ponch gya 1
		  tem->left=tem2->right;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->left->left!=NULL && tem->left->right!=NULL)
		{
		  node* tem1=tem->left->right;
		  if(tem1->left==NULL)
		  {
		  	tem->left->data=tem1->data;
		  	if(tem1->right!=NULL)
			  { 
			    tem->left->right=tem1->right;      // if tem->right = NULL
			    delete tem1;
			    tem1=NULL;
			    return;
			  }
			  tem->left->right=NULL;
			  delete tem1;
			  tem1=NULL;
			  return;
			  
		  }
		  while(tem1->left->left!=NULL)
		  {
		    tem1=tem1->left;
		  }
		  tem->left->data=tem1->left->data;
		  if(tem1->left->right!=NULL)
		  {
		  	node* tem2=tem1->left;
		  	tem1->left=tem2->right;
		  	delete tem2;
		  	tem2=NULL;
		  	return;
		  }
		  node* tem2=tem1->left;
		  delete tem2;
		  tem2=NULL;
		  tem1->left=NULL;             //hello
		  return;
		}
    }
		if(tem->left!=NULL)
		{
			
			delete1(tem->left,key);
			return;
		}
	}


}





/*
#include<iostream>
using namespace std;
	struct node
		{
			int data;
			node*left;
			node*right;
		};

class binary_tree
{
	
	
	public:
		node *root;
		binary_tree()
		{
			root=NULL;
		}
		void insert(node*,int);
		void display(node*);
		
		node* find_successer(node*,int);
		
		void delete1(node*,int);
};



//void binary_tree::find_successer(node *tem,int key)
//{
//	if(root==NULL)
//	{
//		cout<<"Tree is empty";
//		return;
//	}
//	if(tem->data==key)
//	{
//		cout<<"Yes value is found "<<tem->data;
//		if(tem->right!=NULL)
//		{
//			node *tem2=tem->right;
//			while(tem2->left!=NULL)
//			{
//				tem2=tem2->left;
//			}
//			cout<<"Successor is"<<tem2->data;
//		}
//		else
//		{
//			void binary_tree::new_search(node *tem)
//			{
//		       if(root==NULL)
//	            {
//		          cout<<"Tree is empty";
//		          return;
//	            }
//        	if(tem->info==key)
//	        {
//		    cout<<"Yes value is found "<<tem->info;
//		    return;
//	        }
//         	if(tem->info>key)
//	        {
//		        if(tem->right==NULL)
//		        {
//			        cout<<"NULL value not found";
//			        return;
//		        }
//		        if(tem->right!=NULL)
//		        {
//			        search(tem->left,key);
//			        return;
//		        }		
//	        }
//	        if(tem->info<key)
//         	{
//		       if(tem->left==NULL)
//		        {
//			        cout<<"NULL value not found";
//			        return;
//		        }
//		        if(tem->left!=NULL)
//	         	{
//		         	search(tem->left,key);
//			        return;
//		        }
//	        }
//				
//	        }				
//		}
//			
//	}
//
//	if(tem->data>key)
//	{
//		if(tem->right==NULL)
//		{
//			cout<<"NULL value not found";
//			return;
//		}
//		if(tem->right!=NULL)
//		{
//			find_successer(tem->right,key);
//			return;
//		}		
//	}
//	if(tem->data<key)
//	{
//		if(tem->left==NULL)
//		{
//			cout<<"NULL value not found";
//			return;
//		}
//		if(tem->left!=NULL)
//		{
//			find_successer(tem->left,key);
//			return;
//		}
//	}	
//}
//node* Binary_Tree::find_successor(int key){
//	node *temp = search(key , root);
//	node* successor=NULL;
//	if(temp==NULL){
//		cout<<"Key not Found "<<endl;
//		return NULL;
//	}
//		if(temp->right != NULL){
//			temp = temp->right;
//		while(temp->left != NULL){
//		temp=temp->left;
//		}
//		return temp;
//	}
//	
//	else{
//		node *temp2 = root;   
//		while(temp2 != temp){
//		              
//		if(temp2->info > temp->info){
//			successor = temp2;
//			temp2 = temp2->left;
//		}
//		else{
//			temp2 =  temp2->right;
//		}
//		
//	}
//	return successor;
//}
void binary_tree::delete1(node *tem,int key)
{
	// if(tem==NULL)
	// {
	// 	cout<<"Tree is empty";
	// 	return;
	// }
	if(tem->right->data==key)
	{
        cout<<"hello 1"<<endl;
		if(tem->right->left!=NULL && tem->right->right!=NULL)
		{
		  node* tem1=tem->right->right;
		  while(tem1->left->left!=NULL)
		  {
		    tem1=tem1->left;
		  }
		  tem->right->data=tem1->left->data;
		  node* tem2=tem1->left;
		  if(tem2->right!=NULL)
		  {
              cout<<"hello 2"<<endl;
		  	tem1->left=tem2->right;
		  	delete tem2;
		  	tem2=NULL;
		  	return;
		  }
		  delete tem2;
		  tem2=NULL;
		  return;
		}
		if(tem->right->left==NULL && tem->right->right!=NULL)
		{
            cout<<"hello 3"<<endl;
		  node *tem1=tem->right;
		  tem->right=tem1->right;
		  delete tem1;
		  tem1=NULL;
		  return;	
		}
		if(tem->right->left!=NULL && tem->right->right==NULL)
		{
            cout<<"hello 4"<<endl;
		   node*tem1=tem->right;
		   tem->right=tem1->left;
		   delete tem1;
		   tem1=NULL;
		  return;	
		}
		if(tem->right->left==NULL &&tem->right->right==NULL)
		{
            cout<<"hello 5"<<endl;
		  node *tem1=tem->right;
		  delete tem1;
		  tem1=NULL;
		  tem->right=NULL;
		  return;	
		}
	}
	
	if(tem->left->data==key)
	{
		if(tem->left->left!=NULL && tem->left->right!=NULL)
		{
            cout<<"hello 6"<<endl;
		  node* tem1=tem->left->right;
		  while(tem1->left->left!=NULL)
		  {
		    tem1=tem1->left;
		  }
		  tem->left->data=tem1->left->data;
		  if(tem1->left->right!=NULL)
		  {
              cout<<"hello 8"<<endl;
		  	node* tem2=tem1->left;
		  	tem1->left=tem2->right;
		  	delete tem2;
		  	tem2=NULL;
		  	return;
		  }
		  node* tem2=tem1->left;
		  delete tem2;
		  tem2=NULL;
		  tem1->left=NULL;             //hello
		  return;
		}
		
		if(tem->left->left!=NULL &&tem->left->right==NULL)
		{
            cout<<"hello 9"<<endl;
		  node *tem2=tem->right;
		  tem->left=tem2->right;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->left->left==NULL &&tem->left->right!=NULL)
		{
            cout<<"hello 10 "<<endl;
		   node*tem2=tem->left;
		   tem->left=tem2->right;
		   delete tem2;                   //hello2
		   tem2=NULL;
		   return;	
		}
		// Case 1
		if(tem->left->left==NULL && tem->left->right==NULL)                               
		{  
		  cout<<"Hello 2";                                                                                                                                                           
		  node *tem1=tem->left;                                           
		  delete tem1;                            //alternative
		  tem1=NULL;
		  tem->left=NULL;
		  return;	
		}
		  
		
		
	}
	
	
	
	if(key>tem->data)
	{
		if(tem->right==NULL)
		{

            cout<<"hello 11 "<<endl;
			cout<<"NULL value not found";
			return;
		}
		if(tem->right!=NULL)
		{
            cout<<"hello 12 "<<endl;
			delete1(tem->right,key);
			return;
		}		
	}
	if(key<tem->data)
	{
        cout<<"hello 13"<<endl;
		if(tem->left==NULL)
		{
			cout<<"NULL value not found";
			return;
		}
		if(tem->left!=NULL)
		{
			cout<<"HELLO!";
			delete1(tem->left,key);
			return;
		}
	}
}


void binary_tree::insert(node*tem,int key)
{
	if(root==NULL)
	{
		tem=new node;
		root=tem;
		tem->left=NULL;
		tem->right=NULL;
		tem->data=key;
		return;
	}
	if(tem->data==key)
	{
		cout<<"You have entered the same value";
		return;
	}
	if(key>tem->data)
	{
		if(tem->right!=NULL)
		{
			insert(tem->right,key);
			return;
		}
		else
		{
			tem->right=new node;
			tem->right->right=NULL;
			tem->right->left=NULL;
			tem->right->data=key;
			return;
		}
	}
	if(key<tem->data)
	{
		if(tem->left!=NULL)
		{
			insert(tem->left,key);
			return;
		}
		else
		{
			tem->left=new node;
			tem->left->right=NULL;
			tem->left->left=NULL;
			tem->left->data=key;
			return;
		}
	}
}
void  binary_tree::display(node*tem)
{
	if(root==NULL)
	{
		cout<<"NO display";
		return;
	}
	if(tem->left!=NULL)
	{
		display(tem->left);
	}
	cout<<tem->data<<" ";
	if(tem->right!=NULL)
	{
		display(tem->right);
	}
	return;
}
int main()
{
	binary_tree b;
	b.insert(b.root,100);
	b.insert(b.root,95);
	b.insert(b.root,94);
	b.insert(b.root,98);
	b.insert(b.root,97);
	b.insert(b.root,99);
	b.insert(b.root,96);
	b.display(b.root);
	b.delete1(b.root,94);
	b.display(b.root);
// b.delete1(b.root,20);
//	cout<<endl;
//	b.display(b.root);
//	b.delete1(b.root,9);
//	cout<<endl;
//	b.display(b.root);
}