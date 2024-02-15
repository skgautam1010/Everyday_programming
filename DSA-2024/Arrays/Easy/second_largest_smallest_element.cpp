#include <bits/stdc++.h>

using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.

    //Brute Force Approach


    vector<int>result(2);

    sort(a.begin(),a.end());
    int largest=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]!=largest)
        {
            result[0]=a[i];
            break;
        }
    }
    int smallest=a[0];
    for(int i=1;i<=n;i++)
    {
        
        if(a[i]!=smallest)
        {
            result[1]=a[i];
            break;
        }
    }

    
    return result;


    //Better Approach

    vector<int>result(2);
    int largest=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>largest)
        {
            largest=a[i];
        }
    }
    result[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=largest && a[i]>result[0])
        {
            result[0]=a[i];
        }
    }
    int smallest=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<smallest)
        {
            smallest=a[i];
        }
    }
    result[1]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        
        if(a[i]!=smallest && result[1]>a[i])
        {
            result[1]=a[i];
        }
    }

    
    return result;


    //Optimal Approach
    vector<int>result(2);
    int largest=a[0];
    result[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>largest)
        {
            result[0]=largest;
            largest=a[i];
        }
        else if(a[i]!=largest && a[i]>result[0])
        {
            result[0]=a[i];
        }
    }
    int smallest=a[0];
    result[1]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]<smallest)
        {
            result[1]=smallest;
            smallest=a[i];
        }
        else if(a[i]!=smallest && a[i]<result[1])
        {
            result[1]=a[i];
        }
    }

    
    return result;

}
