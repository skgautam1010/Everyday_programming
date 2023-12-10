/*
Find the median
School Accuracy: 47.87% Submissions: 8673 Points: 0

Given an array arr[] of N integers, calculate the median
 

Example 1:

Input: N = 5
arr[] = 90 100 78 89 67
Output: 89
Explanation: After sorting the array 
middle element is the median 

Example 2:

Input: N = 4
arr[] = 56 67 30 79â€‹
Output: 61
Explanation: In case of even number of 
elemebts average of two middle elements 
is the median

*/


// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    int result;
		    int n=v.size();
		    int mid;
		    if(n%2==0)
		    {
		        int temp1=(n/2);
		        int temp2=(n/2)+1;
		        result=(v[temp1-1]+v[temp2-1])/2;
		    }
		    else
		    {
		        int temp3=(n+1)/2;
		        result=v[temp3-1];
		    }
		    return result;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends