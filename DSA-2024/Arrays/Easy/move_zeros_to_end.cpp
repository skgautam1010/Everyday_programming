#include<bits/stdc++.h>

using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.


    //Optimal Approach

    int j=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)
    {
        return a;
    }

    for(int i=j+1;i<n;i++)
    {
        if(a[i]!=0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    return a;


    //Brute Force Approach
     int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            count++;
        }
    }
    if(count==0)
    {
        return a;
    }
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            temp.push_back(a[i]);
        }
        
    }
    for(int i=0;i<count;i++)
    {
        temp.push_back(0);
    }
    return temp;

    //Brute Force Approach

    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            temp.push_back(a[i]);
        }
        
    }
    for(int i=0;i<temp.size();i++)
    {
        a[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++)
    {
        a[i]=0;
    }
    return a;
}
