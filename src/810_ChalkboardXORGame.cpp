class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums) {
            sum ^= num;
        }
        return (sum == 0) || (nums.size() % 2 == 0);
    }
};