class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.emplace_back(intervals[0]);
        for(auto itv : intervals){
            if(ans.back()[1] > itv[1])
                continue;
            if(ans.back()[1] < itv[0])
                ans.emplace_back(itv);
            else if(ans.back()[1] < itv[1])
                ans.back()[1] = itv[1];
        }
        return ans;
    }
};