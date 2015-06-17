class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 1;
        
        // [1,2,0] return 3,
        // [3,4,-1,1] return 2.
        
        for(int i = 0;i < nums.size();)
        {
            if(nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            {
                //nums.swap(nums + i,nums + nums[i]);
                iter_swap(nums.begin() + i, nums.begin() + nums[i] - 1);
            }
            else
                i++;
        }
        for(int i = 0;i < nums.size();++i)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }
        
        return nums.back() + 1;
        
        
    }
};
