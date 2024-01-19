#include<bits/stdc++.h>

using namespace std;

void print(int x, int n, vector<string>&res)
{
	if(x>n)
	{
		return;
	}
	res.push_back("Coding Ninjas");
	x++;
	print(x,n,res);
}


vector<string> printNTimes(int n) {
	// Write your code here.

	vector<string>res;
	print(1,n,res);
	return res;
}