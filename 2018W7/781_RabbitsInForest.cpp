//11 Feb 2018
//sort the array then find the number of every duplicate value
//every uniform value at most have (value + 1) members in a group
//say there are 5 rabbits reporting 3, only 4 of them can be considered as the same color, the left one must be a different color 
struct Dup
{
    int val; int num;
};

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int res = 0;
        vector<Dup> d;
        int cur = -1;
        for(int i = 0; i < answers.size(); i++)
        {
            if(d.size() == 0 || answers[i] != answers[i - 1])
            {
                d.push_back(Dup{answers[i], 1});
                cur++;
            }
            else d[cur].num++;
        }
        for(int i = 0; i < d.size(); i++)
        {
            if(d[i].num % (d[i].val + 1) == 0)
                res += d[i].num;
            else res += ((d[i].num / (d[i].val + 1)) + 1) * (d[i].val + 1);
        }
        return res;
    }
};