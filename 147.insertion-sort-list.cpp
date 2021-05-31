/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* pre = NULL;
        while(head->next != NULL){
            if(head->next->val < head->val){
                pre = head->next;
                head->next = head->next->next;
                ListNode* tmp = Dummy;
                while(true){
                    if(tmp->next->val > pre->val){
                        pre->next = tmp->next;
                        tmp->next = pre;
                        break;
                    }
                    tmp = tmp->next;
                }
            }
            else
                head = head->next;
        }
        return Dummy->next;
    }
};
// @lc code=end

