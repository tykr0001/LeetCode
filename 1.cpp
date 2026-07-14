class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int need = target-nums[i];
            if(um.find(need) != um.end()){
                ans = {um[need], i};
                break;
            }
            um[nums[i]] = i;
        }
        return ans;
    }
};