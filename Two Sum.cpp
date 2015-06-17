class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // 使用coolshell的方法
        map<int,int> list;
        vector<int> result;
        for(int i = 0;i < numbers.size();++i)
        {
            if(list.find(numbers[i]) == list.end())
            {
                // 没找到
                list[target - numbers[i]] = i;
            }
            else
            {
                //找到
                result.push_back(list[numbers[i]] + 1);
                result.push_back(i + 1);
            }
        }
        return result;
        
    }
};
