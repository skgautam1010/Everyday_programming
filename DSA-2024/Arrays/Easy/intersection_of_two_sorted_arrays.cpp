#include <bits/stdc++.h> 

using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.

    //Optimal Approach

    	vector<int>result;
	int i=0,j=0;

	while(i<n && j<m)
	{
		if(arr1[i]<arr2[j])
		{
			i++;
		}
		else if(arr1[i]>arr2[j])
		{
			j++;
		}
		else
		{
			result.push_back(arr1[i]);
			i++;j++;
		}
	}
	return result;

    

    //Brute - Force Approach

	vector<int>visited(m);

	vector<int>result;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr2[j]>arr1[i])
			{
				break;
			}

			if(arr1[i]==arr2[j] && visited[j]==0)
			{
				result.push_back(arr1[i]);
				visited[j]=1;
				break;
			}
		}
	}
	return result;
}