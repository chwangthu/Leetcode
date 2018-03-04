//Feb 26 2018
//If the ghost reachs you at point X, that means dist(g, x) <= dist(0, x), and then dist(g, t) <= dist(0, t), so we can assume that we go directly to the target
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> begin;
        begin.push_back(0); begin.push_back(0);
        for(const vector<int>& g : ghosts) {
            if(dist(g, target) <= dist(begin, target))
               return false;
        }
               return true;
    }
    int dist(const vector<int>& begin, const vector<int>& end) {
        return abs(begin[0] - end[0]) + abs(begin[1] + end[1]);
    }
};