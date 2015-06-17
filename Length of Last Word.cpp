class Solution {
public:
    int lengthOfLastWord(string s) {

        int len = 0;
        int n = s.size() - 1;
        // skip space 
        while(n >= 0 && s[n] == ' ')
            n--;

        for(;n >= 0;--n)
        {
            if(s[n] == ' ')
                break;
            else
                len++;

        }
        return len;

        
    }
};
