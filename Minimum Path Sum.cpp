class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        for(int i = m - 1;i >= 0;--i)
        {
            calculateLeftMin(grid,n - 1,i,m,n);
        }
        
        return grid[0][0];
    }
private:
    void calculateLeftMin(vector<vector<int>>& grid,int x,int y,int m,int n)
    {
        if(x < 0)
            return;
        
        // 右下都有
        if(x + 1 <= n - 1 && y + 1 <= m - 1)
        {
            grid[y][x] = min(grid[y][x] + grid[y][x + 1],grid[y][x] + grid[y + 1][x]);
        }
        else if(x + 1 <= n - 1)
        {
            // 有右
            grid[y][x] += grid[y][x + 1];
        }
        else if(y + 1 <= m - 1)
        {
            // 有下
            grid[y][x] += grid[y + 1][x];
        }
        return calculateLeftMin(grid,x-1,y,m,n);
    }
};
