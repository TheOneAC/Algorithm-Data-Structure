> Sort a linked list in O(n log n) time using constant space complexity.


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
    ListNode *sortList(ListNode *head) {
        if(!head || ! head->next)return head;
        ListNode *fast = head->next, *slow = head;
        while(fast && fast->next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        fast = sortList(slow->next);
        slow->next = NULL;
        slow = sortList(head);
        head = new ListNode(0);
        ListNode *cur = head;
        while(slow && fast){
            if(slow ->val < fast -> val){
                cur->next = slow;
                slow = slow->next;
            }else{
                cur->next = fast;
                fast = fast->next;
            }
            cur = cur->next;
        }
        if(slow == NULL)slow = fast;
        cur->next = slow;
        return head->next;
    }
};
```