#include<bits/stdc++.h>


using namespace std;

int main()
{
    string str;
    cin>>str;
    int n=str.length();
    string res="";
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            res +=str[i];
        }
        else{
            if(str[i]=='z')
            {
                res +='a';
            }
            else if(str[i]=='Z')
            {
                res +='A';
            }
            else{
                res +=char(str[i]+1);
            }
        }
    }

    cout<<res<<endl;
}