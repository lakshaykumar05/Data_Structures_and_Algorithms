class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*>q;
        bool flag = true;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            for(int i = 0 ; i < n ; i++)
            {
                TreeNode* front_node = q.front();
                temp.push_back(front_node->val);
                q.pop();
                if(front_node->left)
                    q.push(front_node->left);
                if(front_node->right)
                    q.push(front_node->right);
                
            }   
            if(flag)
                res.push_back(temp);
            else
            {
                reverse(temp.begin() , temp.end());
                res.push_back(temp);
            }
            flag=!flag;
            
        }
        return res;
    }
};