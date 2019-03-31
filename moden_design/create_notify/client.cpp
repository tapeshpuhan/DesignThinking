#include "client.h"

BookClient::BookClient(NotifyInt& notify):notify_{notify}
{
    notify_.RegisterNotification([&](int result){BookHandler(result);});
}


void BookClient::BookHandler(int result)
{
    std::cout<<"BookHandler :: "<<result<<std::endl;
}

PenClient::PenClient(NotifyInt& notify):notify_{notify}
{
    notify_.RegisterNotification([&](int result){PenHandler(result);});
}

void PenClient::PenHandler(int result)
{
    std::cout<<"PenHandler :: "<<result<<std::endl;
}

EmployClient::EmployClient(NotifyInt& notify):notify_{notify}
{
    notify_.RegisterNotification([&](int result){EmployHandler(result);});
}

void EmployClient::EmployHandler(int result)
{
    std::cout<<"EmployHandler :: "<<result<<std::endl;
}
