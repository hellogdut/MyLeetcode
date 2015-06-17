class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
       
    //    if(nums.size() == 0 || nums.size() == 1)
    //       return nums.size();

    //    int prev = 0;
    //    int curr = 1;
       
    //    while(curr < nums.size())
    //    {
    //       if(nums[curr] == nums[prev])
    //       {
    //          int next = curr + 1;
    //          while(next < nums.size() && nums[next] == nums[curr])
    //             ++next;
    //          nums.erase(nums.begin() + curr,nums.begin() + next);
    //       }
    //       prev = curr;
    //       ++curr;
    //    }

    //    return nums.size();
    // }
    int removeDuplicates(vector<int>& nums) {

       if(nums.size() == 0 || nums.size() == 1)
          return nums.size();
       int prev = 0;
       int curr = 1;

       while(curr < nums.size())
       {
          if(nums[curr] == nums[prev])
          {
             while(nums[curr] == nums[prev] && curr < nums.size())
                curr++;
             if(curr == nums.size())
                break;
             nums[prev + 1] = nums[curr];
          }
          else if(curr - prev > 1)
          {
             nums[prev + 1] = nums[curr];
          }
          prev++;
          curr++;

          
       }
       return prev + 1;
    }

};
