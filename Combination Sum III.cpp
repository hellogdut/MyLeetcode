class Solution {
private:
    vector<vector<int>> result;
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        vector<int> solution;
        
        _combinationSum(candidates,solution,0,k,n);
        return result;
        
        
    }
    void _combinationSum(vector<int>& cand,vector<int>& solution,int start,int k,int n)
    {
        if(n < 0 || k < 0)
            return;
        
        if(k == 0 && n == 0)
        {
            result.push_back(solution);
            return;
        }
        
        for(int i = start;i < 9;++i)
        {
            solution.push_back(cand[i]);
            _combinationSum(cand,solution,i + 1,k - 1,n - cand[i]);
            solution.pop_back();
        }
    }
};
