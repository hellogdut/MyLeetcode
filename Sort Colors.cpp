class Solution {
public:
    void sortColors(vector<int>& nums) {

        int i = 0;
        for(int j = 0;j <= 2;++j)
        {
            i = swap(nums,i,j);
        }
        
    }
    int swap(vector<int>& nums,int begin,int target)
    {
        int n = nums.size() - 1;
        int i = begin;
        int j = n;
        if(i > j)
            return 0;
        while(i < j)
        {
            while(i <= nums.size() - 1 && nums[i] == target)
                i++;
            while(j >= begin && nums[j] != target)
                j--;
            if(i < j)
                iter_swap(nums.begin() + i,nums.begin() + j);
        }

        // j Îª×îºóÒ»¸ö target µÄÏÂÒ»¸öÎ»ÖÃ
        return j + 1;
    }
};
