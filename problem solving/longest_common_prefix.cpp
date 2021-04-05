
/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
        {
            return "";
        }
        string result="";
        sort(strs.begin(),strs.end());
        bool status=true;
        for(int i=0;i<strs[0].length();i++)
        {
            char ch=strs[0][i];
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]!=ch)
                {
                    status=false;
                    break;
                }
            }
            if(status==false)
            {
                break;
            }
            else
            {
                result +=ch;
            }
        }
        return result;
    }
};