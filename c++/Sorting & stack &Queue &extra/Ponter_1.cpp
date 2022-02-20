#include <iostream>
#include<cstring>
using namespace std;
//copy cosntructors
/*here i learn  if you simply added one constructor to other
the pointer data type will store the address of other and our required condion is not
fulfiled
The ages are different, but the names in the two objects are the same. What happened?
The problem is that the definition of Node does not provide a copy constructor
	 Node(const Node&);
which is necessary to execute the declaration node2(node1) to initialize node1.
If a user copy constructor is missing, the constructor is generated automatically by
the compiler. But the compiler-generated copy constructor performs member-bymember copying. Because name is a pointer, the copy constructor copies the string
address node1.name to node2.name, not the string content, so that right after execution of the declaration, the situation is as in Figure 1.2a. Now if the assignments
	 strcpy(node2.name,"Wendy");
	 node2.age = 30;
are executed, node2.age is properly updated, but the string "Roger" pointed to by
the name member of both objects is overwritten by "Wendy", which is also pointed
to by the two pointers (Figure 1.2b). To prevent this from happening, the user must
define a proper copy constructor,
<---------->
 */
struct Node {
 char *name;
 int age;
 Node(char *n = "", int a = 0) {
 name = strdup(n);
 age = a;
 }
 Node(const Node&s)
 {
     name=strdup(s.name);
     //age=a;
 }
};
int main()
{
    int *ptr2 = (int *)malloc(sizeof(int));
    cout<<ptr2;
    delete ptr2;
    Node node1("usama",3),node2(node1);
    strcpy(node2.name,"yazdani");
    node2.age=19;
    cout<<node1.name<<' '<<node1.age<<' '<<node2.name<<' '<<node2.age;

}
/*
// cOsnt pointer :
 //   1:pointer constant = we cannot edit that value
 //   2: variable const = we only read that value with the help of pointer we cannot chng that only read
 // if the const is write after pointer then it means it s const pointers otherwise if we write const int then
 // it means our pointing variable is pointers
int main()
{

    int A=12;
      int   * const  b=&A;
     //++(*b);
     b++;
    cout<<*b;
    A++;
    cout<<A;
//const int


}
/*
void increment_all (int* start, int* stop)
{
int * current = start;
while (current != stop) {
++(*current); // increment value pointed
++current; // increment pointer
}
}
void print_all (const int* start, const int* stop)
{
const int * current = start;
while (current != stop) {
        cout << *current << '\n';
++current; // increment pointer
}
}
/*
int main ()
{
int numbers[] = {10,20,30};
increment_all (numbers,numbers+3);
print_all (numbers,numbers+3);
return 0;
}
/*
// A great use case
int main ()
{
int a[5]={1,2,3,4,5};
int b[5]={1,2,3,4,5};
int *p,*s;
p=a;
s=b;

*++p=*s++;
cout<<*p<<endl;
cout<<*s<<endl;

}


/*
   // more pointers
//Here incementaion and decrementaon preocess works
//post incremet and pre increment
//run this code on python visulaization tutor
int main ()
{
int numbers[5]={1,2,3,4,5};
int *p;
p=numbers;
cout<<*p++<<endl;
cout<<++*p<<endl;
cout<<(*p)++<<endl;
cout<<*++p<<endl;

}
}

//type casting in pointer
/*
int main()
{
    int s=12;
    void *p=&s;
    int*d=(int*)p;
     //p=12;
    //d=&p;
    cout<<*d;
}
/*
void increase (void* data, int psize)
{
if ( psize == sizeof(char) )
{ char* pchar;
 pchar=(char*)data;
  ++(*pchar);
   }
else if (psize == sizeof(int) )
{ int* pint; pint=(int*)data; ++(*pint); }
}
int main ()
{
char a = 'x';
int b = 1602;
increase (&a,sizeof(a));
increase (&b,sizeof(b));
cout << a << ", " << b << '\n';
return 0;
}
/*
//Here we use static keyword to point argument but static cannot change value
void increment_all ( int* start, int* stop)
{
const int * current = start;
while (current != stop) {
++(*current); // increment value pointed
++current; // increment pointer
}
}
void print_all (int* start, int* stop)
{
 int * current = start;
while (current != stop) {

cout << *current << '\n';
++current; // increment pointer
}
}
int main ()
{
const int numbers[] = {10,20,30};
increment_all (numbers,numbers+3);
print_all (numbers,numbers+3);
return 0;
}
/*
#include<iostream>
using namespace std;
int main()
{
    int numbers[5];
    int *p;
    p=numbers;
    *p=10;
    p++;
     *p = 20;
    p = &numbers[2]; *p = 30;
    p = numbers + 3; *p = 40;
    p = numbers; *(p+4) = 50;
    for (int n=0; n<5; n++)
    {
        cout<<n<<" Number of : "<<numbers[n]<<endl;
    }
return 0;
}
*/
