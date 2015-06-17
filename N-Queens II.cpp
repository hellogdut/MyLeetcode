class Solution {
private:
    vector<vector<string>> result;

public:
    int totalNQueens(int n)
    {
        auto v = solveNQueens(n);
        return v.size();
    }

private:
    vector<vector<string> > solveNQueens(int n) 
    {
        
        vector<pair<int,int>> queen;
        _solveNQueens(queen,1,n);
        return result;
    }
    void _solveNQueens(vector<pair<int,int>>& queen,int line,int N)
    {
        if(line > N)
        {
            vector<string> solution;
            for(int i = 0;i < N;++i)
            {
                string s;
                for(int j = 0;j < N;++j)
                    s.push_back('.');
                
                solution.push_back(s);
                
            }
            for(int i = 0;i < queen.size();++i)
            {
                int x = queen[i].first;
                int y = queen[i].second;
                solution[y-1][x-1] = 'Q';
            }
            
            result.push_back(solution);
            return;
        }
        
        // 计算行 Line 可选的位置
        vector<bool> avl;
        for(int i = 0;i < N;++i)
            avl.push_back(true);
        
        for(int i = 0;i < queen.size();++i)
        {
            auto p = queen[i];
            int x = p.first;
            int y = p.second;
            avl[x - 1] = false;
            
            
            // 计算高度
            int d = line - y;
            
            // 左右两个可能的斜线位置
            // 等腰
            int x1 = x - d;
            int x2 = x + d;
            if(0 < x1 && x1 <= N)
                avl[x1 - 1] = false;
            if(0 < x2 && x2 <= N)
                avl[x2 - 1] = false;
        }
        
        // 尝试每一个位置，递归下去
        
        for(int i = 0;i < N;++i)
        {
            if(avl[i] == true)
            {
                queen.push_back(make_pair(i + 1,line));
                _solveNQueens(queen,line + 1,N);
                queen.pop_back();
            }
        }
        
        
    }
};
