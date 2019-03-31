
#ifndef CLIENT_H_
#define CLIENT_H_

#include "notify.h"

class BookClient
{
    public:
    explicit BookClient(NotifyInt& notify);
    
    private:
    NotifyInt &notify_;
    void BookHandler(int result);
};

class PenClient
{
    
    public:
    explicit PenClient(NotifyInt& notify);
    
    private:
    NotifyInt &notify_;
    void PenHandler(int result);
};

class EmployClient
{    
    public:
    explicit EmployClient(NotifyInt& notify);
    
    private:
    NotifyInt &notify_;
    void EmployHandler(int result);
};
#endif 
