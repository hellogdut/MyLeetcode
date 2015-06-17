class Solution {
public:
    int climbStairs(int n) {

        int b = 1;
        int a = 1;

        n = n - 2;
        while(n >= 0)
        {
            int c = b + a;
            a = b;
            b = c;
            n--;
        }

        return b;
    }
};
