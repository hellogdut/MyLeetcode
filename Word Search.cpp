class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if(!board.size() || !board[0].size() || !word.size())
            return false;
        
        int m = board.size();
        int n = board[0].size();
        if(word.size() > m * n)
            return false;
        
        
        
        for(int y = 0;y < m;++y)
        {
            for(int x = 0;x < n;++x)
            {
                if(board[y][x] != word[0])
                    continue;
                vector<vector<bool>> _set(m,vector<bool>(n,false));
                if(_exist(_set,make_pair(x,y),0,word,board,m,n))
                    return true;
            }
        }
        return false;
        
    }
private:
    bool _exist(vector<vector<bool>>& _set,pair<int,int> curr,int i,string& word,vector<vector<char>>& board,int m,int n)
    {
        if(i == word.size())
            return true;
        
        int x = curr.first;
        int y = curr.second;
        if(x < 0 || x >= n || y < 0 || y >= m || _set[y][x] || board[y][x] != word[i])
            return false;
        
        _set[y][x] = true;
        if(_exist(_set,make_pair(x-1,y),i+1,word,board,m,n))  return true;
        if(_exist(_set,make_pair(x+1,y),i+1,word,board,m,n))  return true;
        if(_exist(_set,make_pair(x,y - 1),i+1,word,board,m,n))  return true;
        if(_exist(_set,make_pair(x,y + 1),i+1,word,board,m,n))  return true;
        
        _set[y][x] = false;
        return false;
    }
};
