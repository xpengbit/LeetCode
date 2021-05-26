/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* fast = Dummy, *slow = Dummy;

        for(int i = 1;i <= n + 1; i++){
            fast = fast->next;
        }
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return Dummy->next;
    }
};
// @lc code=end

