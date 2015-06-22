class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0;i <= nums.size();++i)
        {
            vector<int> curr;
            _subsetsWithDup(result,nums,curr,0,i);
        }
        return result;

        
    }

    void _subsetsWithDup(vector<vector<int>>& result,vector<int>& nums,vector<int>& curr,int i,int k)
    {
        if(k == 0)
        {
            result.push_back(curr);
            return ;
        }
        if(i >= nums.size())
            return;

        // 选择当前元素，向后面要 k - 1 个元素
        // 保证一定有结果
        curr.push_back(nums[i]);
        _subsetsWithDup(result,nums,curr,i + 1,k - 1);
        curr.pop_back();

        // 下一个元素必须跟刚才选择的不同
        // 保证不会有相同路径
        int a = nums[i];
        while(i < nums.size() && nums[i] == a)
            i++;
        // 要么越界，要么找到了不同元素
        return _subsetsWithDup(result,nums,curr,i,k);


    }
};
