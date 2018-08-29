//最小表示法
class Solution {
public:
    int findMin(string s) {
        int len = s.length();
        int i = 0, j = 1, k = 0;
        while(i<len&&k<len&&j<len) {
            if(s[(i+k)%len]==s[(j+k)%len]) {
                k++;
            }
            else if(s[(i+k)%len]>s[(j+k)%len]) {
                i=i+k+1;
                k=0;
            }
            else {
                j=j+k+1;
                k=0;
            }
            if(i==j) j++;
        }
        return min(i,j);
    }
    
    bool rotateString(string A, string B) {
        int a = findMin(A), b = findMin(B);
        string A1 = A.substr(a, A.length() - a);
        A1.append(A.substr(0, a));
        string B1 = B.substr(b, B.length() - b);
        B1.append(B.substr(0, b));
        return A1 == B1;
    }
};