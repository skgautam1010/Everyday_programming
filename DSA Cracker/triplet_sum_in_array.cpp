


/*
Triplet Sum in Array
Medium Accuracy: 49.0% Submissions: 14316 Points: 4

Given an array arr of size N and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
N = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.

Example 2:

Input:
N = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for 
    //Function to find if there exists a triplet in the 
    //array arr[] which sums up to X.
    bool find3Numbers(int arr[], int N, int X)
    {
        sort(arr,arr+N);
        int i,j;
        for(int k=0;k<N;k++)
        {
            int tempsum=X-arr[k];
            i=k+1;
            j=N-1;
            while(i<j)
            {
                if(arr[i]+arr[j]==tempsum)
                {   
                    return 1;
                }
                else if(arr[i]+arr[j]<tempsum)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }
        return 0;
        
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends