/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> result;
        vector<TreeNode*> _stack;
        unordered_set<TreeNode*> _set;
        _stack.push_back(root);

        while(!_stack.empty())
        {
            TreeNode* p = _stack.back();
            _stack.pop_back();
            if(!p)
                continue;
            if(_set.count(p) == 0)
            {
                _stack.push_back(p);
                _stack.push_back(p -> right);
                _stack.push_back(p -> left);
                _set.insert(p);
            }
            else
                result.push_back(p -> val);
        }
        return result;    
    }


};
