class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> s;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            auto it = s.lower_bound(x - valueDiff);

            if (it != s.end() && *it <= x + valueDiff) {
                return true;
            }

            s.insert(x);

            if (i >= indexDiff) {
                s.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};