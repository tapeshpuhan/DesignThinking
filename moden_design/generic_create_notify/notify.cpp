#include "notify.h"

void NotifyInt::RegisterNotification(NotifyType&& notify)
{
    
    store_notification_list_.push_back(std::move(notify));
    
}

void NotifyInt::Notify(int data)
{    
    for(auto& notification : store_notification_list_)
    {
        notification(data);
    }
}
