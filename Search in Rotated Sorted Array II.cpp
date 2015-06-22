class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int m = nums.back();
        int j = nums.size() - 1;

        
        // 找到最左边比nums[0]大的
        while(j >= 0 && nums[j] <= m)
            j--;
        // 33112
        // 划分成左右大小数组
        if(j >= 0)
        {
            vector<int> big(nums.begin(),nums.begin() + j + 1);
            vector<int> small(nums.begin() + j + 1,nums.end());
            return binSearch(big,target) || binSearch(small,target);
        }

        // 333333
        // 从左到右找比nums[0]小的，划分成两个数组
        j = 0;
        while(j < nums.size() && nums[j] >= nums[0])
            j++;
        if(j == nums.size())
        {
            // 找不到，说明数组有序
            return binSearch(nums,target);
        }
        else
        {
            // 331133
            // 划分成两个数组
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
