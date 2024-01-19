#include<bits/stdc++.h>

using namespace std;

void print(int n, vector<int>&res)
{
    if(n==0)
    {
        return ;
    }
    res.push_back(n--);
    print(n,res);
}


vector<int> printNos(int x) {
    // Write Your Code Here

    vector<int>res;
    print(x,res);
    return res;
}