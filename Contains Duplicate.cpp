class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> _set;
        for(auto i : nums)
        {
           if(_set.count(i) != 0)
              return true;
           _set.insert(i);
        }
        return false;
    }
};
