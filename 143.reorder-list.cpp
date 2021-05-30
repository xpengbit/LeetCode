/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL) 
            return;
        ListNode* mid, *midHead;
        
        mid = findMid(head);
        midHead = reverse(mid->next);
        mid->next = NULL;
        merge(head, midHead);
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL and fast->next != NULL){
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

    void merge(ListNode* l1, ListNode* l2){
        ListNode* t1, *t2;
        while(l1!= NULL and l2 != NULL){
            t1 = l1->next;
            t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1;
            l2 = t2;        
        }
    }
};
// @lc code=end

