class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

       invert(root);
       return root;

    }
    void invert(TreeNode* node)
    {
       if(node == NULL)
          return;
       TreeNode* left = node -> left;
       TreeNode* right = node -> right;
       node -> left = right;
       node -> right = left;
       invert(left);
       invert(right);


    }
};
