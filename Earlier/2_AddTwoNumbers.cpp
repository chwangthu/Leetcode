class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int tep = 0;
        ListNode* p1 = l1, *p2 = l2;
        ListNode* lt1 = nullptr, *lt2 = nullptr;
        for(p1=l1, p2=l2; p1!=NULL&&p2!=NULL; p1=p1->next, p2=p2->next)
        {
            p1->val = p1->val + p2->val + tep;
            tep = p1->val / 10; p1->val %= 10;
            if(p1 -> next == NULL) lt1 = p1;
            if(p2 -> next == NULL) lt2 = p2;
        }
        if(p1 == NULL && p2 == NULL)
        {
            if(tep > 0) lt1 -> next = new ListNode(tep);
        }
        else if(p1 == NULL)
        {
            p1 = p2; lt1 -> next = p1;
            for(;p2!=NULL; p2=p2->next)
            {
                p2->val += tep;
                tep = p2 -> val / 10; p2->val %= 10;
                if(p2 -> next == NULL) lt2 = p2;
            }
            if(tep > 0)
                lt2 -> next = new ListNode(tep);
        }
        else if(p2 == NULL)
        {
            for(;p1!=NULL; p1=p1->next)
            {
                p1->val += tep;
                tep = p1 -> val / 10; p1->val %= 10;
                if(p1 -> next == NULL) lt1 = p1;
            }
            if(tep > 0) lt1 -> next = new ListNode(tep);
        }
        return l1;
    }
};