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
    ListNode* sortLinkedList(ListNode* head) 
    {
        ListNode* pos = new ListNode(-1);
        ListNode* neg = new ListNode(-1);
        ListNode* p = pos, *n = neg;
        while(head){
            if(head->val >= 0){
                p->next = head;
                head = head->next;
                p = p->next;
            }
            else{
                n->next = head;
                head = head->next;
                n = n->next;
            }
        }

        p->next = NULL;
        n->next = NULL;
        n = neg->next;
        p = pos->next;
        n = reverse(n);
        if(n){
            while(n->next) n = n->next;
            n->next = p;
            return neg->next;
        }
        else
            return pos->next;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = NULL, *cur = head, *nxt;
        while(cur){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};