/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
/*class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL or k == 0) return head;
        int len = length(head);
        len = k % len;
        for(int i = 0; i < len; i++){
            head = deleteTail(head);
        } 
        return head;
    }
    ListNode* deleteTail(ListNode* head){
        ListNode* cur = head;
        while(cur->next->next != NULL)
            cur = cur->next;
        ListNode* ptr = cur->next;
        cur->next = NULL;
        ptr->next = head;
        head = ptr;
        return head;
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
};*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* cur = head;
        int n = 1;
        while(cur->next){
            cur = cur->next;
            n++;
        }

        k %= n;
        if(k == 0) return head;
        
        ListNode* fast = head, *slow = head;
        for(int i = 0; i < k; ++i){
            fast = fast->next;
        }
        if(!fast) return head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* newHead = slow->next;
        slow->next = NULL;
        fast->next = head;

        return newHead;
    }
};
// @lc code=end

