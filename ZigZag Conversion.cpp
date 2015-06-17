class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;
        
        const int max = (numRows - 1) * 2;
        string str;
        
        for(int i = 0;i < numRows;++i)
        {
            int gap = (max - i * 2) == 0 ? max : (max - i * 2);
            int j = i;
            while(j < s.size())
            {
                str.push_back(s[j]);
                j += gap;
                gap = (gap == max) ? max : max - gap;
            }
        }
        return str;
        
    }
};
