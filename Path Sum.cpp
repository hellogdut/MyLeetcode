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
    bool hasPathSum(TreeNode* root, int sum) {

        return currSum(root,0,sum);

    }
    bool currSum(TreeNode* root, int curr,int sum) {
        
        if(root == NULL)
            return false;
        curr += root -> val;
        if(curr == sum && !(root -> left) && !(root -> right))
            return true;
        return currSum(root -> left,curr,sum) || currSum(root -> right,curr,sum);
    }
};
