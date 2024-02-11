
#include<bits/stdc++.h>

using namespace std;

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/



int partitionArray(int input[], int start, int end) {
	// Write your code here

	int pivot=start;
	int i=start;
	int j=end;

	while(i<j)
	{
		while(input[i]<=input[pivot] && i<=end)
		{
			i++;
		}
		while(input[j]>input[pivot] && j>=start)
		{
			j--;
		}

		if(i<j)
		{
			int temp=input[i];
			input[i]=input[j];
			input[j]=temp;
		}
		if(i>j)
		{
			swap(input[j],input[pivot]);
		}
	}
	return j;

}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/
	
	if(start<end)
	{
		int partition=partitionArray(input, start, end);
		quickSort(input, start, partition-1);
		quickSort(input, partition+1, end);
	}
}