#include<iostream>
using namespace std;
int Linear_Search(int *arr,int size,int key)
{
    int i=0;
    while (i<size)
    {
        if(arr[i]==key)
        {
            return i;
        }else
        {
            i++;
        }

    }



}
int main()
{
     int arr[10]={5,9,17,23,25,45,59,63,71,89};
    cout<<Linear_Search(arr,10,71);
    return 0;
}
