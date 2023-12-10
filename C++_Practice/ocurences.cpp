#include<bits/stdc++.h>

using namespace std;


int main()
{

    string s;
    getline(cin,s);
    
    unordered_map<char,int>mp;

    int n=s.length();
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }
    for(char a: s)
    {
        if(mp[a]!=0)
        {
            cout<<a<<mp[a];
            mp[a]=0;
        }
    }
    cout<<"\n";
    return 0;
}