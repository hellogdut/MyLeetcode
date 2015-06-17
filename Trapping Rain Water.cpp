class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 0)
            return 0;
        vector<pair<int,int>> pool;

        // 找出所有的水池，保证
        // height[i] <= height[j]
        // 之后计算容量
        findPools(height,pool,0);
        
        int sum = 0;
        
        for(auto& p : pool)
        {
            int i = p.first;
            int j = p.second;
            int total = (j - i - 1) * height[i];
            for(int k = i + 1;k < j;++k)
                total -= height[k];
            
            sum += total;
            
        }
        return sum;
        
    }
    void findPools(vector<int>& height,vector<pair<int,int>>& pool,int start)
    {
        // 至少3个位置才能产生一个水池
        if(start  > height.size() - 2)
            return;
        
        // 跳过所有0
        while(start < height.size() && height[start] == 0)
            start++;
        
        int i = start + 1;
        
        // 找到不矮于左边的墙
        for(;i < height.size() && height[i] < height[start];++i)
            ;
        
        if(i < height.size())
        {   
            // >= 3个位置，这是一个水池
            if(i - start > 1)
            {
                pool.push_back(make_pair(start,i));
            }
            // 相邻
            return findPools(height,pool,i);
        }
        
        // 找不到至少跟左边相同高度的，所以左边砍一刀，重新找
        // 因为已经保证有3个位置了，肯定能找到
        if(height[start] > 0)
        {
            height[start] -= 1;
            return findPools(height,pool,start);
        }
        
    }
};
