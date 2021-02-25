/*Given a balanced parentheses string S, compute the score of the string based on the following rule:

    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

    Input: "(())"
Output: 2

Example 3:

Input: "()()"
Output: 2

Example 4:

Input: "(()(()))"
Output: 6
*/



class Solution {
public:
    int scoreOfParentheses(string S) {
        int result=0;
        int n=S.length();
        int count=0;
        for(int i=1;i<n;i++)
        {
            if(S[i]=='(')
            {
                count +=1;
            }
            else if(S[i-1]=='(')
            {
                result +=1<<count--;
            }
            else
            {
                count--;
            }
        }
        return result;
        
    }
};