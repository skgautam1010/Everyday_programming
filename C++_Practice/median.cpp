#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v1={3,1,1,2};
    vector<int>v2={4,3,3,2,1};

    vector<int>::iterator ip;
    vector<int>::iterator ip1;
    
    ip = std::unique(v1.begin(), v1.end());
    
    v1.resize(std::distance(v1.begin(), ip));

    ip1 = std::unique(v2.begin(), v2.end());
    
    v2.resize(std::distance(v2.begin(), ip1));
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<int>res(v1);
    res.insert(res.end(), v2.begin(), v2.end());
    int n=res.size();
    if(n%2==0)
    {
        int temp=(n/2)+((n/2)+1);
        cout<<res[temp];
    }
    else{
        int temp1=(n+1)/2;
        cout<<res[temp1];
    }
    return 0;
}