#include<bits/stdc++.h>

using namespace std;

int main()
{
	while(true)
	{
    	int n1,sum=0;
		cin>>n1;
		if(n1==0){break;}
		else
		{
			int arr1[n1];
			for(int i=0;i<n1;i++)
			{
				cin>>arr1[i];
			}
			int n2;
			cin>>n2;
			int arr2[n2];
			for(int i=0;i<n2;i++)
			{
				cin>>arr2[i];
			}
	
			int j=0,k=0,temp_sum1=0,temp_sum2=0;
			while(j<n1 && k<n2)
			{
					if(arr1[j]<arr2[k])
				{
					temp_sum1 +=arr1[j++];
				}
				else if(arr2[k]<arr1[j])
				{
					temp_sum2 +=arr2[k++];
				}
				else
				{
					sum =sum+max(temp_sum1,temp_sum2)+arr1[j];
					temp_sum1=0;
						temp_sum2=0;
					j++;k++;
				}
			}
			while(j<n1)
			{
				temp_sum1+=arr1[j++];
			}
			while(k<n2)
			{
				temp_sum2 +=arr2[k++];
			}
			sum =sum+max(temp_sum1,temp_sum2);
			cout<<sum<<endl;
		}
	}
	return 0;
}