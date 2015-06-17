class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v(digits);
        reverse(v.begin(),v.end());
        int k = 0;
        v[0] += 1;
        for(int i = 0;i < v.size();++i)
        {
            v[i] += k;
            k = 0;
            if(v[i] < 10)
                break;
            k = v[i]/10;
            v[i] %= 10;
        }
        if(k)
            v.push_back(k);
        reverse(v.begin(),v.end());
        return v;
        
    }
};
