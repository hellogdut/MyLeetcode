class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int i = nums.size() - 1;
        while(nums[i] < nums[0] && i > 0)
            i--;
        
        if(target < nums[0])
            return binary_search(nums,i + 1,nums.size() - 1,target);
        else
            return binary_search(nums,0,i,target);
    }
    int binary_search(vector<int>& nums,int low,int high,int target)
    {
        if(low > high)
            return - 1;
        int mid = (low + high) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            return binary_search(nums,mid + 1,high,target);
        return binary_search(nums,low,mid - 1,target);
        
    }
};

