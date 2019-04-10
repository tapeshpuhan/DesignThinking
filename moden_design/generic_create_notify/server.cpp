
#include "server.h"

  Server::Server(const NotifyInt& notify):notify_{notify}
  {
      
  }
  
  void Server::Notify(int data)
  {
      notify_.Notify(data);
  }
