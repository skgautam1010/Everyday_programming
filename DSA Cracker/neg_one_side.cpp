#include<bits/stdc++.h>
#include<iostream>

using namespace std;



void shiftall(int ar[],int left,int right)
{
	while(left<=right)
	{
		if(ar[left]<0 && ar[right]<0)
		{
			left++;
		}
		else if(ar[left]>0 && ar[right]<0)
		{
			int temp=ar[left];
			ar[left]=ar[right];
			ar[right]=temp;
		}
		else if(ar[left]>0 && ar[right]>0)
		{
			right--;
		}
		else{
			right--;
			left++;
		}


	}
}

void display(int arr[], int right){
   
  // Loop to iterate over the element
  // of the given array
  for (int i=0;i<=right;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main()
{
	int arr[] = {-12, 11, -13, -5, 
               6, -7, 5, -3, 11};
  int arr_size = sizeof(arr) / 
                sizeof(arr[0]);
   
  // Function Call
  shiftall(arr,0,arr_size-1);
  display(arr,arr_size-1);
  return 0;
}