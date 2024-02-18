#include<bits/stdc++.h>

using namespace std;

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here

    //Brute Force Approach
    //Use a set (set<int>st;) to get all the values -> Since set takes only unique values;

    //Optimal Approach

    int i=0,j=0;
    int n=a.size();
    int m=b.size();
   
    vector<int>result;
    
    while(i<n && j<m)
    {
        if(a[i]<=b[j])
        {
            if(result.size()==0 || result.back()!=a[i])
            {
                result.push_back(a[i]);
            }
            i++;
        }
        else{
            if(result.size()==0 || result.back()!=b[j])
            {
                result.push_back(b[j]);
            }
            j++;
        }
    }

    while(i<n)
    {
        if(result.size()==0 || result.back()!=a[i])
            {
                result.push_back(a[i]);
            }
        i++;
    }
    while(j<m)
    {
        if(result.size()==0 || result.back()!=b[j])
            {
                result.push_back(b[j]);
            }
        j++;
    }
    return result;
}