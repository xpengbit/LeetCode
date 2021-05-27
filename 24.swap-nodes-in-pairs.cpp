/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        int k = 2;
        int count = 0;
        ListNode* cur = head;
        while(count < k){
            if(cur == NULL ) return head;
            cur = cur->next;
            count++;
        }
        ListNode* pre = swapPairs(cur);
        return reverse(head, pre, k);        
    }

    ListNode* reverse(ListNode* head, ListNode* pre,int k){
        while(k > 0){
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
            k--;
        }
        return pre;
    }
};
// @lc code=end

