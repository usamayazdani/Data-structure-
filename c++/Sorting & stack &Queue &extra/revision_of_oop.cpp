#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cout<<"hello world";
}

/*
Here we use virtual Base class concept :
1: when you created a virtual class then class D will call the class A
there is only one copy created and resolve the ambiguity error
2:when we want to call the derived class function from main then we use
class name :: function name if we dont it gave error.
class BAseclass
{
private:
    void A()
    {
        cout<<"This is the base class private function"<<endl;
    }
protected:
    void B()
    {
        cout<<"This is the base class protected function"<<endl;
    }
public:
    void C()
    {
        cout<<"This is the base class public function"<<endl;
    }
};
class derivedclass1:public virtual BAseclass
{
public:
    void A()
    {
        cout<<"This is the derived class A function"<<endl;
    }
    void B()
    {
        cout<<"This is the derived class B function"<<endl;
    }
    void C()
    {
        cout<<"This is the derived class C function"<<endl;
    }
};
class derivedclass2:public virtual BAseclass
{
public:
    void A()
    {
        cout<<"This is the derived class 2 A function"<<endl;
        A();
        B();
        C();
    }
    void B()
    {
        cout<<"This is the derived class 2B function"<<endl;
    }
    void C()
    {
        cout<<"This is the derived class 2 C function"<<endl;
    }
};
class derivedclass3:public derivedclass1,public derivedclass2
{
public:
    void A()
    {
        cout<<"This is the derived class A function"<<endl;
        A();
        B();
        C();
    }
    void B()
    {
        cout<<"This is the derived class B function"<<endl;
    }
    void C()
    {
        cout<<"This is the derived class C function"<<endl;
        derivedclass2::C();
        BAseclass::B();
        BAseclass::C();
    }
};

int main()
{
 BAseclass B1;
//  B1.A(); //error
//  B1.B(); //error
 // B1.C();
 //derivedclass1 d1;
 //d1.A();
 //d1.B();
 //d1.C();
 derivedclass2 d2;
// d2.A();
//d2.B();
// d2.C();
 derivedclass3 d3;
 //d3.A();
 //d3.B();
 d3.C();

}
/*class C {
	 public:
 C(char s , int i = 0, double d = 1) {
 strcpy(dataMember1,s);
 dataMember2 = i;
 dataMember3 = d;
 }
 void memberFunction1() {
 cout << dataMember1 << ' ' << dataMember2 << ' '
 << dataMember3 << endl;
 }
 void memberFunction2(int i, char *s = "unknown") {
 dataMember2 = i;
 cout << i << " received from " << s << endl;
 }
	 protected:
 char dataMember1[20];
 int dataMember2;
 double dataMember3;
	 };

int main()
{
 C object1("object1",100,2000), object3;
 object3.memberFunction1();
 //object3.memberFunction2();


}*/
