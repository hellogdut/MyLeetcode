
class Solution {
private:
    vector<vector<int>> vec;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        
        
        vector<int> rst;
        combination(candidates,rst,target,0);
        
        //set<vector<int>> s(vec.begin(),vec.end());
        //vec.assign(s.begin(), s.end());
        
        return vec;
    }
    void combination(vector<int>& cand,vector<int>& rst,int target,int from)
    {
        if(target < 0)
            return;
        
        if(target == 0)
        {
            vec.push_back(rst);
            return ;
        }
        
        for(int i = from;i < cand.size();++i)
        {
            if(i > from && cand[i] == cand[i-1])
                continue;
            rst.push_back(cand[i]);
            combination(cand,rst,target - cand[i],i + 1);
            rst.pop_back();
        }
    }
};

// int main()
// {
//     vector<int> vec = {1,1,2,5,6,7,10};
//     int target = 8;
//     Solution s;
//     auto vv = s.combinationSum2(vec,target);
//     for(auto & v : vv)
//     {
//         for(auto &i : v)
//             cout << i << " ";
//         cout << endl;
//     }
// }
