#include<iostream>
using namespace std;
class array
{
private:
    int len,max;
    int *p= new int [10];
    int *temp,*current;
public:
    array()
    {
        cout<<"Enter the size of array : ";
        cin>>max;
        current=p;
        temp=p;
        len=0;

    }
    void insert(int ele,int index)
    {
        int counter=0;
        for(int i=0; i<max; i++)
        {
            if(counter==index)
            {
                *(p+i)=ele;

            }
            counter++;

        }
        len=len+1;
    }
    void print()
    {
        for(int i=0; i<len; i++)
        {
            cout<<*(p+i)<<" ";
        }
    }
    //move the array 2 times
        void rotaion()
        {
            int temp=p[0];
            for(int i=0; i<(len-1); i++)
            {
                *(p+i)=*(p+i+1);
            }
            *(p+len-1)=temp;
        }
        void rotaion_time()
        {
            int n;
            
            cout<<"how many time you want to rotate this array : ";
            cin>>n;
            for(int i=0; i<n; i++)
                array::rotaion();
        }
        int *arr=new int [len];
        void multipication_array()
        {
            for(int i=0; i<(len-1); i++)
                *(arr+i)=array::rotaion();
            for(int i=0; i<len; i++)
                *(arr+i)+=i**(arr+i);
        }
          void print2()
    {
        
        
            cout<<*(arr)<<" ";
        
    }
        ~array()
        {
            delete  arr; 
            delete [] p;
        }

};
int main(){
array obj;
obj.insert(1,0);
obj.insert(2,1);
obj.insert(3,2);
obj.insert(4,3);
cout<<"Simple array  : ";
obj.print();
obj.rotaion_time();
cout<<"Rotation array : ";
obj.print();
obj.multipication_array();
obj.print2();
return 0;
}