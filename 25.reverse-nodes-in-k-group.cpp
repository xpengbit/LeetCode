/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*iterative 解法*/
        ListNode* Dummy = new ListNode(-1), *pre = Dummy, *cur = pre;
        Dummy->next = head;
        int num = 0;
        while(cur != NULL) num++;
        while(num >= k){
            cur = pre->next;
            for(int i = 1; i < k; ++i){ /*这里i小于k，因为cur->next也处理了*/
                ListNode* t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            num -= k;
            pre = cur;
        }
        return Dummy->next;
        
        /*递归解法*/
        ListNode* cur = head;
        for(int i = 0; i < k; ++i){
            if(!cur)  return head;
            cur = cur->next;
        }

        ListNode* new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;        
    }

    /*这里的reverse返回的是反转后的new head*/
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* pre = tail;
        while(head != tail){
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre; 
    }
    /*另外一种reverse返回反转后的最后一个元素指针*/
    ListNode* reverse(ListNode* pre, ListNode* tail){
        ListNode* cur = pre->next;
        while(cur != tail){
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
};
// @lc code=end

