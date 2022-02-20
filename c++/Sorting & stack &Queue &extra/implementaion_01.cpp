#include<iostream>
using namespace std;

class STACK
{
    private:
    int *STACKtop;      //max _Size find
    int *list;              
    int MAX_size;
    int *temp;
    public:
        
        STACK()
        {
            
            cout<<"input size of array : "<<endl;
            cin>>MAX_size;
            STACKtop=temp = NULL;
            list=new int[MAX_size];
            
        }

        void push()
        {

            if(list+(MAX_size)==STACKtop)
            {
                cout<<"STACK overflow";
                return ;
            }
                        
                  
            if(STACKtop == NULL)
            {
              STACKtop = list;
              cout <<"Eter value :  "<<endl;
              cin>>*STACKtop;  
                return ;
            }
            STACKtop++;
            cout <<"Eter value :  "<<endl;
            cin>>*STACKtop;    
                    
        }
        
        void pop()
        {
        	if(STACKtop == NULL)
        	{
        		cout<<"underflow"<<endl;
        		return;
			}
			
			if(STACKtop ==list)
			{
				STACKtop = NULL;
				return;
			}
			STACKtop--;
			return;			
		}
		void print()
		{
		
			while(STACKtop != NULL)
			{
				cout<<*STACKtop<<endl;
				pop();
			}
			
		}
};

int main()
{
    STACK OBJ;
    OBJ.push();
    OBJ.push();
    OBJ.push();
    OBJ.push();
    OBJ.push();
    OBJ.print();
    OBJ.pop();
    return 0;
    
}

