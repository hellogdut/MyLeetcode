class Solution {
public:
    int numDecodings(string s) {
        
        // 动态规划
        // 如果序列为 [1, 2,3,4]
        // 对于4,只能取一个，1
        // 对于3,只能取一个，总数即4的总数,1
        // 对于2,取一个时,总数即3的总数,1.取两个时,总数即4的总数,1.总共为 1 + 1 = 3
        // 对于1,取一个时,总数即2的总数,2.取两个时,总数即3的总数,1.总共为  2 + 1 = 3；
        if(s.size() < 1)
            return 0;
        if(s.size() == 1)
            return s[0] != '0';
        int c = 1;
        int b = s[s.size() - 1] == '0' ? 0 : 1;
        int i = s.size() - 2;
        int a = 1;
        while(i >= 0)
        {
            char c1 = s[i];
            char c2 = s[i + 1];
            if(c1 == '0' && (c2 == '0' ||((i - 1 >= 0 && !( '1' <= s[i - 1] && s[i - 1] <= '2')) || (i - 1) < 0)))
                return 0;
            
            if(c1 == '0')
            {
                a = 0;
            }
            
            if ('1' <= c1 && c1 <= '2')
            {
                if(c1 < '2' || (c1 == '2' && '1' <= c2 && c2 <= '6'))
                {
                    a = b + c;
                }
                else if('0' == c2)
                {
                    a = c;
                    
                }
                else
                    a = b;
            }
            // c1 >= 3
            if(c1 >= '3')
            {
                a = b;
            }
            c = b;
            b = a;
            i--;
        }
        
        return a;
    }
};
