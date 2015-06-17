class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        return getNth(s,n - 1);
    }
    string getNth(string &s,int n)
    {
        if(n <= 0)
            return s;
        
        string rst;
        char c = s[0];
        int  count = 1;
        for(int i = 1;i < s.length();++i)
        {
            if(c != s[i])
            {
                rst += to_string(count);
                rst += c;
                c = s[i];
                count = 1;
            }
            else
            {
                count++;
                
            }
        }
        
        rst += to_string(count);
        rst += c;
        
        return getNth(rst, n - 1);
    }
};
