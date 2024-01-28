#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr,int l, int m, int r)
{
    vector<int>v;
    int i=l;
    int j=m+1;

    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            v.push_back(arr[i]);
            i++;
            
        }
        else
        {
            v.push_back(arr[j]);
            j++;
        
        }
    }

    while(i<=m)
    {
        v.push_back(arr[i]);
        i++;
        
    }
    while(j<=r)
    {
        v.push_back(arr[j]);
        j++;
    
    }

    for(int i=l;i<=r;i++)
    {
        
        arr[i]=v[i-l];
    }
   
}

void mergeSort(vector<int> &arr, int l, int r) {
    // Write Your Code Here

    if(l>=r)
    {
        return;
    }
    int m=(l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    
}

int main()
{
    vector<int>v;
    int n,val;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }

    mergeSort(v,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}