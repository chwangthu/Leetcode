//Feb 26 2018

//最右侧为竖矩形 f[n-1]
//最右侧为横矩形 f[n-2]
//最右侧为L型，设可能性为g(n)
//f(n) = f(n-1) + f(n-2) + g(n) * 2
//g(n) = f(n-3) + g(n-1) -> g(n) = f(n-3) + ... + f(0)
//f(n) = f(n-1) + f(n-2) + 2 * (f(n-3) + ... + f(0))
// =f[n-1]+f[n-2]+f[n-3]+f[n-3]+2*(f[n-4]+…+d[0])
// =f[n-1]+f[n-3]+(f[n-2]+f[n-3]+2*(f[n-4]+…+d[0]))
// =f[n-1]+f[n-3]+f[n-1]
// =2*f[n-1]+f[n-3]
class Solution {
public:
    int numTilings(int N) {
        int f[1000];
        f[1] = 1; f[2] = 2; f[3] = 5;
        for(int i = 4; i <= N; i++)
        {
            f[i] = (2 * (long long)f[i-1] + (long long)f[i-3]) % int(1e9 + 7);
        }
        return f[N];
    }
};