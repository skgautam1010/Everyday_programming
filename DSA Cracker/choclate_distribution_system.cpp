/*
Chocolate Distribution Problem
Easy Accuracy: 59.81% Submissions: 844 Points: 2

Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between 
maximum chocolates and minimum chocolates 
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}.

Example 2:

Input:
N = 7, M = 3
A = {7, 3, 2, 4, 9, 12, 56}
Output: 2
Explanation: The minimum difference between
maximum chocolates and minimum chocolates
is 4 - 2 = 2 by choosing following M packets :
{3, 2, 4}.
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a,long long n, long long m);

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		cout<<findMinDiff(a,n,m)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long result=a[n-1]+100;
    int start=0;
    int end=m-1;
    if(m==1)
    {
        return 0;
    }
    while(start<end && end<n)
    {
        result=min(result,a[end]-a[start]);
        start++;
        end++;
    }
    
    return result;
}