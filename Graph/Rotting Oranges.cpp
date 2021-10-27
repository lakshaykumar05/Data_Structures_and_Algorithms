class Solution {
public:
    void fun(vector<vector<int>>&grid , int r , int c , int time)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0 || 1 < grid[r][c] && grid[r][c]<time)
            return;
        grid[r][c] = time;
        fun(grid , r +1 , c , grid[r][c] +1 );
        fun(grid , r -1 , c , grid[r][c] +1);
        fun(grid , r  , c+1 , grid[r][c] +1);
        fun(grid , r  , c-1 , grid[r][c] +1);
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i <  m ; i++)
        {
            for(int j = 0; j<n ; j++)
            {
                if(grid[i][j] == 2)
                {
                    fun(grid , i , j , grid[i][j] );
                }
            }
        }
        int res = 2;
        for(auto i : grid)
        {
            for(auto j : i )
            {
                cout<<j<<" ";
                if(j == 1)return -1;
                else
                {
                    res= max(j , res);
                }
            }
            cout<<"\n";
        }
        return res -2;
    }
};