


/*Minimum Swaps to Sort
Medium Accuracy: 50.0% Submissions: 47726 Points: 4

Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.

Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.


Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 106*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    vector<pair<int,int>>v(n);
	    vector<bool>visited(n,false);
	    
	    for(int i=0;i<n;i++)
	    {
	        v[i].first=nums[i];
	        v[i].second=i;
	    }
	    
	   
	    sort(v.begin(),v.end());
	    
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(visited[i]|| v[i].second==i)
	        {
	            continue;
	        }
	        int cyclesize=0;
	        int j=i;
	        while(!visited[j])
	        {
	            visited[j]=1;
	            j=v[j].second;
	            cyclesize++;
	        }
	        if(cyclesize>0)
	        {
	            ans +=cyclesize-1;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends