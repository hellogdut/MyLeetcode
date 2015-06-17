class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j)
        {
            if(nums[i] != val)
                i++;
            else if(nums[i] == val && nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
                j--;
            }
            else if (nums[i] == val && nums[j] == val)
            {
                j--;
            }
        }
        return j + 1;
    }
};
