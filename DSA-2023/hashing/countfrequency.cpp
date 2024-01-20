#include<bits/stdc++.h>

using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums){
    // Write your code here.

    vector<int>res(x);
    for(int i=0;i<n;i++)
    {
        res[nums[i]-1]++;
    }
    res.resize(n);
    return res;
}