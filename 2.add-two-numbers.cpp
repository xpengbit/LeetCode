/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
        ListNode* Dummy = new ListNode(0);
        ListNode* cur = Dummy; 
        int carrier = 0;
        
        while(l1 != NULL or l2 != NULL or carrier == 1){
            int sum = carrier;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carrier = sum / 10;
        }

        return Dummy->next;
        /*while( l1 != nullptr and l2 != nullptr){
            int tmp = l1->val + l2->val + carrier;
            carrier = tmp / 10;
            ListNode* newNode = new ListNode(tmp%10);
            root->next = newNode;
            root = root->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l2 != nullptr){
            int tmp = l2->val + carrier; 
            carrier = tmp / 10;
            ListNode* newNode = new ListNode(tmp%10);
            root->next = newNode;
            root = root->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            int tmp = l1->val + carrier; 
            carrier = tmp / 10;
            ListNode* newNode = new ListNode(tmp%10);
            root->next = newNode;
            root = root->next;
            l1 = l1->next;
        }
        if(carrier != 0){
            ListNode* newNode = new ListNode(carrier);
            root->next = newNode;
            root = root->next;
        }
        return Dummy->next;*/    
    }
};
// @lc code=end

