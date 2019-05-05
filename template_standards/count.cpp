#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
void Print(const T& value)
{
    for(auto& at : value)
    {
        std::cout<<at;
    }
    std::cout<<std::endl;
}


template<class ForwardInput, typename UnaryPred>
size_t CountIf(ForwardInput first, ForwardInput last, UnaryPred pred)
{
    size_t count = 0;
    
    for(ForwardInput index = first; index != last; ++index)
    {
        if(pred(*index))
        {
            count++;
        }
    }
    return count;
}
int main()
{
        std::string s = "My          o      Hobby   is     to   drive    on  hill           ";

        auto c = CountIf(s.begin(),s.end(),[&](char c){return c == 'o';});
std::cout<<c<<std::endl;

    
    return 0;
}
