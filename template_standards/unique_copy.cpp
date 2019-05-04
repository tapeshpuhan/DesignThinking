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

template<class ItreatorFast, class Outputiterator, typename BinaryPred>
Outputiterator UniqueCopy(ItreatorFast first, ItreatorFast last, Outputiterator d_input, BinaryPred pred)
{
     for(ItreatorFast index = first; index != last; ++index)
     {
         if( !pred(*index, *(index + 1)))
         {         
            *d_input = *index;          
            d_input++;
        }
     }
    return d_input;
}

int main()
{
        std::string s = "My                Hobby   is     to   drive    on  hill           ";
        std::string s1;
        UniqueCopy(s.cbegin(), s.cend(), std::back_inserter(s1), [&](const char c1, const char c2)
        {
            return ((c1 == ' ') && (c2 == ' ')); 
            }); 

Print(s1);
    
    return 0;
}
