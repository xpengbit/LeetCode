/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* Dummy = new ListNode(0);
        Dummy->next = head;
        ListNode* cur;
        int prefix = 0;
        unordered_map<int, ListNode*> mp;
        
        /*prefix sum 中相同value的两个节点间的subarray 的sum一定为0
         在第一遍扫描保存最后一个相同的value，这样在下面第二次扫描，直接把
         指针指向相同value的next，跳过和为0的元素
         0,1,2,3,-2,-3,9
         ----------------
         0,1,3,6, 4, 1,10
         两个1之间的和为0， 在map中保存后一个1的LinkNode， 在第二次扫描1->next 指向9*/
        for(cur = Dummy; cur != NULL; cur = cur->next){
            prefix += cur->val;
            mp[prefix] = cur;
        }

        prefix = 0;
        for(cur = Dummy; cur != NULL; cur = cur->next){
            prefix += cur->val;
            cur->next = mp[prefix]->next;
        }
        return Dummy->next;
    }
};
// @lc code=end

