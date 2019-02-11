Technique: Process two arrays at the same time.

```c++
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> tep, ans;
        int s = A.size();
        while(--s >= 0 || K > 0) {
            if(s >= 0) K += A[s];
            tep.push_back(K % 10);
            K /= 10;
        }
        for(vector<int>::reverse_iterator rit = tep.rbegin(); rit != tep.rend(); rit++) {
            ans.push_back(*rit);
        }
        return ans;
    }
};
```



