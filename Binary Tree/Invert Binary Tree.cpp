class Solution {
public:
    void invert(TreeNode*t)
    {
        if(t)
        {
            TreeNode* curr = t->left;
            t->left = t->right;
            t->right = curr;
            
            invert(t->left);
            invert(t->right);
        }
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};