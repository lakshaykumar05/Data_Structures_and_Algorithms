class Solution {
public:
    void fun(vector<vector<char>>&grid , int i , int j )
    {
        if(i < 0 || i >=grid.size() || j < 0 || j >=grid[0].size() || grid[i][j] == '0' || grid[i][j] == 's')
            return ;
        grid[i][j] = 's';
        fun(grid , i+1 , j);
        fun(grid , i -1 , j);
        fun(grid , i , j+1);
        fun(grid , i , j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m ==0)
            return 0;
        int n = grid[0].size() , res = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0; j < n ; j ++)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    fun(grid , i , j);
                }
            }
        }
        return res;
    }
};