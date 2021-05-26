/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL or headB == NULL) return NULL;
        int lenA = length(headA);
        int lenB = length(headB);

        while(lenA < lenB){
            lenB--;
            headB = headB->next;
        }
        while(lenB < lenA){
            lenA--;
            headA = headA->next;
        }
        while(headA !=  NULL and headB != NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;           
        }
        return NULL;
    }

    int length(ListNode* head){
        ListNode* cur = head;
        int len = 0;
        while(cur != NULL){
            len++;
            cur = cur->next;
        }
        return len;
    }
};
// @lc code=end

