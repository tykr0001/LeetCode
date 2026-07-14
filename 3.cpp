class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int left = 0;
        int ans = 0;
        for(int right=0; right<s.size(); right++){
            while(us.count(s[right])){
                us.erase(s[left]);
                left++;
            }

            us.insert(s[right]);
            ans = max(ans, (int)us.size());
        }
        return ans;
    }
};