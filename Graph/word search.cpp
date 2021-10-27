class Solution {
public:
    bool fun(vector<vector<char>>&m , int pos , int r , int c , string s)
    {
        //base case
        if(pos == s.size()) 
            return true;
        if(r<0||c<0||r>=m.size()||c>=m[0].size()||m[r][c]=='@'||m[r][c]!=s[pos])
            return false;

        char lost = m[r][c];
        m[r][c] = '@';//so that no retracing while in the recursion tree.
        bool res = fun(m , pos +1 , r+1 , c , s) ||
        fun(m , pos +1 , r-1 , c , s)||
        fun(m , pos +1 , r , c+1 , s)||
        fun(m , pos +1 , r , c-1 , s);
        m[r][c] = lost;//backtrack
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        //dfs sol
        for ( int i = 0; i < board.size(); i++) 
        for ( int j = 0; j < board[0].size(); j++) 
            if (fun(board,0,i,j, word ))
                return true;
        return false;
        
    }
};