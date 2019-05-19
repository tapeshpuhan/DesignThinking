#include "thread_pool.h"


void fun(int a)
{
    std::cout<<"fun "<<a<<std::endl;
}

int main()
{
    ThreadPool<int> pool;
    int a = 100;
    
    auto id = pool.RegisterThread([&](int a){fun(a);});
    pool.RunThread(id, a);
    pool.RunThread(id, a);
    return 0;
}
