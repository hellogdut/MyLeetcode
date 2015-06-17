class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = INT_MIN;
        
        // b 保留当前连续子串和的最大值
        // a 保留当前子串的和
        int b = nums.back();
        int a = b;
        
        for(int i = nums.size() - 2;i >= 0;i--)
        {
            a += nums[i];
            b = max(a,b);
            m = max(b,m);
            if(a < nums[i])
            {
                a = b = nums[i];
            }
            
        }
        
        return max(m,b);
    }
};
