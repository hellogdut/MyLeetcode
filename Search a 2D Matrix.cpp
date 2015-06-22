class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m * n;
        int low = 0;
        int high = size - 1;

        // 当成一个连续的vector,然后二分查找
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            int y = mid / n;
            int x = mid % n;
            if(matrix[y][x] == target)
                return true;
            else if(matrix[y][x] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
