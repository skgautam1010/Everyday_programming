
//Subarray with 0 sum 


//Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum
// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


//Complete this function
bool subArrayExists(int arr[], int n)
{
    //Your code here
    int sum=0;
    unordered_set<int>sumset;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum==0 || sumset.find(sum)!=sumset.end())
        {
            return true;
        }
        sumset.insert(sum);
        
    }
    return false;
}


