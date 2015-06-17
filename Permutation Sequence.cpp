class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> cand;
        string s;
        
        for(int i = 0;i < n;++i)
            cand.push_back(i + 1);
        
        k -= 1;
        
        while(cand.size() > 2)
        {
            int n = cand.size() - 1;
            int m = factorial(n);
            int j = k / m;
            k = k % m;
            s.push_back(cand[j] + '0');
            cand.erase(cand.begin() + j);
        }
        // 最终 k 肯定等于 1 或 0
        // 0 的时候顺序
        // 1 的时候逆序
        if(k == 1)
            reverse(cand.begin(), cand.end());
        
        for(int i = 0;i < cand.size();++i)
            s.push_back(cand[i] + '0');
        
        return s;
        
        
        
    }
private:
    int factorial(int m)
    {
        for(int i = m - 1;i > 1;--i)
            m *= i;
        return m;
    }
};

