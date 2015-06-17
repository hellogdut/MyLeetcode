class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> v;
        int n = binary_search(nums,0,nums.size() - 1,target);
        if(n == -1)
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        else
        {
            int i = n - 1;
            int j = n + 1;
            while(i >= 0 && nums[i] == target)
                i--;
            while(j <= nums.size() - 1 && nums[j] == target)
                j++;
            v.push_back(i + 1);
            v.push_back(j - 1);
        }
        return v;
        
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
