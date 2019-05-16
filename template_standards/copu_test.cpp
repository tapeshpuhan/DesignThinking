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



int main()
{
        std::string s = "My          o      Hobby   is     to   drive    on  hill           ";


    std::transform(begin(s),end(s),s.begin(),[&](const char ch)
    {
        char out = ch;
        if (out == 'o')
        {
            out = '*';
        }        
        return out;
        });
    Print(s);
    return 0;
}
