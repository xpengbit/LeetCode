/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* sortList(ListNode* head) {
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* cur = head;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        while(cur != NULL){
            pq.push(cur);
            cur = cur->next;
        }
        cur = Dummy;
        while(!pq.empty()){
            cur->next= pq.top();
            pq.pop();
            cur = cur->next;
        }
    cur->next = NULL;
    return Dummy->next;
    }
};
// @lc code=end

