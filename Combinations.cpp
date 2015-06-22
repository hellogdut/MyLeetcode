class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> nums;
        
        
        for(int i = 1;i <= n;++i)
            nums.push_back(i);
        for(int i = 0;i < nums.size();++i)
        {
            vector<int> s;
            s.push_back(nums[i]);
            _combine(result,s,nums,i + 1,k - 1);
            s.pop_back();
        }
        
        return result;
        
    }
    void _combine(vector<vector<int>>& result,vector<int>& s,vector<int>& nums,int i,int k)
    {
        if(i > nums.size() - k)
            return;
        if(k == 0)
        {
            result.push_back(s);
            return;
        }
        s.push_back(nums[i]);
        _combine(result,s,nums,i + 1,k - 1);
        s.pop_back();
        
        _combine(result,s,nums,i + 1,k);
        
        
    }
};
