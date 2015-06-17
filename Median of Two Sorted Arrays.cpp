class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        int* c = new int[m + n];
        while(i < m  && j < n )
        {
            if(A[i] < B[j])
            {
                *(c + k) = A[i];
                ++i;
            }
            else
            {
                *(c + k) = B[j];
                ++j;
            }
            ++k;
        }
        int* p = A;
        int  t = 0;
        int  y = 0;
        if(i < m )
        {
            p = A;
            t = i;
            y = m;
        }
        else
        {
            p = B;
            t = j;
            y = n;
        }
        while(t < y)
        {
            *(c + k) = *(p + t);
            ++k;
            ++t;
        }
        //奇数
        if((m + n ) & 1)
          return (double)c[(m + n)/2];
        else
        {
            return (double)(c[(m+n-1)/2] + c[(m + n)/2])/2;
        }
        
    }
};
