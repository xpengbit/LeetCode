/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *pre = NULL, *next;
        while(cur != NULL){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;    
        }
        return pre;
        //return reverse(head, NULL);
    }
    /*use recursive*/
    /*ListNode* reverse(ListNode* cur, ListNode* pre ){
        if(cur == NULL) return pre;
        ListNode* next = cur->next;
        cur->next = pre;
        return reverse(next, cur);
    }*/
};
// @lc code=end

