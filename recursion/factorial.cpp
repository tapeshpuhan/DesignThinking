#include <iostream>
using namespace std;
#define MAX 1000
int countZeroes(int A[MAX][MAX],int N);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int A[MAX][MAX];
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>A[i][j];
		cout<<countZeroes(A,n)<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
int countZeroes(int A[MAX][MAX],int N)
{
//Your code here
int count = 0;
for(auto i = 0 ; i < N; ++ i)
{
    for(auto j = 0 ; j < N; ++ j)
    {
        if(A[j] == 0)
        {
        count++;
        }
    }
}
return count;
}
