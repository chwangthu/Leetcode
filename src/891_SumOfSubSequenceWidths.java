//Sort first and it doesn't affect answer
//For A[i], there are 2^i to be max and 2^(n-i-1) to be min
//So for every i, result = 2^(n-i-1) * A[i] - 2^i * A[i]
class Solution {
  public int sumSubseqWidths(int[] A) {
    Arrays.sort(A);
    long res = 0, p = 1;
    long mod = (long)1e9 + 7;
    for(int i = 0; i < A.length; i++, p = (p << 1) % mod) {
      res = (res + A[i] * p - A[A.length - i - 1] * p) % mod;
    }
    return (int)(res % mod);
  }
}
