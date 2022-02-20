#include<iostream>
using namespace std;
void rec(int &max, int intArray[], int index)
{   

      if (index==7){return;}
        if(max<intArray[index])
        {
                max=intArray[index];
                 rec(max,intArray,index+1);
            }else
        {
 rec(max,intArray,index+1);        }

}
int main()
{
    int intArray[10] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};
    int max,index;
    max=intArray[0];
    rec(max,intArray,index);
    cout<<max;
}
/*
class Array
{
    public:
    
    int max;
    int lowerindex;
    int upperindex;

    Array(){for (int i = 0; i < 7; i++)
    {
        arr[i]=0;
    }
    lowerindex=0;
    upperindex=0;
    max=arr[0];
    }
    void gets()
    {
        for (int i = 0; i < 7; i++)
        {
            cin>>arr[i];
        }
        

    }
    void recursion(int arr[lowerindex])
    {
        if (lowerindex==7){return;}
        if(max<arr[lowerindex])
        {
                max=arr[lowerindex];
                recursion(arr[loweindex+1]);
        }else
        {
            recursion(arr[lowerindex+1]);
        }


    }
    ~Array()
    {
        cout<<max<<endl;
    }
};
int main()
{
    int arr[8];
    Array obje;
    
    obje.gets();
    obje.recursion(arr[0]);
    return 0;
}*/