//Push every second element to the end
//Link the 1st and 3rd element
//Update end and nullify end->next
//Time Complexity -> O(n)
//Memory Complexity -> O(1)

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* end = head;
        ListNode* curr = head;
        int count = 0;
        while(end->next != nullptr)
        {
            end = end->next;
            count++;
        }
        if(count <= 1) return head;
        count = (count-1)/2;
        while(count>=0)
        {
            end->next = curr->next;
            curr->next = curr->next->next;
            end->next->next = nullptr;
            end = end->next;
            curr = curr->next;
            count--;
        }
        return head;
    }
};