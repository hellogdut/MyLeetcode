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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return _minDepth(root);        
    }
    int _minDepth(TreeNode* root)
    {
        if(!(root -> left) && !(root -> right))
            return 1;
            
        int left = root -> left ? _minDepth(root -> left) : INT_MAX;
        int right = root -> right ? _minDepth(root -> right) : INT_MAX;
        return min(left,right) + 1;
    }
};
