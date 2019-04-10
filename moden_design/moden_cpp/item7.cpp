/*
 * why to prefer {} insted () or =
 * 
 * 1. Provide universial initializations
 * 2. Prevent Initiazation of narrowing converssions
 *    build in type
 * 3. Using {} and () in a variadic template is complete 
 *    diffrent behavior . () -> 10 number of int in vector
 *      print 10 number of 20
 *    {} print 10, 20 -> number of vector is 2 [Strange :)]
 * */

#include <iostream>
#include <vector>
#include <string>


template<typename T, typename... Ts>
T DoSomething(Ts&&... param)
{

    T local_obj{std::forward<Ts>(param)...};//[10,20]
    // T local_obj(std::forward<Ts>(param)...); //[20,20,20,20,20,20,20,20,20,20] for two arg 3 arg will not work

     return local_obj;
}

int main()
{
    //point 1
    std::vector<int> v{1,2,3};
    
    //point 2
    
    double a,b,c;
    //int d{a+b+c};
    /*
     * warning: narrowing conversion of ‘((a + b) + c)’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]
     int d{a+b+c};

     * */
    
    //int d = a+b+c; //Ok
    int e (a+b+c); //Ok
    
    // Point 3
    std::vector<int> vi;
    
    vi = DoSomething<std::vector<int>>(10,20,30);
    
    for(auto at : vi)
    {
        std::cout<<at<<std::endl;
    }
    
    return 0;
}
