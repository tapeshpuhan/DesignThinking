#include <iostream>
#include <functional>
#include <string>

template<typename TYPE>
void print(const TYPE& data, TYPE& value)
{
    std::cout<<data<<value<<std::endl;
}

template<typename EXICUTE, typename V1,typename V2>
void Exicute(EXICUTE&& exicute, V1&& v1, V2&& v2)
{
    exicute(v1,v2);
}

int main()
{
    auto function_type = [&](auto&& str, auto&& type){
                             print(str, type);
                            };
                            
    //function_type("aloo ", 3.6);
    
    Exicute(function_type, 100.6, 5.7);
                                
    return 0;
}
