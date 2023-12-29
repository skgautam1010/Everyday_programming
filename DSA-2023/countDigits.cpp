#include<bits/stdc++.h>
using namespace std;


int countDigits(int n){
	// Write your code here.
	int m=n;
	int count=0;
	while(m>0)
	{
		int s=m%10;
		if(s!=0)
		{
			if(n%s==0)
			{
				count++;
			}
		}
		
		m=m/10;
	}	


	return count;	
}

int main()
{
    int n;
    cout<<"enter the value";
    cin>>n;
    int res=countDigits(n);
    cout<<res<<endl;
    return 0;
}