/*Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        int n=nums.size();
        int l=0,h=n-1;
        int mid,i=0,j=n-1;
        for(i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                result.push_back(i);
                break;
            }
        }
        for(j=n-1;j>=0;j--)
        {
            if(nums[j]==target)
            {
                result.push_back(j);
                break;
            }
        }
        if(result.size()==0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        /*if(result.size()==1)
        {
            result.push_back(result[0]);
        }*/
        return result;
        
    }
};