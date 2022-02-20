#include<iostream>
using namespace std;
/*Here we use template class
It is used to define our own data type which we want output
if we want float simply add in main function after creating a class  object the
define our required data types
passing a data types
simple data type syntax
template<class T>
class_name <"The data type you want">functon_name or constructor
Multiple data
template<class T1,class T2>
DEfalut parameters
template<class t1=int,t2=float>
class-name<>function_name
---------------------Sir NAUMAN ---------------
placeholder  == (T) <- it usually we will use 't' to define type of functions
template ==It is runtime :

*/
/*
-------function templates--------

template < class T>
T fun(T a,T b)
{
    T result;
    result= (a>b)? a:b;
    return result;
}

int main()
{
    int x,y ,l;
    x=2;
    y=3;
    l=fun<int>(x,y);
    cout<<"REsult of int : "<<l;
    string x1,y2,d;
    x1="Ali";
    y2="usama";
    d=fun<string>(x1,y2);
    cout<<"value of string : "<<d<<endl;
}
*/
/*
------------class template -----------------
-----> every function u define write  template must
-----> creating obj must define which type you want 
-----> understand below syntax : 
------> for creating multiples data types : 
template <class T>
class tempo
{
    private:
    
        
        T value;
        T s;    

    public:
    void input_val();
    void output();
    
};
template<class T>
void tempo<T>::input_val()
{
    cout<<"Enter a value from user : ";
    cin>>value;
    cout<<"enter a second value : ";
    cin>>s;
}
template<class T>
void tempo<T>::output()
{
    cout<<"Fisrt value : "<<s;
    cout<<"Second value : "<<value;
}
int main()
{
    tempo<int> obj;
    obj.input_val();
    obj.output();
    cout<<"Enter a string : "<<endl;
    tempo<string> obj2;
    obj2.input_val();
    obj2.output();
}*/

/*
template<class T1, class T2>
class myClass{
    public:
        T1 data1;
        T2 data2;
        myClass(T1 a,T2 b){
            data1 = a;
            data2 = b;
        }
    void display(){
        cout<<this->data1<<" "<<this->data2;
    }
    void ourfunc();
};

void myClass<T1>::outfunc()
{
    cout<<"This function is shown how we declare a template function outside the class
}
int main()
{
    myClass<int, char> obj(1, 'c');
    obj.display();
}
*/