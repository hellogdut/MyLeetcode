class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string s;
        leftOrRight(n,n,vec,s);
        return vec;
        
        
    }
    void leftOrRight(int l,int r,vector<string>& vec,string s)
    {
        if(l == 0 && r == 0)
        {
            return vec.push_back(s);
        }
        if(l == r)
        {
            // can only push '('
            s.push_back('(');
            return leftOrRight(l - 1,r,vec,s);
        }
        if(l > 0)
        {
            string s1 = s;
            s1.push_back('(');
            leftOrRight(l - 1,r,vec,s1);
        }
        if(r > 0)
        {
            s.push_back(')');
            leftOrRight(l,r - 1,vec,s);
        }
    }
};

