/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL or left == right) return head;

        ListNode* Dummy = new ListNode(-1, head);
        ListNode* pre = Dummy;
        ListNode* cur = Dummy->next;
        int i = 1;
        while(i < left){
            cur = cur->next;
            pre = pre->next;
            i++;
        }

        ListNode* node = pre;

        while(i++ <= right){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        node->next->next = cur;    
        node->next = pre;

        return Dummy->next;
    }
};
// @lc code=end

