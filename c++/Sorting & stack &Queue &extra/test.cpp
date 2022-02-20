#include<iostream>
using namespace std;
int main()
{
    int *p=new int [5];
    int a;
    *p=1;
    *(p++)=2;
    *(p++)=3;
    if()
    int s;
    s=sizeof(p)/sizeof(int);
    cout<<s;
    delete [] p;
}



/* class Class1 {
	 public:
 virtual void f() {
 cout << "Function f() in Class1\n";
 }
 void g() {
 cout << "Function g() in Class1\n";
 }
	 };
	 class Class2 {
	 public:
 virtual void f() {
 cout << "Function f() in Class2\n";
 }
 void g() {
 cout << "Function g() in Class2\n";
 }
	 };
 class Class3 {
	 public:
 virtual void h() {
 cout << "Function h() in Class3\n";
 }
	 };
 int main() {
 Class1 object1, *p;
 Class2 object2;
 Class3 object3;
 p = &object1;
 p->f();
 p->g();
 p =(Class1*)  &object2;
 p->f();
 p->g();
 p = (Class1*) &object3;
 p->f(); // possibly abnormal program termination;
 p->g();
	 // p->h(); // h() is not a member of Class1;
 return 0;
}
/*
double p(double x)
{
    return x*2;
}
double sum(double (*p)(double), int n, int m) {
 double result = 0;
 for (int i = n; i <= m; i++)
 result += p(i);
 return result;
}
int main()
{
double d;

    d=sum((*p)(7),2,4);
    cout<<d;
}
/*
#include<iostream>
#define arraysize 7
using namespace std;
struct Node
{
    int info;
    Node *next;

};
class linkedlist
{
private:

    int *arra=new int [arraysize];
public:
    linkedlist()
    {
        for(int i=0; i<arraysize; i++)
        {
            cin>>*arra;
        }
    }
    void display()
    {
        for(int i=0; i<arraysize; i++)
            cout<<*arra;
    }
    void delete_arr()
    {
        delete [] arra;
    }

};

int main()
{
linkedlist L1;
L1.display();
L1.delete_arr();
}


/*int find1(int *x)
{
    int j,s;
    s=sizeof(x)/sizeof(int);
    int len=sizeof(x);
    cout<<s<<"LEngth "<<len;
    //for(int i=0;i<)
}
int main()
{
 int *p=new int[3];
    find1(p);

}
*/
