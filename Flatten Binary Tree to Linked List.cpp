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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        deque<TreeNode*> q;
        preorder(q,root);
        q.pop_front();

        TreeNode* curr = root;
        
        while(!q.empty())
        {
            curr -> right = q.front();
            q.pop_front();
            curr = curr -> right;
        }
    }
    void preorder(deque<TreeNode*>& q,TreeNode* root)
    {
        if(root == NULL)
            return;
        q.push_back(root);
        preorder(q,root -> left);
        preorder(q,root -> right);
        root -> left = root -> right = NULL;
    }
};
