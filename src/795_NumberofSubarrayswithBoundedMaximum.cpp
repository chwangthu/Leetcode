//Mar 5 2018

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }
    int count(vector<int> A, int t) {
        int cur = 0, ans = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > t) cur = 0;
            else cur += 1;
            ans += cur;
        }
        return ans;
    }
};