
#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& arr, int n) 
{
    //write your code here
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
    }
}