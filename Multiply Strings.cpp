class Solution {
public:
    string multiply(string num1, string num2) {
        
        // 将最长的串置为num1
        if(num1.size() < num2.size())
            num1.swap(num2);
        
        vector<string> tmp;
        vector<int> len;
        string result;
        
        int maxLen = 0;
        int n = 0;
        
        for(int i = num2.size() - 1;i >= 0;--i)
        {
            string s;
            int k = 0;
            for(int j = num1.size() - 1; j >= 0;--j)
            {
                int a = num2[i] - '0';
                int b = num1[j] - '0';
                int sum = a * b + k;
                k = sum / 10;
                s.insert(0,to_string(sum % 10));
            }
            if(k)
                s.insert(0,to_string(k));
            for(int t = 0;t < n;++t)
                s.push_back('0');
            
            // 顺便计算下长度
            tmp.push_back(s);
            len.push_back(s.size());
            n++;
        }
        // 计算最大长度
        for_each(len.begin(),len.end(),[&maxLen](const int& a){
            maxLen = a > maxLen ? a : maxLen;
        });

        
        int sum = 0;
        int k = 0;
        
        for(int i = 1;i <= maxLen;++i)
        {
            sum = 0;
            for(int j = 0;j < tmp.size();++j)
            {
                int index = len[j] - i;
                if(index < 0)
                    continue;
                sum += (tmp[j][index] - '0');
            }
            sum += k;
            k = sum / 10;
            result.insert(0,to_string(sum % 10));
        }
        if(k)
            result.insert(0,to_string(k));
        
        int i = 0;
        for(;i < result.size() - 1;++i)
        {
            if(result[i] != '0')
                break;
        }
        result.erase(result.begin(),result.begin() + i);
        return result;
        
    }
};
