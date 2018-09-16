//4 Feb 2018
//the kth number in N comes from the (k+1)/2 number in N-1
//divide k for N-1 times and determine whether K is even or odd
//0 -> 01 1 -> 10
//even xor one time, odd two times
class Solution {
public:
    int kthGrammar(int N, int K) {
        stack<int> s;
        for(int i = 1; i < N; i++)
        {
            if(K % 2) s.push(1);
            else s.push(0);
            K = (K + 1) / 2;
        }
        int ans = 0;
        N -= 1;
        while(N--)
        {
            ans ^= 1;   //odd numbers xor for 2 times
            if(s.top()) ans ^= 1;
            s.pop();
        }
        return ans;
    }
};