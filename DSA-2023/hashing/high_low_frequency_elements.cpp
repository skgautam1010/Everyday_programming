#include<bits/stdc++.h>

using namespace std;



vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    map<int,int>mp;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        mp[v[i]]++;
    }
    int min=INT_MAX,low=0;
    int max=INT_MIN,high=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second<min)
        {
            min=it->second;
            low=it->first;
        }
        if(it->second>max)
        {
            max=it->second;
            high=it->first;

        }
    }
    vector<int>res={high,low};
    return res;
}