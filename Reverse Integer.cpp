class Solution {
public:
    int reverse(int x) {
       int minus = x < 0 ? -1 : 1;
       // if x is negative
       x = x * minus;
       int result = 0;
       while(x)
       {
          result = result * 10 + x % 10;
          x /= 10;
       }
       return result * minus;
        
    }
};
