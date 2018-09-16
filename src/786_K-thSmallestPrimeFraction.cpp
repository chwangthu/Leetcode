//Feb 18 2018
//Brutal force O(n^2) time and memory
//using reserve to keep the size constant and not double to n*(n-1) at the end

struct Pair
{
    int first, second;
    bool operator< (const Pair& cmp) const
    {
        return first * cmp.second < second * cmp.first;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<Pair> pairs;
        int s = A.size();
        pairs.reserve(s * (s - 1) / 2);
        for(int i = 0; i < s; i++)
            for(int j = i + 1; j < s; j++)
            {
                pairs.push_back({A[i], A[j]});
            }
        nth_element(pairs.begin(), pairs.begin() + K - 1, pairs.end());
        return {pairs[K-1].first, pairs[K-1].second};
    }
};