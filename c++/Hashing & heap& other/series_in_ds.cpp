#include<iostream>
using namespace std;
int power(int key,int n)
{
    int result=1;
    for(int i=0; i<n; i++)
    {
        result=result*key;
    }
    return result;
}
int factorail(int value)
{
    if(value==0 || value ==1)
    {
        return 1;
    }else
    {
        return value * factorail(value-1);
    }

}

int  series(int x,int val)

{

    int result=0,fac_val=0;
    for (int i=1; i<=val; i++)
    {
        if(i%2==0)
        {
            result+=power(x,i)/factorail(fac_val+2);
            cout<<result<<" ";
            //cout<<fac_val<<" ";
        }else if (i%2!=0)
        {
            result=result-(power(x,i)/factorail(fac_val+2));

            cout<<result<<" ";
        }



    }
    return 1-result;
}






int main()
{
    series(3,3);
    return 0;
}
