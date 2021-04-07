
/*Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:

Input: s = "textbook"
Output: false
*/


class Solution {
public:
    bool halvesAreAlike(string s) {
        string vow="aeiouAEIOU";
        string a,b;
        int n=s.length();
        int half=n/2;
        a=s.substr(0,half);
        b=s.substr(half);
        int count1=0,count2=0;
        for(int i=0;i<a.length();i++)
        {
            size_t found=vow.find(a[i]);
            if(found!=string::npos)
            {
                count1++;
            }
        }
        for(int i=0;i<b.length();i++)
        {
            size_t found=vow.find(b[i]);
            if(found!=string::npos)
            {
                count2++;
            }
        }
        
        if(count1==count2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};