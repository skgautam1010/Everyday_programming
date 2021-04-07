
/*3Sum Closest
Medium

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 */


 class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int val,sum;
        int j,k;
        long long int result=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            j=i+1;
            k=n-1;
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if(sum==target)
                {
                    return sum;
                }
                if(sum<target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
                if(abs(sum-target)<abs(result-target))
                {
                    result=sum;
                }
            }     
        }
        return result;
        
    }
};