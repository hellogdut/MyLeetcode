class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> result;
        string curr;
        _restoreIpAddresses(result,s,curr,0,4);
        return result;
    }
private:
    void _restoreIpAddresses(vector<string>& result,string& s,string& curr,int i,int k)
    {
        
        if(k == 0 && i == s.size())
        {
            result.push_back(curr);
            return;
        }
        if(i >= s.size() || k < 0)
            return;
        
        // 压入1个
        curr.push_back(s[i]);
        if(k != 1)
            curr.push_back('.');
        _restoreIpAddresses(result,s,curr,i + 1,k - 1);
        if(curr.back() == '.')
            curr.pop_back();
        curr.pop_back();
        // 压入2个
        if(i <= s.size() - 2)
        {
            if(s[i] == '0')
                return;
            
            curr.push_back(s[i]);
            curr.push_back(s[i+1]);
            if(k != 1)
                curr.push_back('.');
            _restoreIpAddresses(result,s,curr,i + 2,k - 1);
            if(curr.back() == '.')
                curr.pop_back();
            curr.pop_back();
            curr.pop_back();
        }
        if(i <= s.size() - 3)
        {
            string num;
            num.push_back(s[i]);
            num.push_back(s[i+1]);
            num.push_back(s[i+2]);
            
            if(stoi(num) > 255 || (stoi(num) < 100))
                return;
            
            curr.push_back(s[i]);
            curr.push_back(s[i+1]);
            curr.push_back(s[i+2]);
            if(k != 1)
                curr.push_back('.');
            _restoreIpAddresses(result,s,curr,i + 3,k - 1);
            if(curr.back() == '.')
                curr.pop_back();
            curr.pop_back();
            curr.pop_back();
            curr.pop_back();
        }
    }
    
};
