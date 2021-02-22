
/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true
*/







//Elaborate Solution of the Same Problem

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(!st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']'))
            {
                if(s[i]==')')
                {
                    if(st.top()!='(')
                    {
                        return false;
                    }
                    st.pop();
                }
            
                else if(s[i]=='}')
                {
                    if(st.top()!='{')
                    {
                        return false;
                    }
                    st.pop();
                }
                 else if(s[i]==']')
                {
                    if(st.top()!='[')
                    {   
                        return false;
                    }
                    st.pop();
                }
            }
            else if(s[i]==']' || s[i]=='}' || s[i]==')')
            {
                return false;
            }
        }
        if(st.size()==0)
        {
            return true;   
        }
        else
        {
            return false;
        }
    }
};







//Concise Solution
stack<char> st;
       for(int i=0;i<s.size();i++){
           if(s[i] =='(' || s[i] =='[' || s[i]=='{'){
               st.push(s[i]);
           }else if(!st.empty() && ((s[i] ==')' && st.top() =='(') || (s[i] =='}' &&st.top() =='{') || (s[i] ==']' && st.top() =='[' ))){
               st.pop();
           }else if (s[i] == ')' || s[i]=='}'||s[i]==']'){
               return false;
           }
        }
        if(st.size() ==0){
            return true;
        }else{
            return false;
        }