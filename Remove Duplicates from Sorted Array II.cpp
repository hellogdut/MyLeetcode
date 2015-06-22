class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 1)
            return nums.size();
        vector<int> vec;
        int c = nums[0];
        int i = 1;
        int n = 1;
        vec.push_back(c);
        while(i < nums.size())
        {
            if(nums[i] == c && n < 2)
            {
                vec.push_back(nums[i]);
                n++;
                i++;
                continue;
            }
            if(nums[i] != c)
            {
                vec.push_back(nums[i]);
                c = nums[i];
                n = 1;
                i++;
                continue;
            }
            while(i < nums.size() && nums[i] == c)
                i++;
        }
        nums.swap(vec);
        return nums.size();
    }
    
};
