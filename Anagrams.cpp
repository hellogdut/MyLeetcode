class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        
        vector<string> result;
        
        vector<vector<int>>  count;
        unordered_map<string,pair<int,bool>> table;
        
        for(int i = 0;i < strs.size();++i)
        {
            auto s = strs[i];
            vector<int> v;
            for(int i = 0;i < 26;++i)
                v.push_back(0);
            for(auto& c: s)
            {
                v[c - 'a']++;
            }
            string hash;
            for(int j = 0;j < v.size();++j)
            {
                hash.push_back(v[j] - '0');
            }
            auto f = table.find(hash);
            
            // 没找到，插入
            if(f == table.end())
            {
                table[hash] = make_pair(i,false);
            }
            else
            {
                // 加入到结果
                result.push_back(strs[i]);
                // 如果表中的项还没加入到结果
                if(table[hash].second == false)
                {
                    result.push_back(strs[table[hash].first]);
                    table[hash].second = true;
                    
                }
            }
            
        }
        return result;
    }
};

