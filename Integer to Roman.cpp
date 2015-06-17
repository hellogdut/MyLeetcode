#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
   string intToRoman(int num){
      string roman[] = { "M", "D", "C", "L", "X", "V", "I" };
      int    val[] = { 1000, 500, 100, 50, 10, 5, 1 };
      string str;
      while (num >= 1000) {
         str += "M";
         num -= 1000;
      }
      // now (1 < num < 1000)
      int i = 0;
      while (num > 0) {

         while (val[i] > num) i++;
         // if fit one roman number
         if (num == val[i]) {
            str += roman[i];
            num -= val[i];
            continue;
         }
         // try if minus
         int d = val[i - 1] - num;
         if (d <= 100 && num > 100){
            str += "C";
            str += roman[i - 1];
            num = num + 100 - val[i - 1];
            continue;
         }
         if (d <= 10 && num > 10){
            str += "X";
            str += roman[i - 1];
            num = num + 10 - val[i - 1];
            continue;

         }
         if (d == 1 && num > 1){
            str += "I";
            str += roman[i - 1];
            num = num + 1 - val[i - 1];
            continue;

         }
         // now must add
         str += roman[i];
         num = num - val[i];

      }
      return str;
   }
};
