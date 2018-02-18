//14 Feb 2018
//Two pointers approach
//At each time, we only move the shorter pointer
//If we move the higher one, the result must get less
//If we move the shorter one, we only skip those are destined to contain less water
//eg.If left pointer is shorter and we move right, we miss (L, R-1), (L, R-2)..., those must be less than (L, R)

//So when we move to (L, R), we're already have the max in ((0, L), (R, n))
//And as we move further, we only skip less ones, so we can arrive at the largest one

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = height.size();
        int maxArea = 0;
        int l = 0, r = s - 1;
        while(l < r)
        {
            int tep = min(height[l], height[r]) * (r - l);
            if(tep > maxArea) maxArea = tep;
            if(height[l] > height[r])
                r--;
            else l++;
        }
        return maxArea;
    }
};