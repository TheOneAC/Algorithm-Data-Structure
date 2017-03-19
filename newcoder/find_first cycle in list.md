> Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.
Follow up:
Can you solve it without using extra space?



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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)return NULL;
        ListNode *fast = head, *slow = head;
        while(fast){
            fast = fast->next;
            if(NULL == fast)break;
            fast = fast->next;
            slow = slow->next;
            if(slow == fast)break;
            
        }
        if(fast == NULL)return fast;
        fast = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
```