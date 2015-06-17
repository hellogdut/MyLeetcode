class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        _rotate(matrix,0,0,matrix.size());
        
    }
    void _rotate(vector<vector<int>>& matrix,int ox,int oy,int N)
    {
        if(N < 2)
            return;
        
        for(int i = 0;i < N - 1;++i)
        {
            _moveHelper(matrix,make_pair(ox,oy + i),make_pair(ox,oy + i),matrix[ox][oy + i]);
        }
        
        // 对内矩阵进行递归
        int oox = (ox + 1);
        int ooy = (oy + 1);
        int size = N - 2;
        _rotate(matrix,oox,ooy,size);
        
    }
    void _moveHelper(vector<vector<int>>& matrix,const pair<int,int>& source,const pair<int,int>& curr,int val)
    {
        auto target = rShift(matrix,curr);
        int save = matrix[target.first][target.second];
        matrix[target.first][target.second] = val;
        
        if(target != source)
        {
            _moveHelper(matrix,source,target,save);
        }
        
    }
    
    pair<int,int> rShift(vector<vector<int>>& matrix,const pair<int,int>& curr)
    {
        // [x][y] -> [y][N - 1 - x]
        int N = matrix.size();
        int x = curr.first;
        int y = curr.second;
        return make_pair(y,N - 1 - x);
    }
    
};

// int main()
// {
// //    ----------> y
// //    | 1  2  3  4
// //    | 5  6  7  8
// //    | 9  10 11 12
// //    | 13 14 15 16
// //    x
    
//     Solution s;
//     vector<vector<int>> v = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    
//     s.rotate(v);
    
//     for(auto& i: v)
//     {
//         for(auto& j : i)
//             cout << j << " ";
//         cout << endl;
//     }
    
// }
