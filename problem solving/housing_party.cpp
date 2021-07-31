
/*A=[2,3,4,5,6]

Output=[2,1,1,0,2]


A=[6,6,6,6,6]
O=[4,4,4,4,4]
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int ans[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
    }
    int dp[n][n];
    

   for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            
                if(arr[i]%arr[j]==0)
                {
                    ans[i] +=1;
                    ans[j] +=1;
                }
                else if(arr[j]%arr[i]==0)
                {
                    ans[i] +=1;
                    ans[j] +=1;
                }
        }
    }
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
