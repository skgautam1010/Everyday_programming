#include<bits/stdc++.h>

using namespace std;

void print(int a, int n, vector<int>&res)
{
    if(a>n)
    {
        return;
    }

    res.push_back(a);
    a++;
    print(a,n,res);
}


vector<int> printNos(int x) {
    // Write Your Code Here

 vector<int>res;
 print(1,x,res);
 return res;
}