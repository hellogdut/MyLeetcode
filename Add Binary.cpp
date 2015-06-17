class Solution {
public:
    string addBinary(string a, string b) {
        // 交换长的到a
        if(b.size() > a.size())
            a.swap(b);
        int n1 = a.size();
        int n2 = b.size();
        int i = b.size() - 1;
        int k = 0;
        int n = 0;
        while(n1 - n2 + i >= 0)
        {
            int op1 = a[n1 - n2 + i] - '0' + k;
            int op2 = n < n2 ? b[i] - '0' : 0;
            
            int sum = op1 + op2;
            k = sum > 1 ? 1 : 0;
            sum %= 2;
            a[n1 - n2 + i] = sum + '0';
            i--;
            n++;
        }
        return k == 0 ? a : "1" + a;
    }
};
