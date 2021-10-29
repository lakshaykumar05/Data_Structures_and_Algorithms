class Solution {
public:
    bool ans = false;
    int check(TreeNode* root)
    {
        if(root)
        {
            int lheight = check(root->left);
            int rheight = check(root->right);
            if(lheight == rheight)
                ans = true;
            else
                ans = false;
            return 1+max(lheight , rheight);
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        int h = check(root);
        return ans;
    }
};