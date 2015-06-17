class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size() - 1;
        int ii = i - 1;
        while(ii >= 0 && nums[ii] >= nums[i])
        {
            --i;
            --ii;
        }
        if(ii < 0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int j = nums.size() - 1;
        
        while(j > i && nums[j] <= nums[ii])
            j--;
        
        int t = nums[ii];
        nums[ii] = nums[j];
        nums[j] = t;
        
        j = nums.size() - 1;
        
        while(i < j)
        {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            ++i;
            --j;
        }
    }
};
