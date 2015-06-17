class Solution {
public:
   int maxcount(string& s, int i)
   {
      int  a[128] = { 0 };
      int count = 0;
      for (; i < s.length(); ++i)
      {
         int index = s[i];
         if (a[index] == 0)
         {
            a[index] = 1;
            ++count;
         }
         else
            return count;
      }
      return count;
   }
   int lengthOfLongestSubstring(string s) {
      int max = 0;
      for (int i = 0; i < s.length(); ++i)
      {
         int j = maxcount(s, i);
         if (j > max)
            max = j;
      }
      return max;

   }
};
