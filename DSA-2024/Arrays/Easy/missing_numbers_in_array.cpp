#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Optimal Approach

         int n=nums.size();
        int sum_of_n_natural_number=(n*(n+1))/2;
        int sum=0,result=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }

        result=abs(sum_of_n_natural_number-sum);
        return result;


        //2nd Optimal Approach

         int n=nums.size();
       int xor1=0,xor2=0;
       for(int i=0;i<n;i++)
       {
           xor2=xor2^nums[i];
           xor1=xor1^(i+1);
       }
        return xor1^xor2;
    


        //Brute Force Approach

        int n=nums.size();
        int flag=0;
        for(int i=0;i<=n;i++)
        {
            flag=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]==i)
                {
                    flag=1;
                    break;
                }
            }
             if(flag==0)
            {
                return i;
            }
           
        }
        
        
    }
};