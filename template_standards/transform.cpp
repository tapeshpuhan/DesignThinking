#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void Print(const T& value)
{
    for(auto& at : value)
    {
        std::cout<<at<<" ";
    }
    std::cout<<std::endl;
}

template<class InputIter, class OutputItr, typename UnaryOperator>
OutputItr Transform(InputIter first, InputIter last, OutputItr output, UnaryOperator pred)
{
 
     for(InputIter index = first; index != last; ++index)
     {
         *output = pred(*index);          
         output++;
     }
     return output;   
}

template<class InputIter, class InputIter1, class OutputItr, typename BinaryPred>
OutputItr Transform(InputIter first, InputIter last, InputIter1 d_first, OutputItr output, BinaryPred pred)
{
 
     for(InputIter index = first; index != last; ++index)
     {
         *output = pred(*index, *d_first++);         
         output++;
     }
     return output;   
}

int main()
{
    std::vector<int> coll={1,2,3,4,5,6,7};

// using unary
 /*   std::transform(coll.cbegin(), coll.cend(), coll.begin(),[&](const int x)
    {
        return x + 10;
        });
    Print(coll);
   */ 
    Transform(coll.cbegin(), coll.cend(), coll.begin(),[&](const int x)
    {
        return x + 10;
        });
    Print(coll);
    
    Transform(coll.cbegin(), coll.cend(), coll.crbegin(),coll.begin(),[&](const int x , const int y)
    {
        std::cout<<x<<" "<<y<<std::endl;
        return x + y;
    });
    Print(coll);
    
    return 0;
}
