

#include <bits/stdc++.h>
using namespace std;

bool solve(int *arr,int mid,int p,int n)
{
	int timing=0;
	int paratha=0;
	for(int i=0;i<n;i++)
	{
		timing=arr[i];
		int j=2;
		while(timing<=mid)
		{
			paratha++;
			timing=timing+(arr[i]*j);
			j++;
		}
		if(paratha>=p){return true;}
	}
	return false;
}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int p;
		cin>>p;
		int l;
		cin>>l;
		int arr[l];
		for(int i=0;i<l;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<l;i++)
		{
			cout<<arr[i]<<"  ";
		}
		int lb=0;
		int ub=1e8;
		int ans=0,mid;
		while(lb<=ub)
		{
			mid=(lb+ub)/2;
			if(solve(arr,mid,p,l))
			{
				ans=mid;
				ub=mid-1;
			}
			else
			{
				lb=mid+1;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}