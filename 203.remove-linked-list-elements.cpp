/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* cur = Dummy;

        while(cur->next != NULL){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return Dummy->next;
        /*Solution use recursive*/
        /*if(head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;*/
    }
};
// @lc code=end

