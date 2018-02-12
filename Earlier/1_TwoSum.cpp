class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto p = map.find(target-nums[i]);
            if (p!=map.end()) {
                return {p->second, i};
            }
            map[nums[i]]=i;
        }
    }
};