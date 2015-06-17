class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        if(m == 1 && n == 1)
            return obstacleGrid[0][0] == 0;
        // 无视前面两种奇葩情况
        return uniquePaths(obstacleGrid,m,n);
        
    }
public:
    int uniquePaths(vector<vector<int>>& obstacleGrid,int m, int n) {
        vector<vector<int>> _map;
        for(int i = 0;i < m;++i)
        {
            vector<int> v(n,0);
            _map.push_back(v);
        }
        // 初始化右下角为 1
        _map[m - 1][n - 1] = 1;
        // 从最后一行最后一个元素开始，向左计算
        
        for(int i = m - 1;i >= 0;--i)
            calculateLeft(obstacleGrid,_map,n - 1,i,m,n);
        // [0][0] 即为结果
        return  _map[0][0];
        
    }
private:
    
    void calculateLeft(vector<vector<int>>& obstacleGrid,vector<vector<int>>& _map,int x,int y,int m,int n)
    {
        if(x < 0)
            return;
        // 先加上右边
        if(x + 1 <= n - 1 && obstacleGrid[y][x + 1] != 1)
            _map[y][x] += _map[y][x + 1];
        // 再加上下面
        if(y + 1 <= m - 1 && obstacleGrid[y + 1][x] != 1)
            _map[y][x] += _map[y + 1][x];
        
        calculateLeft(obstacleGrid,_map,x - 1,y,m,n);
    }
};

