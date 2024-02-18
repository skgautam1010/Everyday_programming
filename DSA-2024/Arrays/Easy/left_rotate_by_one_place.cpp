#include <bits/stdc++.h> 

using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
   
    //one Approach

    int temp=arr[0];
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            arr[i]=temp;
            break;
        }
        arr[i]=arr[i+1];

    }
    return arr;


    //Another Approach

    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];

    }
    arr[n-1]=temp;
    return arr;


    //Another Approach
   vector<int>result;

   int i=1,j=0;
   while(i!=j)
   {
       result.push_back(arr[i]);
       
       i++;
       if(i==n)
       {
           i=0;
           result.push_back(arr[i]);
           
       }
   }
   return result;
}
