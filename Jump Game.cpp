class Solution {
public:
    bool canJump(vector<int>& nums) {

        int last = 0;
        int curr = 0;
        int i = 0;
        while(i < nums.size() - 1)
        {
            last = max(last,i + nums[i]);
            if(nums[i] == 0 && i >= last)
                break;
            i++;
        }
        return last >= nums.size() - 1;


    }
};
