/*
static binding or early binding:
In static binding we know which function we are calling
like function overloading  where we know that(by seeing function
arguments)which function is call.
Dynamic binding:
In dynamic binding we don't know which function will called
-->we use virtual keyword in main class and then on run time
our compiler will decide that now run the derived function
-->there function name is same which we call "function overriding "


*/
#include<iostream>
using namespace std;
class dynamic_binding
{
    public:
        virtual void fun()
        {
            cout<<"My base class function"<<endl;
        }



};
class derived_class: public dynamic_binding
{
    public:
         void fun()
        {
            cout<<"My derived class function"<<endl;
        }

};
void myfun(dynamic_binding*obj)
{
    obj->fun();
}

int main()
{
    dynamic_binding object1, *p;
    derived_class object2;
    p=&object1;
    p->fun();
    p=(dynamic_binding*)&object2; //we use pointer of dynamic class which
                                // point the object of class 2
    p->fun();
    //Also i gave you another good examples

    myfun(new dynamic_binding);
    myfun(new derived_class);
/*
-->here we use base class virtual
-->first line will call myfun where i created object of class base
-->then it call (its easy to understand it)
-->what about second calling of my func where i call fun with derived class
-->now here function check first main function then
-->automatically call derived function(runtime or dynamic binding)


}
