//Feb 22 2018
//To judge whether the graph is bipartite
//Cautions: The graph can be disconnected
//We always paint the graph in one connected component, using DFS or BFS
//DFS can be simulated by stack and BFS can be stimulated by queue
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int* color = new int[n];
        for(int i = 0; i < n; i++)
            color[i] = -1;
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)  //A new connected component
            {
                stack<int> s;   //We can also use queue
                s.push(i);
                color[i] = 0;
                while(!s.empty())
                {
                    int t = s.top();
                    s.pop();
                    for(auto iter = graph[t].begin(); iter != graph[t].end(); iter++)
                    {
                        if(color[*iter] == -1)
                        {
                            s.push(*iter);
                            color[*iter] = color[t] ^ 1;
                        }
                        else if(color[*iter] == color[t])   //contradict
                            return false;
                    }
                }
            }
        }
        return true;
    }
};