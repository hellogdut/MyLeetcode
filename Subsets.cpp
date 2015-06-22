class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> result;
        result.push_back(vector<int>());
        
        sort(nums.begin(),nums.end());
        for(int i = 1;i <= nums.size();++i)
        {
            combine(result,nums,i);
        }
        return result;
    }
private:
    vector<vector<int>> combine(vector<vector<int>>& result,vector<int>& nums, int k) {
        
        
        for(int i = 0;i < nums.size();++i)
        {
            vector<int> s;
            s.push_back(nums[i]);
            _combine(result,s,nums,i + 1,k - 1);
            s.pop_back();
        }
//        sort(result.begin(),result.end(),[](const vector<int>&v1,const vector<int>&v2){return v1.size() < v2.size();});
        
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

