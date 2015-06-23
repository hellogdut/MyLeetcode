class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> _map;
        for(int i = 0;i < nums.size();++i)
        {
           if(_map.count(nums[i]) != 0)
           {
              if(i - _map[nums[i]] <= k)
                 return true;
           }
           _map[nums[i]] = i;
        }
        return false;
    }

};
