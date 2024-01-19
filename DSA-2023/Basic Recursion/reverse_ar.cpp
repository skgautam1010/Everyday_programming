
#include<bits/stdc++.h>

using namespace std;


void reverseAr(int i,int n,vector<int> &nums)
{
    if(i>n)
    {
        return;
    }
    int temp=nums[i];
    nums[i]=nums[n];
    nums[n]=temp;
    reverseAr(i+1, n-1, nums);

}

vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    reverseAr(0,n-1,nums);
    return nums;

}
