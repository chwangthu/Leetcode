//Mar 9 2018
//主要时间消耗在去重上面
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum < target) l++;
                else if(sum > target) r--;
                else {
                    vector<int> single = {nums[i], nums[l], nums[r]};
                    ans.push_back(single);
                    int t1 = nums[l], t2 = nums[r];
                    while(l < r && nums[l] == t1) l++;
                    while(l < r && nums[r] == t2) r--;
                }
            }
            while(i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};