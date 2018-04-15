class Solution {
public:
    int N[10001];
    int numComponents(ListNode* head, vector<int>& G) {
        for(int i = 0; i < 10001; i++)  N[i] = 0;
        int ans = 0;
        for(auto & t: G) {
            N[t] = 1;
        }
        ListNode* cur = head;
        while(cur != NULL) {
            if(N[cur -> val] && (cur -> next == NULL || !N[cur -> next -> val])) 
                ans++;
            cur = cur -> next;
        }
        return ans;
    }
};