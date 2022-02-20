#include<iostream>
using namespace std;

class list
{
    private:
    int *top;
    int *stk;
    int size;
    int *temp;
    public:
        
        list()
        {
            
            cout<<"input size of array : "<<endl;
            cin>>size;
            top,temp = NULL;
            stk=new int[size];
            //top = stk;
            
            
        }
//        bool list_empty()
//        {
//            if(top == NULL)
//                return true ;
//            else
//                return false;
//            
//        }
//        bool list_full()
//        {
//            if(stk+(size-1 )==top)
//                return true;
//                else
//                return false;
//        }
        void push()
        {
//                if(list_full())
            if(stk+(size)==top)
            {
                cout<<"overflow";
                return ;
            }
                        
//            if(list_empty())
                  
            if(top == NULL)
            {
              top = stk;
              cout <<"Eter value :  "<<endl;
              cin>>*top;  
                return ;
            }
            top++;
            cout <<"Eter value :  "<<endl;
            cin>>*top;    
                    
        }
        
        void pop()
        {
        	if(top == NULL)
        	{
        		cout<<"underflow"<<endl;
        		return;
			}
			
			if(top ==stk)
			{
				top = NULL;
				return;
			}
			top--;
			return;			
		}
		void print()
		{
		
			while(top != NULL)
			{
				cout<<*top<<endl;
				pop();
			}
			
		}
};

int main()
{
    list ls;
    ls.push();
    ls.push();
    ls.push();
    ls.push();
    ls.push();
    ls.print();
    ls.pop();
    return 0;
//    ls.list_empty();
//    ls.list_full();    
    
}
// #include<iostream>
// #include<string>
// using namespace std;
// template<class T>
// class STACK
// {
// private:
//     T maxsize;
//     T stacktop;
//     T *List;

// public:
//     STACK();
//     bool isempty();
//     bool isfull();
//     void Push(T);
//     void Pop();
//     void print();
//     void Top();
//     ~STACK();
// };
// template<class T>
// STACK<T>::STACK()
// {
//     stacktop=0;
//     cout<<"Enter the size of stack :";
//     cin>>maxsize;
//     List=new T[maxsize];
// }
// template<class T>
// bool STACK<T>::isempty()
// {
// return(stacktop==0);
// }
// template<class T>
// bool STACK<T>::isfull()
// {
//     return(stacktop==maxsize);
// }

// template<class T>
// void STACK<T>::Push(T newitem)
// {
//     if(!isfull())
//     {
//         List[stacktop]=newitem;
//         stacktop++;
//     }else
//         cout<<"Cannot add to a full stack "<<endl;
// }
// template<class T>
// void STACK<T>::Pop()
// {
//     if(!isempty())
//     {
//         stacktop--;
//     }else
//         {
//             cout<<"STAck underflow "<<endl;
//         }
// }
// template <class T>
// void STACK<T>::print()
// {
//     while (stacktop!=NULL)
//     {
//         cout<<stacktop<<endl;
//     }
    
//     // for(int i=0; i<maxsize; i++)
//     // {
//     //     //cout<<stacktop<<endl;
//     //     cout<<List[i]<<endl;
//     // }
// }


// template<class T>
// STACK<T>::~STACK()
// {
//     delete [] List;
// }

// int main(){
// STACK <int> obj;
// obj.Push(12);

// obj.Push(13);
// obj.Push(15);

// obj.print();
// obj.Pop();
// obj.Pop();
// obj.Pop();

// //2
// obj.print();
// return 0;
// }
