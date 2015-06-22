class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        
        m--;
        n--;
        
        while(index >= 0)
        {
            int t = 0;
            if(m >= 0 && n >= 0)
                t = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            else if(m >= 0)
                t = nums1[m--];
            else
                t = nums2[n--];
            nums1[index--] = t;
        }
        
    }
};
