class Solution {
public:

bool verify(TreeNode* root,int low,int high,bool llimit,bool hlimit)
{
    if(root==NULL) return true;
    if((hlimit && root->val>=high) ||(llimit && root->val<=low)) return false;
    return verify(root->left,low,root->val,llimit,true) && verify(root->right,root->val,high,true,hlimit);
}
bool isValidBST(TreeNode* root) {
    return verify(root,INT_MIN,INT_MAX,false,false);
}
};

