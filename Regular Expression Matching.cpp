#include <string>
class Solution {
public:
   bool isMatch(const char *s, const char *p) {
      if (*p == '\0')
         return *s == '\0';

      // next char is not '*' :: must match current char
      if (*(p + 1) != '*')   {
         return ((*p == *s) || ((*p == '.') && *s != '\0')) && isMatch(s + 1, p + 1);
      }
      // next char is '*'
      while ((*p == *s) || (*p == '.' && *s != '\0')) {
         if (isMatch(s, p + 2)) return true;
         s++;
      }
      // now have skip all the chars equal to *p,match the rest
      return isMatch(s, p + 2);

   }
};
