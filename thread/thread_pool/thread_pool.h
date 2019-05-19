#include <thread>
#include <future>
#include <functional>
#include <cstdint>
#include <map>
#include <iostream>

template<typename... Arg>
class ThreadPool
{
    public:
    
    using FunctionType = std::function<void(Arg ...)>;
    using TaskType = std::packaged_task<void(Arg ...)>;
    using TaskId = std::uint32_t;
    
    ThreadPool()=default;
    ThreadPool(ThreadPool&)=delete;
    ThreadPool& operator=(ThreadPool&)=delete;
    ThreadPool(ThreadPool&&)=delete;
    
    TaskId RegisterThread(FunctionType&& function)
    {
        thread_id_++;
        TaskType task{std::move(function)};
        task_pool_.insert({thread_id_, std::move(task)});
        
        return thread_id_;
    }
        
    void RunTask(const TaskId thread_id, Arg&&... arg)
    {
        auto task_index = task_pool_.find(thread_id);
        
        if(task_index != task_pool_.end())
        {
           auto result = task_index->second.get_future();
           task_index->second(std::forward<Arg>(arg)...);
           result.get();
        }
    }
    
    void RunTask(const TaskId thread_id, Arg&... arg)
    {
        auto task_index = task_pool_.find(thread_id);
        
        if(task_index != task_pool_.end())
        {
           auto result = task_index->second.get_future();
           task_index->second(arg...);
           result.get();
        }
    } 
    
    std::thread::id RunThread(const TaskId thread_id, Arg&&... arg)
    {
        auto task_index = task_pool_.find(thread_id);
        
        if(task_index != task_pool_.end())
        {
            std::thread task_thread(std::move(task_index->second),std::forward<Arg>(arg)...);
            UnRegisterThread(thread_id);
            task_thread.join();                                
            return  task_thread.get_id();
        }
    }
  
    std::thread::id RunThread(const TaskId thread_id, Arg&... arg)
    {
        auto task_index = task_pool_.find(thread_id);
        
        if(task_index != task_pool_.end())
        {
            std::thread task_thread(std::move(task_index->second),arg...);
            UnRegisterThread(thread_id);  
            task_thread.join(); 
            return  task_thread.get_id();                               
        }
    }
    
    private:
    
    TaskId thread_id_{0};
    std::map<TaskId, TaskType> task_pool_;
    
    void UnRegisterThread(const TaskId thread_id)
    {
        task_pool_.erase(thread_id);
    }
};
