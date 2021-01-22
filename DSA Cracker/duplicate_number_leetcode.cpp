class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int temp;
        if(n<=1)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                temp=nums[i];
            }
        }
        return temp;
        
    }
};