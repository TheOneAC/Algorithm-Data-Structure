
> reverse a list inplace

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* dummy = new ListNode(0);
        ListNode* cur;
        while(head){
            cur = head;
            head = head->next;
            cur->next = dummy->next;
            dummy->next = cur;
        }
        return dummy->next;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* cur  = right,*head = left;
        while(right != NULL){
            cur  = right;
            right = right->next;
            cur->next = left->next;
            left->next = cur;
            left = left->next->next;
        }
        return head;
    }
    void reorderList(ListNode *head) {
        if(!head || !head->next)return ;
        ListNode* fast = head->next, *slow =head;
        while(fast &&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = reverse(slow->next);
        slow->next = NULL;
        head =  merge(head,fast);
    }
};
```