#include<iostream>
using namespace std;
int  recursion(int num)
{
    int j=1;
    cout << *"+*"<<endl;
    if(num == 0)
        return 0;
    else
    {
        j++;
        return recursion(num-1);
        
    }
}

void recursive(int x, int y, int temp)
{

  if(x > 0) {
      
    if(y > 0) {
      cout <<"*";
      recursive(x,y-1,temp);
      
    }
    else {
      y = temp;
      recursive(x-1,y,temp);
    }
    
  }
}
/*
hell all there is kichri type for printing pattern in single fucntion 
void printpattert(int x, int y)
{
    const int d=x;
    int j=1,o;
    y=d-(x-y);
    j=y-(y-1);
    o=0;
    if(x<1)
        return;
    if(0<j)
    {
        cout<<"*";
        o++;
        printpattert(x-1,y+1);
    }else
    {
        cout<<endl;
        printpattert(x-1,y);
    }

}
*/

 
// function to print a row
void printn(int num)
{
    // base case

    if (num == 0)
     
        return;
 

    cout << "* ";
    
    // recursively calling printn()
    printn(num - 1);
}
 
// function to print the pattern
void pattern(int n, int i)
{
    // base case
    if (n == 0)
        return;
    printn(i);
    cout << endl;
 
    // recursively calling pattern()
    pattern(n - 1, i + 1);
}
void printpattern(int n,int i)
{
    
    i=n-i;
    //base case
    if(n<1)
        return;
    //print all the first rows 
    if(i<n){
        cout<<" *";
        
        printpattern(n,i+1);
    }
    else
    {
        cout<<endl;
        i=1;
        printpattern(n-1,i+1);
    }
    
}

//int recursion2(int num)
int main()
{
    printpattert(5,1);
    //printpattern(5,1);
    //int num;
    //num=10;
   // recursion(5);
    //recursive(5,5,1);
    /*for (int i = 0; i <5; i++)
    {
        for (int  j = 0; j <=i; j++)
        {
            cout<<" * ";
        }
        cout<<endl;

        
        
    }
    */
    return 0;
}
