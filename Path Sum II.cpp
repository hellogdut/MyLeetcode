class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> s;
        _pathSum(root,0,sum,s,ret);
        return ret;
    }
    void _pathSum(TreeNode* root,int curr,int sum,vector<int>& s,vector<vector<int>>& ret)
    {
        if(root == NULL)
            return;
        
        curr += root -> val;
        s.push_back(root -> val);
        
        if(!(root -> left) && !(root -> right) && curr == sum)
                ret.push_back(s);
        
        _pathSum(root -> left,curr,sum,s,ret);
        _pathSum(root -> right,curr,sum,s,ret);
        
        s.pop_back();
    }
};
