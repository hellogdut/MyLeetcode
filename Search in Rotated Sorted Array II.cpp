class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int m = nums.back();
        int j = nums.size() - 1;

        
        // ÕÒµ½×î×ó±ß±Ènums[0]´óµÄ
        while(j >= 0 && nums[j] <= m)
            j--;
        // 33112
        // »®·Ö³É×óÓÒ´óÐ¡Êý×é
        if(j >= 0)
        {
            vector<int> big(nums.begin(),nums.begin() + j + 1);
            vector<int> small(nums.begin() + j + 1,nums.end());
            return binSearch(big,target) || binSearch(small,target);
        }

        // 333333
        // ´Ó×óµ½ÓÒÕÒ±Ènums[0]Ð¡µÄ£¬»®·Ö³ÉÁ½¸öÊý×é
        j = 0;
        while(j < nums.size() && nums[j] >= nums[0])
            j++;
        if(j == nums.size())
        {
            // ÕÒ²»µ½£¬ËµÃ÷Êý×éÓÐÐò
            return binSearch(nums,target);
        }
        else
        {
            // 331133
            // »®·Ö³ÉÁ½¸öÊý×é
            vector<int> big(nums.begin(),nums.begin() + j);
            vector<int> small(nums.begin() + j,nums.end());
            return binSearch(big,target) || binSearch(small,target);
        }
        return false;

    }
    bool binSearch(vector<int>& vec,int target)
    {
        int low = 0;
        int high = vec.size() - 1;
        while(low <= high)
        {
            int mid = (high - low) / 2 + low;
            if(vec[mid] == target)
                return true;
            else if(vec[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
