/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        root -> next = NULL;
        connectToRight(root);
    }
    void connectToRight(TreeLinkNode* curr)
    {
        if(curr == NULL)
            return;
        if(curr -> left)
            curr -> left -> next = curr -> right;

        if(curr -> right && curr -> next)
            curr -> right -> next = curr -> next -> left;
        else if (curr -> right)
            curr -> right -> next = NULL;
        connectToRight(curr -> left);
        connectToRight(curr -> right);


    }
};
