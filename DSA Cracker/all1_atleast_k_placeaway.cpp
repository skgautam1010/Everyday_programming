class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int start=0;
        int end;
        int n=nums.size();
        for (end=1;end<n;end++)
        {
            if(nums[end]==1)
            {
                if(nums[start]==1)
                {
                    if(end-start-1<k)
                    {
                        return false;
                    }
                }
                start=end;
            }
        }
        return true;
    }
};