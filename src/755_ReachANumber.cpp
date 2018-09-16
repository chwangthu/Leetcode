/*
a) if target is negative, we can reverse every step for abs(target), 
the result won't change, so we can only consider target as positive

b) suppose we goes straight right for t steps, find the exact t 
that makes t*(t+1)/2 exceeds target

c) if t*(t+1)/2 - target is even, we can go left in the 
(t*(t+1)/2-target)/2 step, then we can make it in t steps
  else, the result is at least t+1, then the problem equals to 
  compute if ((t+1)*(t+2)/2 - target) / 2 is even
*/

class Solution {
public:
    int reachNumber(int target) {
        if(target < 0) target *= -1;
        long long t = 0;
        while(t * (t + 1) / 2 < target) t++;
        while(true)
        {
            if(((t * (t + 1)) / 2 - target) % 2 == 0)
                return t;
            t++;
        }
    }
};