
//Important
/*AGGRCOW - Aggressive cows
#binary-search

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input

t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output

For each test case output one integer: the largest minimum distance.
Example

Input:

1
5 3
1
2
8
4
9

Output:

3
*/




    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	
    	int t;
    	cin>>t;
    	int n,c;
    	int arr[n];
    	while(t--)
    	{
    		cin>>n>>c;
    		for(int i=0;i<n;i++)
    		{
    			cin>>arr[i];
    		}
    		sort(arr,arr+n);
    		long long int lb=1;
    		long long int ub=1e9;
    		int ans=0;
    		int cow;
    		int prev;
    		long long int mid;
    		while(lb<=ub)
    		{
    			mid=(lb+ub)/2;
    			cow=1;
    			prev=arr[0];
    			for(int i=1;i<n;i++)
    			{
    				if(arr[i]-prev>=mid)
    				{
    					cow++;
    					prev=arr[i];
    					if(c==cow)
    					{
    						break;
    					}
    				}
    			}
    			if(c==cow)
    			{
    				ans=mid;
    				lb=mid+1;
    			}
    			else
    			{
    				ub=mid-1;
    			}
    		}
    		cout<<ans<<endl;
    	}
     
    	return 0;
    } 