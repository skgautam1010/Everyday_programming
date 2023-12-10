#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char,int>mp;
    queue<char>q;
    string s="aabcdeef";
    string res="";
    int n=s.length();
   /* for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }*/

    for(auto a:mp)
    {
        cout<<a.first<<"->"<<a.second<<endl;
    }

    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]==1)
        {
            q.push(s[i]);
            //cout<<s[i]<<endl;
        }
        while(!q.empty() && mp[q.front()]>1)
        {
            q.pop();
        }
        if(q.empty())
        {
            res+="#";
        }
        else{
            res+=q.front();
        }
    }
    /*cout<<(!q.empty())<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }*/
    cout<<res<<endl;
    return 0;
}