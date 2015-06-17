class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        long size = strs.size();
        if(size == 0)
            return string();
        if(size == 1)
            return strs[0];
        
        char c = strs[0][0];
        for(long i = 0;i < size;++i)
        {
            if(strs[i][0] != c)
                return string();
        }
        
        sort(strs.begin(),strs.end(),[](const string& a,const string& b){
            return a.length() < b.length();
        });
        long n = strs[0].length();
        while(n > 0)
        {
            long k = n;
            for(long i = 1;i < size;++i)
            {
                if(strs[i][n-1] != strs[0][n-1])
                {
                    --n;
                    break;
                }
            }
            if(k == n)
                break;
        }
        return string(strs[0].begin(),strs[0].begin() + n);
    }
};

