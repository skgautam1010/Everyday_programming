#include<bits/stdc++.h>

#define int long long 

using namespace std;

int N=1e6;

int32_t main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int sum=0;
        
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
        }
         int forward_gcd[N];
            forward_gcd[0]=arr[0];
            for(int i=1;i<n;i++)
            {
                forward_gcd[i]=__gcd(forward_gcd[i-1],arr[i]);
            }

            int backward_gcd[N];
            backward_gcd[n-1]=arr[n-1];
            for(int i=n-2;i>=0;i--)
            {
                backward_gcd[i]=__gcd(backward_gcd[i+1],arr[i]);
            }

            int final_res[N];
            final_res[0]=backward_gcd[1];
            final_res[n-1]=forward_gcd[n-2];
            for(int i=1;i<n-1;i++)
            {
                final_res[i]=__gcd(forward_gcd[i-1],backward_gcd[i+1]);
            }

            int result=LLONG_MAX;
            int answer=0;
            for(int i=0;i<n;i++)
            {
                answer=((sum-arr[i]+final_res[i])/final_res[i]);
                result=min(answer,result);
            }
            cout<<result<<endl;
    }
    return 0;

}