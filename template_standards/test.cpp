#include <bits/stdc++.h>

using namespace std;

void print()
{
}

template<typename T, typename ... Type>
void print(T type, Type... args)
{
    //cout<<type<<endl;
    cout<<sizeof...(Type)<<endl;
    print(args ...);
}

// Complete the repeatedString function below.
int main()
{

    print('a',1,2.4,5,7,9,'d',"Hallo");
    

    return 0;
}
