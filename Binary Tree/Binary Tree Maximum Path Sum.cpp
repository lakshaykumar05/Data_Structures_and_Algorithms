class Solution {
public:
    int res;
    int fun(TreeNode * t , int &res)
    {
        //base
        if(!t)
            return 0;
        int l_sum = max( 0 , fun(t->left , res) );
        //want a min of 0 from the left or right coz if the root was negative then 
        //adding negative to it would decrease the max path sum
        //so in order to consider the max path having the current root and its child there can be 3 cases
            // 1.root is negative and children are positive so min sum will be 0
            // 2.root is positive and children are negative so max sum would be the root only
            // 3.root is positive and one child is negative then return 0 from the negative side and add the positive val of root and the positive child.
        int r_sum = max( 0 , fun(t->right , res));
        res = max(res , l_sum + r_sum + t->val);
        return t->val + max(l_sum , r_sum);
    }
        
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        res = root->val;
        fun(root , res);
        return res;
    }
};
