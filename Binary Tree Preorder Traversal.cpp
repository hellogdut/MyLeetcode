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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        vector<TreeNode*> _stack;
        _stack.push_back(root);
        while(!_stack.empty())
        {
           TreeNode* p = _stack.back();
           _stack.pop_back();
           if(!p)
              continue;
           result.push_back(p -> val);
           _stack.push_back(p -> right);
           _stack.push_back(p -> left);
        }

        return result;
    }
};
