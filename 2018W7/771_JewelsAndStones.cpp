//14 Feb 2018
//Brutal force
class Solution {
public:
    int numJewelsInStones(string J, string S){
        int ans = 0;
        for(int i = 0; i < S.length(); i++)
        {
            bool found = false;
        	for(int j = 0; j < J.length(); j++){
        	if(S[i] == J[j]) 
        	{
            	found = true;
         		break;
            }
        }
        if(found) ans++;
        }
        return ans;
    }
};