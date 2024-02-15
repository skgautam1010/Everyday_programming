#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.

    //Brute Force Approach

	set<int>st;
	for(int i=0;i<n;i++)
	{
		st.insert(arr[i]);
	}
	return st.size();


    //Optimal Approach

    int i=0,j=1;
	while(j<n)
	{
		if(arr[i]!=arr[j]){
			arr[i+1]=arr[j];
			i++;
			
		}
		j++;
	}
	return i+1;

}