/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverse(firstHalfEnd->next);
        ListNode* l1 = head;
        ListNode* l2 = secondHalfStart;
        bool res = true;
        while(res and l2 != NULL){
            if(l1->val != l2->val) res = false;
            l1 = l1->next;
            l2 = l2->next;
        }
        firstHalfEnd->next = reverse(secondHalfStart);
        return res;
    }
    
    ListNode* endOfFirstHalf(ListNode* head){
        ListNode* fast = head, *slow = head;
        while(fast->next != NULL and fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;

        while(head != NULL){
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
// @lc code=end

