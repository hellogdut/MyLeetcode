class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

       int m = matrix.size();
       int n = matrix[0].size();
       vector<pair<int,int>> v;
       for(int y = 0;y < m;++y)
       {
          for(int x = 0;x < n;++x)
             if(matrix[y][x] == 0)
                v.push_back(make_pair(x,y));
       }

       while(v.size() > 0)
       {
          int x = v[v.size() - 1].first;
          int y = v[v.size() - 1].second;
          v.pop_back();
          for(int i = 0;i < n;++i)
             matrix[y][i] = 0;

          for(int i = 0;i < m;++i)
             matrix[i][x] = 0;
       }        
    }
};
