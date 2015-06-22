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
    vector<int> inorderTraversal(TreeNode* root) {

        unordered_set<TreeNode*> _set;
        vector<TreeNode*> _stack;
        vector<int> result;
        _stack.push_back(root);


        while(!_stack.empty())
        {
            TreeNode* node = _stack.back();
            _stack.pop_back();
            if(!node)
                continue;
            if(_set.find(node)!= _set.end())
            {
                result.push_back(node -> val);
                continue;
            }
            _set.insert(node);
            _stack.push_back(node -> right);
            _stack.push_back(node);
            _stack.push_back(node -> left);
            
        }

        return result;

        
    }
};
