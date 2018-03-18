class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        int score = 0;
        int *good = new int[n];
        int *bad = new int[n];
        for(int i = 0; i < n; i++)
            good[i] = bad[i] = 0;
        
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < i) {
                if(i - A[i] + 1 < n)
                    bad[i - A[i] + 1] += 1;
                if(i + 1 < n) good[i + 1] += 1;
            }
            else if(i == A[i]) {
                if(i != 0) bad[1] += 1;
                if(i + 1 < n && i != 0) good[i+1] += 1;
            }
            else {
                good[i+1] += 1;
                bad[n - A[i] + i + 1] += 1;
            }
        }
        for(int i = 0; i < A.size(); i++)
            if(A[i] <= i) score++;
        int max = score, ans = 0;
        for(int i = 1; i < n; i++) {
            score += good[i] - bad[i];
            if(score > max) {
                max = score;
                ans = i;
            }
        }
        return ans;
    }
};
