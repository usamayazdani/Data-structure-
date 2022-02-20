#include<iostream>
#include<vector>

using namespace std;
struct Node
{
    int info;
    Node *next;
    Node *prev;
};
class Hashing{

    private:
    Node **h_table,**top; //pointing to hash table
    //why it double pointer bcz when i m chnging in function it will gave actaul value
    //not new function so double pointer is used
    //like swap number with reference and without reference variables
    int index;
    int Ht_length;
    int Ht_Size;
    public:

    //constructor
    Hashing(int size)
    {

        h_table = new Node*[size];
        top = new Node*[size];
        for (int i = 0; i <size; i++) {
            h_table[i] = NULL;
            top[i] = NULL;
        }
        Ht_Size=size;
        Ht_length=0;
        index=0;

    }
    ~Hashing()
    {
        delete [] h_table;
    }
    int Hash_Function(int);
    void print () const;
    void insertion(int key);

};
int Hashing::Hash_Function(int key)
{
    return key%Ht_Size;
}
void Hashing::insertion(int key)
    {
        // Applying hashFunc to find
        // index for given key
        int hash_index = Hash_Function(key);
        Node* temp = h_table[hash_index];

        // if key has no value stored
        if (temp == NULL) {
            // creating new node
            temp = new Node;
            temp->info = key;
            temp->next = NULL;
            temp->prev = NULL;
            h_table[hash_index] = temp;
            top[hash_index] = temp;
        }
        else {
            // traversing till the end of
            // the list
            while (temp != NULL)
                temp = temp->next;

            // creating the new node
            temp = new Node;
            temp->info = key;

            temp->next = NULL;
            temp->prev = top[hash_index];
            top[hash_index]->next = temp;
            top[hash_index] = temp;
        }
        cout << "Value  was successfully"
                " added at key " << key << endl;
    }
    /*
void Hashing::insertion(int key)
{
        vector <int> obj;
        index=Hash_Function(key);
        h_table[index]=key;
        obj.push_back(key);
        for(int i=0; i<3; i++)
        {
            cout<<h_table[i]<<" ";
        }
        if(h_table[2]==NULL)
        {
            Node *temp=new Node;
            temp->info=key;
            temp->prev=&(h_table[index])

            //int *add=&(h_table[index]);
            temp->prev=add;
            temp->next=NULL;

            cout<<"Got it";
        }



}
*/
int  main() {
    Hashing obj(3);
    obj.insertion(2);
    obj.print();
    return 0;
}
