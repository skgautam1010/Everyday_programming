#include <bits/stdc++.h>

using namespace std;

//hourglass

int main()
{
    vector<int>ar(16);
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int res=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ar[res]=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+
                arr[i+2][j+1]+arr[i+2][j+2];
            res++;

        }
    }
    sort(ar.begin(),ar.end());
    cout<<ar[15]<<endl;

    return 0;
}
