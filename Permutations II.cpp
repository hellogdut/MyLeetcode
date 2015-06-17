class Solution {
private:
    // 尝试使用 set 来排除相同
    // 发现使用了 <= 后没有相同
    vector<vector<int>> result;
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //result.push_back(nums);
        result.push_back(nums);
        _permute(nums);
        //return vector<vector<int>>(result.begin(),result.end());
        return result;
        
    }
    void _permute(vector<int>& nums)
    {
        int i = nums.size() - 1;
        int ii = i - 1;
        
        // <=
        while(ii >= 0 && nums[i] <= nums[ii])
        {
            i--;
            ii--;
        }
        if(ii < 0)
            return;
        
        int j = nums.size() - 1;
        // <=
        while(j >= i && nums[j] <= nums[ii])
            j--;
        iter_swap(nums.begin() + ii,nums.begin() + j);
        inverse(nums,i,nums.size() - 1);
        
        result.push_back(nums);
        
        _permute(nums);
        
        
    }
    void inverse(vector<int>& nums,int i,int j)
    {
        while(i < j)
        {
            iter_swap(nums.begin() + i,nums.begin() + j);
            i++;
            j--;
        }
    }
};

// int main()
// {
//     Solution s;
//     vector<int> v = {1,1,2};
//     auto vv = s.permuteUnique(v);
//     for(auto& i: vv)
//     {
//         for(auto& j : i)
//             cout << j << " ";
//         cout << endl;
//     }
    
// }
