/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* Dummyless = new ListNode(-1);
        ListNode* Dummygreat = new ListNode(-1);
        ListNode* less = Dummyless;
        ListNode* greater = Dummygreat;
        ListNode* cur = head;
        while(cur != NULL){
            if(cur->val < x){ 
                less->next = cur;
                less = less->next;
            }
            else{
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }
        greater->next = NULL;
        less->next = Dummygreat->next;
        return Dummyless->next;
    }
};
// @lc code=end

