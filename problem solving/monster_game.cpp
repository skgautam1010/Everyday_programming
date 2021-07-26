#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int exp_level;
    cin>>exp_level;
    vector<int>mons_pow;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mons_pow.push_back(temp);
    }
    vector<int>mons_bonus;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mons_bonus.push_back(temp);
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[mons_pow[i]]=mons_bonus[i];
    }
    
    int count=0;
    for(auto a:mp)
    {
        if(a.first<=exp_level)
        {
            exp_level +=a.second;
            count++;
        }
    }
    cout<<"Max Possible monster killed: "<<count<<endl;
    return 0;
}