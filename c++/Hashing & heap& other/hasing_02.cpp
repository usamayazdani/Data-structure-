#include<iostream>
using namespace std;
//Linear seacrching
class Hashing
{
private:
    /* data */
    int *h_table;
    int h_size;
    int h_length;
    int h_index;
public:
    Hashing(int);
    ~Hashing();
    int Hash_function(int );
    void insertion(int );
    void printing();

};
void Hashing::printing()
{
    for(int i=0; i<h_size; i++)
    {
        cout<<h_table[i]<<" ";
    }

}

void Hashing::insertion(int key)
{
    h_index=Hash_function(key);
    int counter=0;
    while(counter<=h_size){
    if(h_table[h_index]==NULL)
    {
        h_table[h_index]=key;
        break;
    }else if(h_index==h_size-1)
        {
            h_index=0;
        }
    else
    {

        h_index++;


    }
    counter++;
    }
    return;



}





int Hashing::Hash_function(int key)
{
    return key%h_size;
}


Hashing::Hashing(int size1)
{
h_table=new int[size1];
h_size=size1;
h_length=0;
for(int i=0; i<size1; i++)
{
    h_table[i]=NULL;
   // cout<<i<<" ";
}

}

Hashing::~Hashing()
{
delete [] h_table;
}
int main()
{
    Hashing obj(3);

    obj.insertion(2);
    obj.insertion(8);
    obj.insertion(4);
    obj.insertion(4);
    obj.printing();

}

