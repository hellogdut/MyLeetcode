// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int i = 0;
//         int j = s.size() - 1;
//         while(i < j)
//         {
//             while(i < j && !isalnum(s[i]))
//                 i++;
//             while(j > i && !isalnum(s[j]))
//                 j--;
//             if(tolower(s[i]) != tolower(s[j]))
//                 return false;
//             i++;
//             j--;
//         }
        
//         return true;
        
//     }
// };
class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        t.resize(s.size());
        auto f = copy_if(s.begin(),s.end(),t.begin(),[](const char& c){return isalnum(c);});
        t.erase(f,t.end());
        
        int i = 0;
        int j = t.size() - 1;
        while(i < j)
        {
            if(tolower(t[i]) != tolower(t[j]))
                return false;
            i++;
            j--;
        }
        
        return true;
        
    }
};
