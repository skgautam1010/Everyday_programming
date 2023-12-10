

/*Non-decreasing Array

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
*/


class Solution {
public:
    /*int find_min(vector<int>nums)
    {
        int n=nums.size();
        int res=nums[0];
        for(int i=1;i<n;i++)
        {
            res=min(res,arr[i]);
        }
        return res;
    }*/
    /*int find_max(vector<int>nums)
    {
        int n=nums.size();
        int res=nums[0];
        for(int i=1;i<n;i++)
        {
            res=max(res,arr[i]);
        }
        return res;
    }*/
    
    //My Solution
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if (n==0)
        {
            return false;
        }
        if(n==1 || n==2)
        {
            return true;
        }
        //when n>=3
        if(n==3)
        {
                if(nums[0]>nums[1]&& nums[1]>nums[2] && nums[0]>nums[2])
                {
                    return false;
                }
            return true;
        }
        /*for(int i=0;i<n-1;i++)
        {
          for(int j=i+1;j<n-1;j++)
          {
              if(nums[i]>nums[j])
              {
                  if(nums[j]>nums[j+1])
                  {
                      return false;
                  }
              }
              else
              {
                  if(nums[i]>nums[j+1] && abs(nums[i]-nums[j+1])==1)
                  {
                      return false;
                  }*/
             /*     int count=0;
                  if(nums[j-1]>nums[j] && nums[j]<nums[j+1])
                  {
                      count++;
                  }
                  if(count>=2)
                  {
                      return false;
                  }
              }
          }
        }*/
        
       // min_elem=find_min(nums);
       // max_elem=find_max(nums);
    
//Efficient Solution
          int n=nums.size();
        for(int i=1,error=0;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(error++ || (i>1 && i<n-1 && nums[i-2] > nums[i] && nums[i+1]<nums[i-1]))
                {
                    return false;
                }
            }
        }
        return true;
    }

    }
};