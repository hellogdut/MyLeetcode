class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return 1;
        int low = 1;
        int high = x / 2;
        
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            
            if((long long)mid * mid >= INT_MAX)
            {
                high = mid - 1;
                continue;
            }
            int y = mid * mid;
            if(y > x)
                high = mid - 1;
            if(y == x)
                return mid;
            else if(y < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low - 1;
    }
};

