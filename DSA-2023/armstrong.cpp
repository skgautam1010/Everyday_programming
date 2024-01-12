#include <bits/stdc++.h>
bool checkArmstrong(int n){
	//Write your code here
	int sum=0;
	int dup=n;
	
	while(n>0)
	{
		int rem=n%10;
		sum=sum+rem*rem*rem;
		n=n/10;
	}

	if(sum==dup)
	{
		return true;
	}
	else{
		return false;
	}
	
}
