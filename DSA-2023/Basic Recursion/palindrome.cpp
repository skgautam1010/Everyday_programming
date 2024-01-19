#include<bits/stdc++.h>


using namespace std;

bool rev(int i, string &str)
{
    if(i>=str.size()/2)
    {
        return true;
    }
    if(str[i]!=str[str.size()-i-1])
    {
        return false;
    }
   
    rev(i+1,str);
}
bool isPalindrome(string& str) {
    // Write your code here.
    return rev(0,str);
   
 
}
