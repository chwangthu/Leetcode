//Mar 9 2018
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        for(int i = numbers.size() - 1; i >= 0; i--) {
            if(map.find(target - numbers[i]) != map.end()) {
                return {i + 1, map[target - numbers[i]] + 1};
            }
            map[numbers[i]] = i;
        }
        return {};
    }
};