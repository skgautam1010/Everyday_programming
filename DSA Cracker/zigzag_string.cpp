/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
*/


class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>rows(numRows);
        int d=numRows-1;
        if(numRows==1)
        {
            return s;
        }
        for(int i=0;i<s.length();i++)
        {
            if(i%(2*d)<d)
            {
                rows[i%(2*d)] +=s[i];
            }
            else
            {
                rows[d-(i%d)]  +=s[i];
            }
        }
        string result="";
        for(string row:rows)
        {
            result +=row;
        }
        return result;
            
    }
};