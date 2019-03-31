#include "client.h"
#include "notify.h"
#include "server.h"

int main()
{
    NotifyInt notify;
    BookClient b_type(notify);
    PenClient p_type(notify);
    EmployClient e_type(notify);
    
    Server server(notify);
    
    server.Notify(100);
    
    return 0;
}
