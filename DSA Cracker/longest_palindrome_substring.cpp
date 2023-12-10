class Solution {
public:
    string longestPalindrome(string s) {
        int palindrome_begin=0;
        int palindrome_len=1;
        int n=s.length();
        bool is_palindrome[n][n];
        memset(is_palindrome,false,sizeof(bool)*n*n);
        //every character is a palindrome in itself
        for(int i=0;i<n;i++)
        {
            is_palindrome[i][i]=true;
        }
        //every adjacent character if similar is a palindrome
        for(int i=0;i<n-1;i++)
        {
            if(s.at(i)==s.at(i+1))
            {
                is_palindrome[i][i+1]=true;
                palindrome_begin=i;
                palindrome_len=2;
            }
        }
        //start to check from the length of the string as 3
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j] && is_palindrome[i+1][j-1]==true)
                {
                    is_palindrome[i][j]=true;
                    if(len>palindrome_len)
                    {
                        palindrome_begin=i;
                        palindrome_len=len;
                    }
                }
            }
        }
        string str=s.substr(palindrome_begin,palindrome_len);
        return str;
    }
};