#include<bits/stdc++.h>

using namespace std;

long long int solve(long long int g)
{
    long long int count=0;
    long long int sum;
    for(int i=1;i<=g;i++)
    {
        sum=0;
        for(int j=i;j<=g;j++)
        {
            sum +=j;
            if(sum>g)
            {
                break;
            }
            if(sum==g)
            {
                count++;
                break;
            }
        }
    }
    return count;
}
int main()
{
    
    long long int t;
    cin>>t;
    int i=1;
    long long int g,res;
    while(t--)
    {
        cin>>g;
        res=solve(g);
        cout<<"Case #"<<i++<<":"<<" "<<res<<endl;
        
    }
    return 0;
}