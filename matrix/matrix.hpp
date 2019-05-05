#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdint>
#include <initializer_list>
#include <iostream>
 
template<typename M_TYPE>
class matrix
{
    public:
    using ColomnData = std::vector<M_TYPE>;
    using MatrixData = std::vector<ColomnData>;
    
    explicit matrix(const int32_t row_size, const int32_t colomn_size):
    row_size_{row_size},col_size_{colomn_size}
    {
        matrix_data_.reserve(row_size);
        for(int32_t index = 0; index < row_size; ++index)
        {
          matrix_data_[index].reserve(colomn_size);  
        }
    }
    
    void InsertRow(const std::initializer_list<M_TYPE>& add_value)
    {
    
      matrix_data_.emplace_back(add_value);
    }
    
    M_TYPE GetValue(const int32_t row, const int32_t colomn)const
    {
        return matrix_data_.at(row).at(colomn);
    }
    
    ColomnData operator[](const int32_t row)const
    {
        return matrix_data_[row];
    }
    void PrintMatrix()
    {
        for(const auto& row_value : matrix_data_)
        {
            for(const auto& col_value : row_value)
            {
                std::cout<<col_value<<" ";
            }
            std::cout<<std::endl;
        }
    }
    
    int32_t GetRowSize()const
    {
       return matrix_data_.size(); 
    }
    
    
    int32_t GetColomnSize(const int32_t row = 0)const
    {
       return matrix_data_.at(row).size(); 
    }
    
    private:

    
    MatrixData matrix_data_;
    int32_t row_size_;
    int32_t col_size_;
};


#endif //MATRIX_H
