#include <bits/stdc++.h> 

using namespace std;

//Optimal Approach

int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int max_elem=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_elem)
        {
            max_elem=arr[i];
        }
    }
    return max_elem;
}

//Brute force Approach

  // Write your code here.

//    sort(arr.begin(),arr.end());
//    return arr[n-1];


