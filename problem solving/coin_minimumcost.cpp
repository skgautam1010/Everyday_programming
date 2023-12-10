#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,j,temp;
    cin>>n;
    int candies_cost=0;
    cin>>candies_cost;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr[i]=temp;
    }
    int result=0;
    result +=arr[0];
    result +=arr[n-1];
    int i=1;
    while (i<n-1)
    {
        j=i;
        while (j<i+3 && j<n-1)
        {
            if(arr[j]>candies_cost)
            {
                result +=candies_cost;
            }
            else
            {
                result +=arr[j];
            }
            j++;
            
        }
        i=i+3;
        if(i<n-1)
        {
            result +=arr[i];
        }
        i++;
        
    }
    cout<<"the result is:"<<result<<"\n";

}