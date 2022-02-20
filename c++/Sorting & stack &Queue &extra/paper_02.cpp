#include<iostream>
using namespace std;
int main(){
    int n;
    n=6;
int *arr=new int[n];
int user_choice;
cout<<"How many time you want to execute this loop";
cin>>user_choice;
for(int i=0; i<user_choice; i++)
{
    cin>>arr[i];
}
int loop=n-user_choice;
int index=0;

while(loop<n){
for(int i=index; i<user_choice+index; i++)
    {arr[user_choice+index]+=arr[i];}
index++;
    
loop++;
}
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";

}


return 0;
}





















/*#include<iostream>
using namespace std;
struct Node
{
int data;
Node *next;
};
class List
{
    private:
    Node *head,*temp,*temp1;
    public:
        List()
        {
            head=temp=temp1=NULL;
        }
        void code()
        {
            max=head->data;
            min=head->data;
            temp=head;
            while(temp!=NULL)
            {
                if(max<temp->data)
                {
                    max=temp->data;
                }else if(min>temp->data)
                {
                    min=temp->data;
                }

                temp=temp->next;
            }
            while(temp!=NULL)
            {
                if(temp->next->data==max)
                {
                    temp1=temp->next;
                    temp->next=temp1->next;
                    delete temp1;
                    

                }
                else if(temp->next->data==min)
                {
                    temp=temp->next;
                    temp->next=temp1->next;
                    delete temp;
                }
                temp=temp->next;
            }
        }

};
int main(){

return 0;
}
*/