#include <bits/stdc++.h>
using namespace std;
const int n=1e5+1;
const int M=1e9+7;
int a[n];
int prefix_sum[n];

int binexprecur(int a,int b)
{
    if(b==0) return 1;
    int res=binexprecur(a,b/2);
    if(b&1)
    {
        return a*((res*1LL*res)%M)%M;
    }
    else{
        return ((res*1LL*res)%M);
    }
}

int main() {

    for(int i=1;i<n;i++)
    {
        int k=i/10;
        int rev=i;
        while(k>0)
        {
            int rem=k%10;
            rev=rev*10+rem;
            k=k/10;
        }
        a[i]=rev;
    }
    prefix_sum[1]=a[1];
    for(int i=2;i<n;i++)
    {
        prefix_sum[i]=(prefix_sum[i-1]+a[i])%M;
    }
	int q;
	cin>>q;
	while(q--)
	{
	    int l,r;
	    cin>>l>>r;
	    int x=a[l];
	    int y=(prefix_sum[r]-prefix_sum[l]);
	    cout<<binexprecur(x,y)<<endl;
	}
	
	return 0;
}
