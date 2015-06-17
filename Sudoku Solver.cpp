class Solution {
public:
    vector<pair<int,int>> blanks;
    
    void solveSudoku(vector<vector<char>>& board) {
        blanks = blankList(board);
        
        isSolved(board,0);
    }
    bool isSolved(vector<vector<char>>& board,int curr)
    {
        // 说明前面都匹配完,解决
        if(curr >= blanks.size())
            return true;
        
        auto x = blanks[curr].first;
        auto y = blanks[curr].second;
        
        // 获得当前点所有可选数字
        auto avl = avlList(board,curr);
        for(int i = 0;i < avl.size();++i)
        {
            board[y][x] = avl[i] + '0';
            
            if(isSolved(board,curr + 1))
                return true;
        }
        board[y][x] = '.';
        return false;
    }
    
    vector<int> avlList(const vector<vector<char>>& board,int curr)
    {
//        cout << endl << "-------- avlList -----" << endl;
//        print(board);
        
        auto p = blanks[curr];
        int x = p.first;
        int y = p.second;
        vector<int> list;
        
        bool avl[9];
        for(int i = 0 ;i < 9;++i)
            avl[i] = true;
        
        // 检测 横行
        for(int i = 0;i < 9;++i)
        {
            char c = board[y][i];
            if(c != '.')
                avl[c - '0' - 1] = false;
        }
        // 检测 竖行
        for(int j = 0;j < 9;++j)
        {
            char c = board[j][x];
            if(c != '.')
                avl[c - '0' - 1] = false;
        }
        // 检测小9宫格
        int ox = (x / 3) * 3;
        int oy = (y / 3) * 3;
        
        for(int i = ox;i < ox + 3;++i)
        {
            for(int j = oy;j < oy + 3;++j)
            {
                char c = board[j][i];
                if(c != '.')
                    avl[c - '0' - 1] = false;
            }
        }
        // 返回列表
        for(int i = 0;i < 9;++i)
            if(avl[i])
                list.push_back(i + 1);
        
        return list;
        
    }
//    void print(const vector<vector<char>>& board)
//    {
//        for(int i = 0;i < 9;++i)
//        {
//            if(i && (i % 3) == 0)
//                cout << endl;
//            for(int j = 0;j < 9; ++ j)
//            {
//                if(j && (j % 3) == 0)
//                    cout << " ";
//                cout << board[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    vector<pair<int,int>> blankList(const vector<vector<char>>& board)
    {
        vector<pair<int,int>> vec;
        for(int i = 0;i < 9;++i)
        {
            for(int j = 0;j < 9;++j)
            {
                if(board[i][j] == '.')
                    vec.push_back(make_pair(j,i));
                
            }
        }
        return vec;
    }
};
