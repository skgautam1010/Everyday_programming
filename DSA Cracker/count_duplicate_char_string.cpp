
/*
Write an efficient program to print all the duplicates and their counts in the input string 
Let input string be “geeksforgeeks” 
1: Construct character count array from the input string.
count[‘e’] = 4 
count[‘g’] = 2 
count[‘k’] = 2 
...
*/

#include <bits/stdc++.h>
using namespace std;

void printDups(string str)
{
	int n=str.length();
	map<char,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[str[i]]=mp[str[i]]+1;
	}

	for(auto it:mp)
	{
		if(it.second>1)
		{
			cout<<it.first<<": "<<it.second<<"\n";
		}
	}
}

int main()
{
    string str = "abcdefgh";
    printDups(str);
    return 0;
}