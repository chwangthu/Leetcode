//7 Feb 2018
//the relative order of L and R remains unchanged in the swap
//First we should check if every L and R corresponds in start and end string
//Another point is that in every swap L will go left and right vice versa
class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.length() != end.length()) return false;
        int n = start.length();
        int i = 0, j = 0;   //two pointer
        while(1)
        {
            while(i < n && start[i] == 'X') i++;
            while(j < n && end[j] == 'X') j++;
            if(i >= n && j >= n) return true;
            if(i < n && j < n && start[i] == end[j])
            {
                if(start[i] == 'L')
                {
                    if(j > i) return false;
                }
                else if(start[i] == 'R')
                {
                    if(j < i) return false;
                }
                i++; j++;
            }
            else return false;
         }
    }
};

//In python, this problem can be much simpler
class Solution:
    def canTransform(self, start, end):
        """
        :type start: str
        :type end: str
        :rtype: bool
        """
        s = [(c, i) for i, c in enumerate(start) if c == 'L' or c == 'R']
        e = [(c, i) for i, c in enumerate(end) if c == 'L' or c == 'R']
        return len(s) == len(e) and all(c1 == c2 and (i1 >= i2 and c1 == 'L' or i1 <= i2 and c1 == 'R') for (c1, i1), (c2, i2) in zip(s,e))