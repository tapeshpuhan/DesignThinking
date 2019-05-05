#include "matrix.hpp"

int main()
{
    matrix<int> data(2,2);
    
    data.InsertRow({1,2});
    data.InsertRow({3,4});
    data.InsertRow({6,7});
    data.PrintMatrix();
    std::cout<<"Row size "<<data.GetRowSize()<<std::endl;
    std::cout<<"Colomn size "<<data.GetColomnSize()<<std::endl;
    
    std::cout<<"get value "<<data.GetValue(1,1)<<std::endl;
    
    return 0;
}
