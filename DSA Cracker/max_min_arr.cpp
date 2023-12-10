//maximum and minimum element in an array

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Pair
{
    int min;
    int max;
};
struct Pair max_min(int arr[],int n)
{
    struct Pair minmax;
    if(n==1)
    {
        minmax.min=arr[0];
        minmax.max=arr[0];
        return minmax;

    }
    if(arr[0]<arr[1])
    {
        minmax.min=arr[0];
        minmax.max=arr[1];   
    }
    else
    {
        minmax.min=arr[1];
        minmax.max=arr[0];
    }
    
    for(int i=2;i<=n;i++)
    {
        if(arr[i]>minmax.max)
        {
            minmax.max=arr[i];
        }
        else if(arr[i]<minmax.min)
        {
            minmax.min=arr[i];
        }
    }
    return minmax;
}

int main()
{
    int arr[]={10,6,76,25,87,45};
    int n=6;
    struct Pair minmax=max_min(arr,n);
    cout<<"min val\t"<<minmax.min<<"\tmax val\t"<<minmax.max<<"\n";
    return 0;
}