思路：根据等式构造连通图并着色（利用DFS或栈），然后根据不等式判断是否满足要求

```c++
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> graph;
        for(int i = 0; i < 26; i++) {
            vector<int> tep;
            graph.push_back(tep);
        }
        for(auto equ : equations) { //construct the graph
            if(equ[1] == '=') {
                int x = equ[0] - 'a';
                int y = equ[3] - 'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        vector<int> color;
        for(int i = 0; i < 26; i++) {
            color.push_back(0);
        }
        int t = 0;
        for(int i = 0; i < 26; i++) {
            if(color[i] == 0) {
                t++;
                stack<int> colorStack;
                colorStack.push(i);
                while(colorStack.empty() == false) {
                    int tep = colorStack.top();
                    colorStack.pop();
                    color[tep] = t;
                    for(auto nei : graph[tep]) {
//                        cout << nei << " ";
                        if(color[nei] == 0) {
                            color[nei] = t;
                            colorStack.push(nei);
                        }
                    }
                }
            }
        }
//        for(int i = 0; i < 26; i++) {
//            cout << i << "th " << color[i] << " ";
//        }
//        cout << endl;
        for(auto equ : equations) {
            if(equ[1] == '!') {
                int x = equ[0] - 'a';
                int y = equ[3] - 'a';
                if(x == y) return false;
                if(color[x] != 0 && color[x] == color[y]) return false;
            }
        }
        return true;
    }
};
```



