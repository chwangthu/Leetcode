class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int pswap = 1, pnswap = 0;  //前一个位置交换或者不交换
        int n = A.size();
        for(int i = 1; i < n; i++) {
            int swap = 0x7ffffff, nswap = 0x7ffffff;  //当前位置是否交换
            if(A[i-1] < A[i] && B[i-1] < B[i]) {    //交换或者不交换
                nswap = min(pnswap, nswap);
                swap = min(swap, pswap + 1);
            }
            if(A[i-1] < B[i] && B[i-1] < A[i]) {    //必须交换
                swap = min(pnswap + 1, swap);
                nswap = min(pswap, nswap);
            }
            pswap = swap;
            pnswap = nswap;
        }
        return min(pswap, pnswap);
    }
};