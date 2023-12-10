//program to reverse an array or string

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reversearr(int arr[],int n)
{
    int start,end;
    start=0;
    end=n-1;
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int arr[]={10,32,12,15,43,41};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    reversearr(arr,n);
    return 0;
}