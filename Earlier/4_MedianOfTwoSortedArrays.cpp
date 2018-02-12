//Feb 1 2018
//merge two sorted arrays and judge even or odd
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> ans;
        int a = nums1.size(); int b = nums2.size();
        int m = (a + b) >> 1;
        int i = 0, j = 0;
        for(int k = 1; k <= m + 1; k++)
        {
            if(j >= b || (i < a && nums1[i] <= nums2[j])) { ans.push_back(nums1[i]); i++; }
            else { ans.push_back(nums2[j]); j++; }
        }
        if((a + b) % 2) return ans[m];
        return ((ans[m-1] + ans[m]) / 2);
    }
};