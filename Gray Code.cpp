class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> bits(n,0);
        vector<int> _map(n,0);
        vector<int> result;
        result.push_back(calBits(bits));
        // ´ÓÓÒµ½×ó£¬ÕÒµÚÒ»¸öÃ»±»±ê¼Ç¹ýµÄ¡£
        // Èç¹ûÃ»ÕÒµ½£¬½áÊø
        // Èç¹û¸ÄÎ»Îª0£¬ÐÞ¸ÄÎª1£¬·ñÔòÐÞ¸ÄÎª0£¬Ìí¼Óµ½½á¹ûÖÐ
        // ±êÖ¾¸ÃÎ»Îª·ÃÎÊ£¬¸ÃÎ»ºóÃæµÄËùÓÐÎ»ÖÃ¶¼±êÖ¾ÎªÎ´·ÃÎÊ
        
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
