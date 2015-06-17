class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int>wordTimes;//L中单词出现的次数
        for(int i = 0; i < L.size(); i++)
            if(wordTimes.count(L[i]) == 0)
                wordTimes.insert(make_pair(L[i], 1));
            else wordTimes[L[i]]++;
        int wordLen = L[0].size();
         
        vector<int> res;
        for(int i = 0; i < wordLen; i++)
        {//为了不遗漏从s的每一个位置开始的子串，第一层循环为单词的长度
            unordered_map<string, int>wordTimes2;//当前窗口中单词出现的次数
            int winStart = i, cnt = 0;//winStart为窗口起始位置,cnt为当前窗口中的单词数目
            for(int winEnd = i; winEnd <= (int)S.size()-wordLen; winEnd+=wordLen)
            {//窗口为[winStart,winEnd)
                string word = S.substr(winEnd, wordLen);
                if(wordTimes.find(word) != wordTimes.end())
                {
                    if(wordTimes2.find(word) == wordTimes2.end())
                        wordTimes2[word] = 1;
                    else wordTimes2[word]++;
                     
                    if(wordTimes2[word] <= wordTimes[word])
                        cnt++;
                    else
                    {//当前的单词在L中，但是它已经在窗口中出现了相应的次数，不应该加入窗口
                     //此时，应该把窗口起始位置想左移动到，该单词第一次出现的位置的下一个单词位置
                        for(int k = winStart; ; k += wordLen)
                        {
                            string tmpstr = S.substr(k, wordLen);
                            wordTimes2[tmpstr]--;
                            if(tmpstr == word)
                            {
                                winStart = k + wordLen;
                                break;
                            }
                            cnt--;
                        }
                    }
                     
                    if(cnt == L.size())
                        res.push_back(winStart);
                }
                else
                {//发现不在L中的单词
                    winStart = winEnd + wordLen;
                    wordTimes2.clear();
                    cnt = 0;
                }
            }
        }
        return res;
    }
};
