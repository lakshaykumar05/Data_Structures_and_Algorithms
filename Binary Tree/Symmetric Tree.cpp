class Solution {
public:
    bool fun(TreeNode* l , TreeNode*r)  
    {
        if(!r && !l)
            return true;
        if(!l && r)
            return false;
        if(!r && l)
            return false;
        bool curr = (r->val == l->val)?true:false;
        return curr && fun(l->left , r->right) && fun(l->right , r->left);            
    }
    bool isSymmetric(TreeNode* root) {
        return fun(root->left , root->right);        
    }
};