class Solution {
private:
    vector<vector<int>> result;
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // 不要以为这道题不用排序。坑死你
        
        sort(nums.begin(),nums.end());
        result.push_back(nums);
        _permute(nums);
        return result;
        
    }
    void _permute(vector<int>& nums)
    {
        int i = nums.size() - 1;
        int ii = i - 1;
        while(ii >= 0 && nums[i] < nums[ii])
        {
            i--;
            ii--;
        }
        if(ii < 0)
            return;
        
        int j = nums.size() - 1;
        while(j >= i && nums[j] < nums[ii])
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
//     vector<int> v = {0,-1,1};
//     auto vv = s.permute(v);
//     for(auto& i: vv)
//     {
//         for(auto& j : i)
//             cout << j << " ";
//         cout << endl;
//     }
    
// }

