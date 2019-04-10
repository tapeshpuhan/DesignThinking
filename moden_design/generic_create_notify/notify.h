
#ifndef NOTIFY_H_
#define NOTIFY_H_

#include <iostream>
#include <functional>
#include <vector>

using NotifyType = std::function<void(int)>;

class NotifyInt
{
    public:
    
    void RegisterNotification(NotifyType&& notify);
    void Notify(int data);
    
    private:
    
    std::vector<NotifyType> store_notification_list_;
};

#endif //NOTIFY_H_
