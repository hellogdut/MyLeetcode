#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int minD = INT_MAX;
        int closest = 0;
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2;++i) {
            int a = num[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int b = num[j];
                int c = num[k];
                int d = abs(a + b + c - target);
                if (d < minD) {
                    closest = a + b + c;
                    minD = d;
                }
                if(d == 0)
                    return target;
                // discuss how to move pointer
                if (target > a + b + c) {
                    j++;
                    continue;
                }
                if(target < a + b + c) {
                    --k;
                    continue;
                }
            }
        }
    return closest;
    }
};
