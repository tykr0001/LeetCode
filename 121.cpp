class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_p = prices[0];
        for(auto p : prices){
            ans = max(ans, p-min_p);
            min_p = min(min_p, p);
        }
        return ans;
    }
};