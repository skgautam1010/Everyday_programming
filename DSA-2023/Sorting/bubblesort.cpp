
#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& arr, int n) 
{
    //write your code here
    for(int i=n-1;i>0;i--)
    {
        int didSwap=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwap=1;
            }
            
        }
        if(didSwap==0)  //with this best case is derived. if the array is already sorted then we don't need to sort this again and again 
        {
            break;
        }
    }
}