#include <vector>
#include <iostream>

using namespace std;


// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int count = 0;
    
    for(int i = 0;  i < 4; ++i)
    {
        int count_hr = 0;
        
        for(int j = 0; j < 4; ++j)
        {            
            count_hr  += arr[i][j];            
            count_hr  += arr[i][j+1];            
            count_hr  += arr[i][j+2];            
            count_hr  += arr[i+1][j+1];
            
            count_hr  += arr[i+2][j];
            count_hr  += arr[i+2][j+1];
            count_hr  += arr[i+2][j+2];  
            
            if(count_hr > count)
            {
                count = count_hr;
            }
            count_hr = 0;
        }
        
   
    }
    return count;
}

int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr{{1, 1, 1, 0, 0, 0,},
{0, 1, 0, 0, 0, 0},
{1, 1, 1, 0, 0, 0},
{0, 0, 2, 4, 4, 0},
{0, 0, 0, 2, 0, 0},
{0, 0, 1, 2, 4, 0}};

   /* for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }*/

    int result = hourglassSum(arr);

    cout << result << "\n";

    

    return 0;
}
