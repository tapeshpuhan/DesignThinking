
#ifndef SERVER_H_
#define SERVER_H_

#include "notify.h"

class Server
{
  public:
    
  explicit Server(const NotifyInt& notify);  
  void Notify(int data);
  
  private:
  NotifyInt notify_;
};
#endif
