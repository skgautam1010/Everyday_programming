#include<vector>

using namespace std;

int getSingleElement(vector<int> &arr){
	// Write your code here.

	int n=arr.size();
	int xor1=0;
	for(int i=0;i<n;i++)
	{
		xor1=xor1^arr[i];
	}
	return xor1;
}