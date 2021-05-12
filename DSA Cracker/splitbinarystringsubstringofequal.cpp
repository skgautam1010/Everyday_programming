
#include<bits/stdc++.h>

using namespace std;



int maxSubStr(string str,int n)
{
	int count0=0,count1=0,count=0;

	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
		{
			count0++;
		}
		else{
			count1++;
		}
		if(count1==count0)
		{
			count++;
		}
	}

	if(count1!=count0)
	{
		return -1;
	}
	else{
		return count;
	}
}


int main()
{
    string str = "0100110101";
    int n = str.length();
  
    cout << maxSubStr(str, n)<<endl;
  
    return 0;
}