
/*

Maximum Product Subarray
Easy Accuracy: 29.84% Submissions: 24590 Points: 2

Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is  6, -3, -10 which gives product as 180.
*/



// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long max1=1,min1=1,overallmax=0;
	    long long count=1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>0)
	        {
	            max1=max1*arr[i];
	            min1=min((min1*arr[i]),count);
	        }
	        else if(arr[i]==0)
	        {
	            max1=min1=count;
	        }
	        else if(arr[i]<0)
	        {
	            long long temp=max1;
	            max1=max((min1*arr[i]),count);
	            min1=temp*arr[i];
	        }
	        if(max1>overallmax)
	        {
	            overallmax=max1;
	        }
	    }
	    return overallmax;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends