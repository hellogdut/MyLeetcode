class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

       if(nums.size() == 0)
          return 0;
       return binary_search(nums,0,nums.size() - 1,target);

        
    }
    int binary_search(vector<int>& nums,int low,int high,int target)
    {
        int mid = (low + high) / 2;
        if(nums[mid] == target)
            return mid;

        if(nums[mid] < target)
        {
           // 插入到 mid 后面
           if(mid + 1 > high)
              return mid + 1;
            return binary_search(nums,mid + 1,high,target);
        }
        // 插入到 mid 前面，下标即 mid
        if(low > mid - 1)
           return mid;
        return binary_search(nums,low,mid - 1,target);
        
    }
};
