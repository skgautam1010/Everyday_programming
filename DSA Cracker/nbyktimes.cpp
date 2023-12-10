//Given an array of size n and a number k, find all elements that appear more than n/k times

/*Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times. There are two elements that appear more than two times, 2 and 3. 
*/

#include<bits/stdc++.h>

using namespace std;
void moreThanNdK(int arr[],int n,int k)
{
	vector<int>temp;
	sort(arr,arr+n);
	int count=1;
	int i=0;
	int m=n/k;
	while(i<n)
	{
		while(i<n-1 && arr[i]==arr[i+1])
		{
			count++;
			i++;
		}
		if(count>m)
		{
			temp.push_back(arr[i]);
		}
		count=1;
		i++;
	}
	for(auto a:temp)
	{
		cout<<a<<" ";
	}
}
//Naive Approach
/*void moreThanNdK(int arr[],int n,int k)
{
	int i,j;
	vector<int>temp;
	int count;
	int m=n/k;
	for(i=0;i<n;i++)
	{
		int x=arr[i];
		count=1;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]==x)
			{
				count++;
			}
		}
		if(count>m)
		{
			temp.push_back(arr[i]);
		}
	}
	for(int i=0;i<temp.size();i++)
	{
		cout<<temp[i]<<" ";
	}
	cout<<"\n";	
}*/

int main()
{
	int arr1[] = { 3,1,2,2,1,2,3,3 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 4;
    moreThanNdK(arr1, size, k);
}