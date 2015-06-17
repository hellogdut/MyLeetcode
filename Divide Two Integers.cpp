#define MAX_INT (-((0x01 << 31) + 1))
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool negative = (dividend >> 31 ^ divisor >> 31);
        
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        
        long long result = 0;
        
        while(a >= b)
        {
            int c = 0;
            while(a >= (b << (c + 1)))    c++;
            a -= (b << c);
            result += abs((long long)(1 << c));
        }
        if((result > MAX_INT && !negative) || ((result > (long long)MAX_INT + 1) && negative))
        {
            return MAX_INT;
        }
        
        return negative ? - result : result;
    }
};
