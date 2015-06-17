#include <vector>
#include <algorithm>
using namespace std;
//bool operator== (const vector<int> &a, const vector<int> &b){
//  int len_a = a.size();
//  int len_b = b.size();
//  if (len_a != len_b)
//      return false;
//  int i = 0;
//  int j = 0;
//  while (a[i++] == b[j++])
//      ;
//  return i == len_a && j == len_b;
//}
class Solution {
public:
   vector<vector<int>> threeSum(vector<int> &num) {

      vector<vector<int>> vec;

      sort(num.begin(), num.end());

      int n = num.size();

      for (int i = 0; i < n - 2; ++i) {
         if (i > 0 && num[i - 1] == num[i]) continue;
         int a = num[i];
         if(a > 0) break;
         int low = i + 1;
         int high = n - 1;
         while (low < high) {
            int b = num[low];
            int c = num[high];
            if (a + b + c == 0) {
               vector<int> v;
               v.push_back(a);
               v.push_back(b);
               v.push_back(c);
               vec.push_back(v);
               // skip duplication
               while (low < n - 1 && num[low] == num[low + 1]) low++;
               while (high > 0 && num[high] == num[high - 1]) high--;
               low++;
               high--;
            }
            else if (a + b + c > 0) {
               // skip duplication
               while (high > 1 && num[high] == num[high - 1]) high--;
               high--;

            }
            else {
               // skip duplication
               while (low < n - 1 && num[low] == num[low + 1]) low++;
               low++;

            }
         }
      }

      return vec;

   }
};
