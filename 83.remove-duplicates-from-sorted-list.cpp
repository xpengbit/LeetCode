/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
        ListNode* cur = head;
        while(cur != NULL){
            while(cur->next != NULL and cur->val == cur->next->val)
                cur->next = cur->next->next;
        cur = cur->next;
        }
        return head;
        /*Solution use recursive*/
        /*if(head == NULL or head->next == NULL) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;*/
    }
};
// @lc code=end

