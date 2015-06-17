#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   vector<vector<int> > fourSum(vector<int> &num, int target) {
      vector<vector<int> > vec;
      sort(num.begin(), num.end());
      int n = num.size();
      for (int i = 0; i < n - 3; ++i) {
         int a = num[i];
         for (int j = i + 1; j < n - 2; ++j) {
            int b = num[j];
            int dif = target - a - b;

            vector<int> v = twosum(num, j + 1, n, dif);  // [i + 1,n - 1);

            int size = v.size();
            if (size != 0) {
               // 找到至少一个组合
               for (int k = 0; k < size; k += 2) {
                  vector<int> t;
                  t.push_back(a);
                  t.push_back(b);
                  t.push_back(v[k]);
                  t.push_back(v[k + 1]);
                  vec.push_back(t);
               }
            }
            while (num[j + 1] == b && j + 1 < n)
               ++j;
         }
         while (num[i + 1] == a && i + 1 < n)
            ++i;
      }
      return vec;
   }

private:
   vector<int> twosum(vector<int>& num, int start, int end, int target) {
      vector<int> vec;
      int low = start;
      int high = end - 1;
      while (low < high) {
         int a = num[low];
         int b = num[high];
         if (a + b == target) {
            vec.push_back(a);
            vec.push_back(b);
            while (low < high && num[low + 1] == a) low++;
            low++;
            while (high > low && num[high - 1] == b) high--;
            high--;
         }
         else if (a + b < target) {
            low++;
         }
         else {
            high--;
         }

      }
      return vec;
   }
};
