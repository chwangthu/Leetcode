class Solution {
public:
    typedef long long ll;
    ll count(ll n) {
        ll res = 0;
        while(n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
    ll find(ll k) {
        ll lo = 0; ll hi = 5 * 1e9;
        while(lo < hi) {
            ll mi = (lo + hi) >> 1;
            if(count(mi) > k) hi = mi;
            else lo = mi + 1;
        }
        return --lo;
    }
    int preimageSizeFZF(int K) {
        if(K == 0) return 5;
        return (int)(find(K) - find(K-1));
    }
};