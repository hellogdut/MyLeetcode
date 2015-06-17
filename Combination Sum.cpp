class Solution {
private:
    vector<vector<int>> vec;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        unique(candidates.begin(), candidates.end());
        vector<int> rst;
        combination(candidates,rst,target,0);
        return vec;
    }
    void combination(vector<int>& cand,vector<int>& rst,int target,int from)
    {
        
        if(target == 0)
        {
            vec.push_back(rst);
            return ;
        }
        
        for(int i = from;i < cand.size();++i)
        {
            if(target < cand[from])
            {
                return;
            }
            rst.push_back(cand[i]);
            combination(cand,rst,target - cand[i],i);
            rst.pop_back();
        }
    }
};
