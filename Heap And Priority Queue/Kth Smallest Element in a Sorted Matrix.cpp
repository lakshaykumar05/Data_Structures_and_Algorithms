class Solution {
public:
    //sorting approach
    //Time Complexity : O(n2)
    //Space Complexity : O(n2)
    int sorting(vector<vector<int>>matrix , int k)
    {
        vector<int>res ;
        for(auto i : matrix)
        {
            for(auto j : i)
                res.push_back(j);
        }
        sort(res.begin() , res.end());
        return res[k-1];
    }
    //Time complexity : O(1)
    //Space complexity : O(1)
    int fun(vector<vector<int>>matrix , int k)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int req_r = ceil(k/c) -1;
        int req_c = k%c - 1;
        return matrix[req_r][req_c];
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return sorting(matrix , k);
    }
};