class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // 直接在原三角形上操作
        // 将每个位置的值改写为 从该位置到底部的最小和
        // 从底部递推上来。然后在第一行寻找最小值
        int MIN = INT_MAX;
        for(int i = triangle.size() - 1;i >= 0;--i)
        {
            for(int j = 0;j < triangle[i].size();++j)
                // 计算每个位置到底部的最小和
                helper(triangle,i,j);
        }
        
        for(int i = 0;i < triangle[0].size();++i)
            MIN = min(MIN,triangle[0][i]);
        return MIN;

    }
    void helper(vector<vector<int>>& triangle,int row,int i)
    {

        int left = 0;
        int right = 0;
        if(row + 1 < triangle.size() && i < triangle[row + 1].size())
            left = triangle[row + 1][i];
        if(row + 1 < triangle.size() && i + 1 < triangle[row + 1].size())
            right = triangle[row + 1][i + 1];

        triangle[row][i] = min(left,right) +  triangle[row][i];
        
    }
};
