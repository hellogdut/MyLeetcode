class Solution {
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        if(m == 0 || n == 0)
            return result;
        
        vector<vector<int>> _map(matrix);
        for(int i = 0;i < m;++i)
            for(int j = 0;j < n;++j)
                _map[i][j] = 0;
        
        int x = 0;
        int y = 0;
        while(result.size() < m * n)
        {
            if(!_map[y][x])
            {
                result.push_back(matrix[y][x]);
                _map[y][x] = 1;
            }
            
            
            // can right
            while(x < n - 1 && !_map[y][x + 1])
            {
                x++;
                result.push_back(matrix[y][x]);
                _map[y][x] = 1;
                
            }
            // can down
            while(y < m - 1 && !_map[y + 1][x])
            {
                y++;
                result.push_back(matrix[y][x]);
                _map[y][x] = 1;
                
            }
            // can left
            while(x > 0 && !_map[y][x - 1])
            {
                x--;
                result.push_back(matrix[y][x]);
                _map[y][x] = 1;
            }
            // can up
            while(y > 0 && !_map[y - 1][x])
            {
                y--;
                result.push_back(matrix[y][x]);
                _map[y][x] = 1;
            }
            
        }
        return result;
    }
};
