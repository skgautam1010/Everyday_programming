#include<bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cin>>s;

    int hash[256]={0};

    int q;
    cin>>q;

    for(int i=0;i<s.size();i++)
    {
        hash[s[i]]++;
    }

    while(q--)
    {
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
}