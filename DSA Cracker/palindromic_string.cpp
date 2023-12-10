
/*
Palindrome String
Easy Accuracy: 50.77% Submissions: 19032 Points: 2

Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome

Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
*/

// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    // Your code goes here
	    string str=S;
	    int n=S.length();
	    int i=0;
	    int sze=n/2;
	    /* while(i<sze)
	    {
	        swap(S[i],S[n-i-1]);
	    }*/
	    reverse(S.begin(),S.end());
	    if(str==S)
	    {
	        return 1;
	    }
	    else
	    {
	        return 0;
	    }
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends