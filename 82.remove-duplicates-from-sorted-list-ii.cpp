/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* cur = head;
        ListNode* pre = Dummy;
        while(cur != NULL and cur->next != NULL){
            if(cur->val == cur->next->val){
                int tmp = cur->val;
                while(cur != NULL and cur->val == tmp)
                    cur = cur->next;
                pre->next = cur;
            }
            else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        return Dummy->next;
    }
};
// @lc code=end

