class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> my_graph;
    int n;
    void dfs(int tar, vector<int> seq) {
        if(tar == n) { ans.push_back(seq); return; }
        for(const int t : my_graph[tar]) {
            seq.push_back(t);
            dfs(t, seq);
            seq.erase(seq.end() - 1, seq.end());    //回溯
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size() - 1;
        my_graph = graph;
        dfs(0, {0});
        return ans;
    }
};
