
Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
        vector<int>::iterator it;
        it=unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),it));
        return nums.size();
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // nums.erase(unique(nums.begin(),nums.end()),nums.end());
        // return nums.size();
        if (nums.size()==0)
            return 0;
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[j]!=nums[i])
            {
                j++;
                nums[j]=nums[i];
                
            }
        }
        return j+1;
        
    }
};