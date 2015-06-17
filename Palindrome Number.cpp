class Solution {
public:
   bool isPalindrome(int x) {
      if (x < 0)
         return false;
      if (x == 0)
         return true;

      int len = 1;
      while ((x / len) >= 10){
         len *= 10;
      }
      while (x != 0){
         int left = x / len;
         int right = x % 10;

         if (left != right)
            return false;
         x = (x - left * len) / 10;
         len /= 100;
      }
      return true;
   }
};
