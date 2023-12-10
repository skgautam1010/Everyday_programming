
/*
Stickler Thief
Easy Accuracy: 50.32% Submissions: 17930 Points: 2

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110

Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4

Your Task:
Complete the function FindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the rules
 

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).

Constraints:
1 <= n <= 104
1 <= a[i] <= 104

*/




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    ll FindMaxSum(ll arr[], ll n)
    {
        //long long int ans;
        long long int include=arr[0],exclude=0;
        for(int i=1;i<n;i++)
        {
            int temp=include;
            include=max(include,exclude+arr[i]);
            exclude=temp;
            
        }
        return max(include,exclude);
        
        
    }


    //Another Aproach

    ll FindMaxSum(ll arr[], ll n)
    {
        if(n<2)
        {
            return arr[0];
        }
        long long int dp[n];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        
        return dp[n-1];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends