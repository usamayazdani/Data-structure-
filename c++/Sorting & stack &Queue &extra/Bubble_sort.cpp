#include<iostream>
using namespace std;
void function(int arr[],int size)
{
    int j=0,k=1;
    for (int i=(size-1); i>=0; i--)
    {

        while (j<(size-1))
        {
        
                if(arr[j]>arr[k])
                {
                    int swap=arr[j];
                    arr[j]=arr[k];
                    arr[k]=swap;
                }
            
            k++;
            
            j++;
            
            
        }
        j=0;k=1;

        
    }
    for(int i=0; i<7; i++)
    {
        cout<<arr[i];
    }
}
int main() {
    int arr[7]={4,5,3,9,1,2,10};
    function(arr,7);
    return 0;
}