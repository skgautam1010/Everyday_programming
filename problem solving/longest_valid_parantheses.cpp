
/*Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.length();
        st.push(-1);
        if(n==0 || n==1)
        {
            return 0;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' )
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    count=max(count,(i-st.top()));
                }
                
            }
        }
        return count;
    }
};