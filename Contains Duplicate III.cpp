// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

//        unordered_map<int,int> _map;
//        for(int i = 0;i < nums.size();++i)
//        {

//           // 很猥琐的解法  (◔౪◔)
//           // 如果差距大的话，直接暴力搜索
//           // 差距小，查表
//           if(t > 10000)
//           {
//              for(int i = nums.size() - 1;i >= 0;--i)
//              {
//                 if(i > nums.size() - 1)
//                    break;
//                 for(int j = i - 1;j >= 0;--j)
//                 {
//                    long long dis = abs((long long) nums[j] - nums[i]);
//                    if(dis <= t && abs(i - j) <= k)
//                       return true;
//                    else if(abs(i - j) > k)
//                       break; 
//                 }
//                 nums.pop_back();
//              }
//           }
//           else
//           {
//              for(int j = 0;j <= t;j++)
//              {
//                 int dummy = nums[i] - j;
//                 if(_map.count(dummy) != 0 && abs(_map[dummy] - i) <= k)
//                    return true;
//                 dummy = nums[i] + j;
//                 if(_map.count(dummy) != 0 && abs(_map[dummy] - i) <= k)
//                    return true;
//              }
//              _map[nums[i]] = i;
//           }
//        }
//        return false;
        
//     }
// };

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

       vector<pair<int,int>> vec;


       for(int i = 0;i < nums.size();++i)
          vec.push_back(make_pair(nums[i],i));

       sort(vec.begin(),vec.end(),[](const pair<int,int>& a,const pair<int,int> &b){
          return a.first < b.first;
       });

       for(int i = vec.size() - 1;i >= 0;i = vec.size() - 1)
       {
          for(int j = i - 1;j >= 0;--j)
          {
             long long dis = abs((long long) vec[i].first - vec[j].first);
             if(dis > t)
                break;
             if(abs(vec[i].second - vec[j].second) <= k)
                return true;
          }
          vec.pop_back();
       }
       return false;
        
    }
};
