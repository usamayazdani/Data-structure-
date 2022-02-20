/*
It simple algorith where we have array first we consider we hav two array's
1: sorted and unsorted 
in what nothing in the sorted then took first item and cmp with all other element 
if it less swap not move to next elements

*/
#include<iostream>
using namespace std;
int main()
{
    int arr[10]={5,3,7,2,6,1,8,4,9,10};
    int temp;
    for (int i = 0; i < 10; i++)
    {
    
        for (int j = i+1; j < 10; j++)
        {
            if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                
        }
        
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<"At index : "<<i<<" : the value is -> "<<arr[i]<<"\n ";
    }
    
    


    return 0;
}