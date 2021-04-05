
/*Reverse String
Easy

Write a function that reverses a string. The input string is given as an array of characters s.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

 

Constraints:

    1 <= s.length <= 105
    s[i] is a printable ascii character.

 */


 class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int temp=n/2;
        int i=0,j=n-1;
        char temp1;
        while(i<temp)
        {
            temp1=s[i];
            s[i]=s[j];
            s[j]=temp1;
            i++;
            j--;
        }
        
    }
};