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

        // Ñ¡Ôñµ±Ç°ÔªËØ£¬ÏòºóÃæÒª k - 1 ¸öÔªËØ
        // ±£Ö¤Ò»¶¨ÓÐ½á¹û
        curr.push_back(nums[i]);
        _subsetsWithDup(result,nums,curr,i + 1,k - 1);
        curr.pop_back();

        // ÏÂÒ»¸öÔªËØ±ØÐë¸ú¸Õ²ÅÑ¡ÔñµÄ²»Í¬
        // ±£Ö¤²»»áÓÐÏàÍ¬Â·¾¶
        int a = nums[i];
        while(i < nums.size() && nums[i] == a)
            i++;
        // ÒªÃ´Ô½½ç£¬ÒªÃ´ÕÒµ½ÁË²»Í¬ÔªËØ
        return _subsetsWithDup(result,nums,curr,i,k);


    }
};
