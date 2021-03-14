
/*Smallest subarray with sum greater than x
Easy Accuracy: 48.92% Submissions: 4547 Points: 2

Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}


Example 2:

Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}

*/


// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        int start=0;
        int end=1;
        int temp=arr[start];
        int length=99999;
        if(n==1)
        {
            return 1;
        }
        while(end<n)
        {
            if(arr[end]>x || arr[start]>x)
            {
                return 1;
            }
            else
            {
                temp += arr[end];
                if(temp>x)
                {
                    length=min(length,((end-start)+1));
                    start++;
                    end=start+1;
                    temp=arr[start];
                }
                else
                {
                    end++;
                }
                
            }
        }
        return length;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends