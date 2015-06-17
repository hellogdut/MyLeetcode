class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            
            return a.start < b.start || ((a.start == b.start) && (a.end < b.end));
        });
        
        deque<Interval> queue(intervals.begin(),intervals.end());
        auto i = queue.begin();
        while(i < queue.end() - 1)
        {
            auto a = *i;
            auto b = *(i + 1);
            if((a.start <= b.start) && ((b.start <= a.end && a.start <= b.end) || (a.end >= b.end)))
            {
                int start = min(a.start,b.start);
                int end = max(a.end,b.end);
                
                auto j = queue.erase(i);
                j ->start = start;
                j ->end = end;
                i = j;
            }
            else
                ++i;
        }
        vector<Interval> result(queue.begin(),queue.end());
        return result;
    }
};
