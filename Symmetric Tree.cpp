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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return _isSymmetric(root -> left,root -> right);
        
    }
    bool _isSymmetric(TreeNode* lc,TreeNode* rc)
    {
        if(!lc && !rc)
            return true;
        if((!lc || !rc) && lc != rc)
            return false;
        return lc -> val == rc -> val && _isSymmetric(lc -> left,rc -> right) && _isSymmetric(lc -> right,rc -> left);
    }
};
