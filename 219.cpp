class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> us;
        int left=0;
        for(int right=0; right<nums.size(); right++){
            if(right-left>k){
                us.erase(nums[left]);
                left++;
            }
            if(us.find(nums[right])!=us.end()){
                return true;
            }
            us.insert(nums[right]);
        }
        return false;
    }
};