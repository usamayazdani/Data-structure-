/*
namespace is basically a representation of word which u used most
->1 -< it will remove ambuiguity like same name in multiples times
->2 -<  
*/
#include<iostream>
namespace first
{
    int var =12;
} // namespace first
namespace second
{
    int var=14;
} // namespace second

int main(){
    //we also use this in our function ...compiler read from upper to lower
   // using namespace first
   // '::' when we write colon we will say it is fully qualified 
    
std::cout<<first::var<<std::endl;
std::cout<<second::var<<std::endl;

return 0;
}