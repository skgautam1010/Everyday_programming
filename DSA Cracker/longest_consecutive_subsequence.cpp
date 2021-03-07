/*
Longest consecutive subsequence
Medium Accuracy: 48.9% Submissions: 28924 Points: 4

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    // return the length of the longest subsequene of consecutive integers
    int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_set<int>s;
      int max_count=0;
      for(int i=0;i<N;i++)
      {
          if(s.find(arr[i])==s.end())
          {
              s.insert(arr[i]);
          }
      }
      for(int i=0;i<N;i++)
      {
      	if(s.find(arr[i]-1)==s.end())
      	{
      		int j=arr[i];
      		while(s.find(j)!=s.end())
      		{
      			j++;
      		}
      		max_count=max(max_count,j-arr[i]);
      	}
      }
      return max_count;
   }     
    };

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  
//  Driver Code Ends