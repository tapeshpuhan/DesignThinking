#include <iostream>
/* Find sum of digits using recursion
 * */
 
 int SumRec(int number)
 {
     if(number == 0 )
     {
      return 0;    
     }
          
     return (number%10)+SumRec(number/10);
 }



int main()
{
    std::cout<<SumRec(43218)<<std::endl;
}
