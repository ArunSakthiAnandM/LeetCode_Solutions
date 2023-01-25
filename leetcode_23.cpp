//Using Recursion
//merge lists one by one with the first list
//Time Complexity -> O(l*k)
//Memory Complexity -> O(l*k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* fun (ListNode* a, ListNode* b)
    {
        if(!a) return b;
        if(!b) return a;
        if(a->val <= b->val)
        {
            a->next = fun(a->next,b);
            return a;
        }
        else
        {
            b->next = fun(b->next,a);
            return b;
        }
        return nullptr;
    }
    ListNode* mergeKLists(vector<ListNode*>& l) {
        ListNode* ans;
        int s = l.size();
        if(s == 0) return nullptr;
        ans = l[0];
        for(int i=1;i<s;i++)
        {
            ans = fun(ans,l[i]);
        }
        return ans;
    }
};