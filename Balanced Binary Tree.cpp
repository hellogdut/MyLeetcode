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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int left = deepOfNode(root -> left);
        int right = deepOfNode(root -> right);
        if(abs(left - right) > 1)
            return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
        
    }
    int deepOfNode(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return max(deepOfNode(root -> left),deepOfNode(root -> right)) + 1;
    }
};
