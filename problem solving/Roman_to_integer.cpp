/*

Roman to Integer
Easy

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3

Example 2:

Input: s = "IV"
Output: 4
*/



class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int>mp;
        mp['M']=1000;
        mp['D']=500;
        mp['C']=100;
        mp['L']=50;
        mp['X']=10;
        mp['V']=5;
        mp['I']=1;
        
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]>=mp[s[i+1]])
            {
                result +=mp[s[i]];
            }
            else
            {
                int temp=mp[s[i+1]];
                temp=temp-mp[s[i]];
                result +=temp;
                i++;
            }
        }
        return result;
    }
};


//Another Approach
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='C' && s[i+1]=='M')
            {
                result +=900;
                i +=2;
            }
            else if(s[i]=='C' && s[i+1]=='D')
            {
                result +=400;
                i +=2;
            }
            else if(s[i]=='X' && s[i+1]=='C')
            {
                result +=90;
                i +=2;
            }
            else if(s[i]=='X' && s[i+1]=='L')
            {
                result +=40;
                i +=2;
            }
            else if(s[i]=='I' && s[i+1]=='X')
            {
                result +=9;
                i +=2;
            }
            else if(s[i]=='I' && s[i+1]=='V')
            {
                result +=4;
                i +=2;
            }
            else if(s[i]=='M')
            {
                result +=1000;
                i +=1;
            }
            else if(s[i]=='D')
            {
                result +=500;
                i +=1;
            }
            else if(s[i]=='C')
            {
                result +=100;
                i++;
            }
            else if(s[i]=='L')
            {
                result +=50;
                i++;
            }
            else if(s[i]=='X')
            {
                result +=10;
                i++;
            }
            else if(s[i]=='V')
            {
                result +=5;
                i++;
            }
            else if(s[i]=='I')
            {
                result +=1;
                i++;
            }
            else
            {
                i++;
            }
        }
        return result;
    }
};