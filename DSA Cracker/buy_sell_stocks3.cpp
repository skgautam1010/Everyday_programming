/*Maximum profit by buying and selling a share at most twice
Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80

Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
Output:  100
Trader earns 100 as sum of 28 and 72
Buy at price 2, sell at 30, buy at 8 and sell at 80

Input:   price[] = {100, 30, 15, 10, 8, 25, 80};
Output:  72
Buy at price 8 and sell at 80.

Input:   price[] = {90, 80, 70, 60, 50}
Output:  0
Not possible to earn.*/



#include<bits/stdc++.h>

using namespace std;

int maxProfit(int price[],int n)
{
	int b=0,count=0;
	int s=1;
	int profit,result=0;
	int temp=0;
	while(s<n)
	{
		if(price[b]<price[s])
		{
			profit=price[s]-price[b];
			result=max(result,profit);
		}
		else
		{
			b=s;
			temp =temp+result;
			count++;
			if(count>1 && temp!=0)
			{
				break;
			}

		}
		if(s==n-1)
		{
			temp=temp+result;
		}
		s++;
	}
	return temp;
}

int main()
{
	int price[] = { 10, 22, 5, 75, 65, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n)<<"\n";
    return 0;
}