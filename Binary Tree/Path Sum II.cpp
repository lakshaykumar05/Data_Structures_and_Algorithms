class Solution {
public:
    vector<vector<int>>res;
    void helper(TreeNode *t , int target , int sum, vector<int>temp)
    {
        if(t)        
        {
            sum+=t->val;
            if(!t->left && !t->right)
            {
                if(sum==target)
                {
                    temp.push_back(t->val);
                    //leaf node
                    res.push_back(temp);
                    temp.pop_back();
                }
                return;
                
            }
            temp.push_back(t->val);
            helper(t->left,target,sum,temp);
            helper(t->right,target,sum,temp);
            temp.pop_back();
        }
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root)
        {
            helper(root, targetSum , 0 , {});
            return res;
        }
        else
            return {};
    }
};