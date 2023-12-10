'''
Longest Repeating Subsequence
Easy Accuracy: 56.59% Submissions: 5728 Points: 2

Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
 

Exampel 1:

Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".

Example 2:

Input: str = "aab"
output: 1
Explanation: The longest reapting subsequenece
is "a".

 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)
 '''


 #User function Template for python3

class Solution:
	def LongestRepeatingSubsequence(self, str):
		# Code here\
		n=len(str)
		
		dp=[[0 for i in range(n+1)] for j in range(n+1)]
		
		for i in range(1,n+1):
		    for j in range(1,n+1):
		        
		        if str[i-1]==str[j-1] and i!=j:
		            dp[i][j]=1+dp[i-1][j-1]
		            
		        else:
		            dp[i][j]=max(dp[i][j-1],dp[i-1][j])
		            
		return dp[n][n]

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		str = input()
		ob = Solution()
		ans = ob.LongestRepeatingSubsequence(str)
		print(ans)

# } Driver Code Ends