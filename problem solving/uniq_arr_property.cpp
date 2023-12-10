#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;
    int k;
    cin>>k;

    vector<pair<int,int>>arr;
    if(n==1 || k==1)
    {
        int temp;
        temp=n>k?n:k;
        cout<<temp<<endl;
    }
    else{
        for(int i=1;i<=k+1;i++)
        {
            for(int j=1;j<=n;j++)
            {
                pair<int,int>p;
                p=make_pair(i,j);
                arr.push_back(p);
            }
        }
        int count=0;
        for(auto i:arr)
        {
            if(i.second%i.first==0)
            {
                count++;
            }
        }
        cout<<count%10000<<endl;
    }

    

    return 0;
}