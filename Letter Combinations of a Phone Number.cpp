#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   vector<string> letterCombinations(string digits) {
      vector<string> com;
      string letter[] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
      int total[] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
      int n = digits.length();
      int cur[1000] = { 0 };

      if (n <= 0) {
         com.push_back("");
         return com;
      }
      while (1) {

         string str;
         for (int i = 0; i < n; ++i) {
            if (!isdigit(digits[i])) {
               if (com.size() == 0)
                  com.push_back("");
               return com;
            }
            int j = digits[i] - '0';
            str.push_back(letter[j][cur[i]]);
         }
         com.push_back(str);
         int k = n - 1;
         if (cur[k] < total[digits[k] - '0'] - 1)
            cur[k]++;
         else {
            while (k >= 0 && cur[k] >= total[digits[k] - '0'] - 1) {
               cur[k] = 0;
               --k;
            }
            if (k < 0)
               break;
            else
               cur[k]++;
         }

      }
      return com;
   }
};
