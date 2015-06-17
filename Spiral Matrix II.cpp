class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> _map;
        
        int m = n;
        if(m == 0 || n == 0)
            return _map;
        for(int i = 0;i < n;++i)
        {
            vector<int> v;
            for(int j = 0;j < n;++j)
                v.push_back(0);
            _map.push_back(v);
        }
        int x = 0;
        int y = 0;
        int curr = 1;
        
        while(curr <= n * n)
        {
            if(!_map[y][x])
            {
                _map[y][x] = curr++;
            }
            
            
            // can right
            while(x < n - 1 && !_map[y][x + 1])
            {
                x++;
                _map[y][x] = curr++;
                
            }
            // can down
            while(y < m - 1 && !_map[y + 1][x])
            {
                y++;
                _map[y][x] = curr++;
                
            }
            // can left
            while(x > 0 && !_map[y][x - 1])
            {
                x--;
                _map[y][x] = curr++;
            }
            // can up
            while(y > 0 && !_map[y - 1][x])
            {
                y--;
                _map[y][x] = curr++;
            }
            
        }
        return _map;
    }
};
