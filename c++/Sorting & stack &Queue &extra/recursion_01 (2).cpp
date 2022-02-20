#include<iostream>
using namespace std;
// Base case --> a condition through which function should stop
// Forward pass and backward pass
//Forward pass ->It is pass where  our function is executing first time when we call same functon from inside then function copies are creating on the same statements
//Backward pass -> when our condition is finished the same remaining condition is executing know
//we cant use static Global and loops in recursion
//Other example
// the question is we will make a array then pass it value from the middle use recursive to print it other value and then print backward value
void getting_array(int *arr, int *value)
{
    cout<<*value

}
int main()
{
    int a[]={1,2,3,4,5,6,7};
    int *p;
    p=a;
    getting_array(p,p+3);
}

// Finding a fictorial
/*
int  factoria(int a)
{
    int d=1
    if (a=0 || a=1)
    return 1;
else
    factoria()
int main()
{
    int a;
    cout<<"Enter a value here "<<endl;
    cin>>a;
    factoria(a);

}
/*void fun(int a=1)
{
    cout<<2<<" * "<<a<<" = "<<2*a<<endl;
    if(a==10)
    {
        return;
    }
    fun(a+1);
    //cout<<a<<endl;

}
int main()
{

    fun();
}
*/
