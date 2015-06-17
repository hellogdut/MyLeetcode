class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() == needle.size() && haystack.size() == 0)
            return 0;
        if(haystack.size() != 0 && needle.size() == 0)
            return 0;
            
        int k = -1;
        for(int i = 0;i < (int)(haystack.size() - needle.size() + 1);++i)
        {
            int j = 0;
            while(j < needle.size() && haystack[i+j] == needle[j])
                j++;
            if(j == needle.size() && j != 0)
            {
                k = i;
                break;
            }
        }
        return k;
    }
};
