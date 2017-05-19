
> Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next)return head;
        ListNode *cur = head->next,*tmp,*pre;
        head->next = NULL;
        tmp = new ListNode(0);
        tmp->next =head;
        head = tmp;
        while(cur){
            tmp =cur;
            cur = cur->next;
            pre = head;
            while(pre->next && pre->next->val < tmp->val)pre = pre->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return head->next;
    }
};
```