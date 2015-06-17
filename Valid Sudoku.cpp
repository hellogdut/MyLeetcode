class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(!ValidBig(board,false) || !ValidBig(board,true))
            return false;
        
        for(int i = 0;i < 9;i += 3)
        {
            for(int j = 0;j < 9;j += 3)
                if(!ValidSmall(board,i,j))
                    return false;
            
        }
        return true;
    }
    bool ValidBig(vector<vector<char>>& board,bool testRow)
    {
        for(int i = 0;i < 9;++i)
        {
            bool test[9] = {false};
            for(int j = 0;j < 9;++j)
            {
                char c = board[i][j];
                if(!testRow)
                    c = board[j][i];
                
                if('1' <= c && c <= '9')
                {
                    if(test[c - '0' - 1])
                        return false;
                    test[c - '0' - 1] = true;
                }
            }
        }
        return true;
    }
    bool ValidSmall(vector<vector<char>>& board,int i,int j)
    {
        bool test[9] = {false};
        int in = i + 3;
        int jn = j + 3;
        for(;i < in;i++)
        {
            for(j = jn - 3;j < jn;++j)
            {
                char c = board[i][j];
                if('1' <= c && c <= '9')
                {
                    if(test[c - '0' - 1])
                        return false;
                    test[c - '0' - 1] = true;
                }
            }
        }
        return true;
    }
};
