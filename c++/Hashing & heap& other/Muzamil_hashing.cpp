#include<iostream>
#include<list> 
using namespace std;
class hashtable{
    public:
    int bucket;   // size of hashtable
    list<int>*table;  // creating table
    hashtable(int x){
        
        bucket=x;
        table=new list<int>[bucket];
        
    }
    int hashfunction(int key){
        return key%bucket;
    }
    void insert(int key){
        int index=hashfunction(key);
        table[index].push_back(key);
    }
    void display(){
        for(int i=0;i<bucket;i++){
            cout<<i;
            for(auto x:table[i])
            cout<<"-----> "<<x;
            cout<<endl;
        }
    }
    void remove(int key){
        int index=hashfunction(key);
        list<int>::iterator i;
        for(i=table[index].begin();i!=table[index].end();i++){
            if(*i==key)
            break;
        }
        if(i!=table[index].end())
        table[index].erase(i);
    
    }
    
};
int main(){
    hashtable h(9);
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,14,15,16};
    int n;
    n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        h.insert(arr[i]);
    }
    cout<<"-------------------deleting the element---------------------  "<<endl;
    int x;
    cout<<"enter the elment you want to delete--------------------------"<<endl;
    cin>>x;
    h.remove(x);
        

    h.display();
    // h.searching(11);
    
}