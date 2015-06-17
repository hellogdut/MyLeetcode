class Solution {
public:
   Solution()
   {
      list["I"] = 1;
      list["X"] = 10;
      list["V"] = 5;
      list["M"] = 1000;
      list["D"] = 500;
      list["C"] = 100;
      list["L"] = 50;
   }
   int romanToInt(string s) {
      if (s.length() == 0)
         return 0;
      string s0;
      string s1;
      s0.push_back(s[0]);
      s1.push_back(s[1]);
      if (s0[0] == 'I' || s0[0] == 'X' || s0[0] == 'C'){
         if (s[1] == '\0')
            return list.find(s0)->second;
         int next = list.find(s1)->second;
         if (next > list.find(s0) ->second)
            return next - list.find(s0)->second + romanToInt(s.substr(2, s.length() - 2));
         else{
            return list.find(s0)->second + romanToInt(s.substr(1, s.length() - 1));
         }
      }
      else{
         return list.find(s0)->second + romanToInt(s.substr(1, s.length() - 1));
      }
   }
private:
   map<string, int> list;
};
