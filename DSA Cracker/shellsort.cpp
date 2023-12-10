#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void shellSort(int arr[],int n)
{
	int gap,i,j;
	for (gap=n/2;gap>0;gap=gap/2)
	{
		for(j=gap;j<n;j++)
		{
			for(i=j-gap;i>=0;i=i-gap)
			{
				if(arr[i+gap]>arr[i])
				{
					break;
				}
				else
				{
					swap(arr[i+gap],arr[i]);
				}
			}
		}
	}
}

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " ";
    cout<<"\n"; 
} 

int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Array before sorting: \n"; 
    printArray(arr, n); 
  
    shellSort(arr, n); 
  
    cout << "\nArray after sorting: \n"; 
    printArray(arr, n); 
  
    return 0; 
}