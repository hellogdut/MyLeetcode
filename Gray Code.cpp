class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> bits(n,0);
        vector<int> _map(n,0);
        vector<int> result;
        result.push_back(calBits(bits));
        // 从右到左，找第一个没被标记过的。
        // 如果没找到，结束
        // 如果改位为0，修改为1，否则修改为0，添加到结果中
        // 标志该位为访问，该位后面的所有位置都标志为未访问
        
        while(1)
        {
            int j = n - 1;
            while(j >= 0 && _map[j])
                j--;
            if(j < 0)
                break;
            _map[j] = 1;
            bits[j] = !bits[j];
            result.push_back(calBits(bits));
            while(++j <= n - 1)
                _map[j] = 0;
        }
        return result;


        
    }
    int calBits(vector<int>& bits)
    {
        // int n = bits.size();
        // int t = 1;
        // int sum = 0;
        // while(--n >= 0)
        // {
        //     sum += bits[n] * t;
        //     t *= 2;
        // }
        // return sum;
        int i = 0;
        int sum = 0;
        while(i < bits.size())
            sum = sum * 2 + bits[i++];
        return sum;
    }
};
