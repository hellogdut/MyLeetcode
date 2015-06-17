class Solution {
public:
   string longestPalindrome(string s) {

      //preprocess to make a string from "abc" to "#a#b#c#"
      string T = "#";
      int n = s.length();
      for (int i = 0; i < n; ++i)
      {
         T += s.substr(i, 1);
         T += "#";
      }

      int* p = new int[T.length()];
      int C = 0, R = 0;   // center and range of longestPalindrome
      n = T.length();
      for (int i = 0; i < n; ++i)
      {
         p[i] = R > i ? min(p[2 * C - i], R - i) : 0;
         while (T[i + p[i] + 1] == T[i - 1 - p[i]])
            p[i]++;
         if (i + p[i] > R)
         {
            R = i + p[i];
            C = i;
         }
      }
      int max = 0;
      int c = 0;
      for (int i = 1; i < n - 1; ++i)
      {
         if (p[i] > max)
         {
            max = p[i];
            c = i;
         }
      }
      //
      delete[]p;
      return s.substr(c/2 - max/2,max);
   }
};
