#include<iostream>
using namespace std;
int  main() {
    int ans=1;
    for(int i=5; i>0; i--)
    {
        if(i==0 || i==1)
        {

            break;
        }else
            {
                ans=ans*i;
            }
    }
    cout<<"df"<<ans<<endl;

}
/*#include<iostream>
using namespace std;
void start(int *a)
{
    cout<<"the starting elements of array"<<*(a+0);

}
int main()
{

int *p= new int [3];

int d;
for (int i=0; i<3; i++){
//cout<<"Enter the index of specific point"<<endl;cin>>d;cout<<endl;
cout<<"Enter array elements"<<endl;cin>>p[i];
}

int user;
cout<<"Enter the choice 1,2,3,4"<<endl;
cin>>user;
if (user ==1)
{
    start(p);
}
delete [] p;

}

*/
