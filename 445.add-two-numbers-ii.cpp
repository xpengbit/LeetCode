/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* res = NULL;
        int carrier = 0;
        while(!s1.empty() or !s2.empty() or carrier != 0){
            int val1 = s1.empty() ? 0 : s1.top();
            int val2 = s2.empty() ? 0 : s2.top();
            int sum = val1 + val2 + carrier;
            ListNode* cur = new ListNode(sum % 10);
            carrier = sum/10;
            cur->next = res;
            res = cur;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
        }
        return res;
    }
};
// @lc code=end

