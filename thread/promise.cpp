#include <thread>
#include <mutex>
#include <future>
#include <iostream>

void Sum(int a, int b,std::promise<int>&& promis)
{
    auto res = a+b;
    promis.set_value(res);
}


int main()
{
    std::promise<int> promise_sum;
    std::future<int> future_sum = promise_sum.get_future();
    
    std::thread th(Sum,10,15,std::move(promise_sum));
    future_sum.wait();
    th.join();
    std::cout<<future_sum.get()<<std::endl;
    return 0;
}
