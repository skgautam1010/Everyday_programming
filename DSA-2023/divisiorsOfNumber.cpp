#include<bits/stdc++.h>

using namespace std;


int divisor(int x)
{
	int sum=0;
	for(int i=1;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			
			sum=sum+i;
			if((x/i)!=i)
			{
				sum=sum+(int)(x/i);
			}
		}
	}	
	return sum;
}



int sumOfAllDivisors(int n){
	// Write your code here.

	
	int res=0;
	int i=1;
	while(i<=n)
	{
		res=res+divisor(i);
		i++;
	}
	
	return res;
}