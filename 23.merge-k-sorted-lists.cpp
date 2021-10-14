/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
 *
 * /
 /* Solution use PQ*/ 
/*class Solution {
public:
    struct compare{
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* Dummy = new ListNode(-1);
        ListNode* cur = Dummy;
        /*auto comp = [](ListNode* x, ListNode* y){
            return x->val > y->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        */
/*        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto it : lists){
            if(it)  pq.push(it);
        }

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if(pq.empty()) break;
            if(node->next != NULL)
                pq.push(node->next); 
        }
        return Dummy->next;
    }
};*/


/*Solution use Divid and Conquer*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partion(lists, 0, lists.size() - 1); 
    }

    ListNode* partion(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];

        if(start < end){
            int mid = start + (end - start)/2;
            ListNode* l = partion(lists, start, mid);
            ListNode* r = partion(lists, mid + 1, end);
            return merge(l, r);
        } 
        return NULL;
    }

    ListNode* merge(ListNode* l, ListNode* r){
        if(l == NULL) return r;
        if(r == NULL) return l;
        if(l->val < r->val){ 
            l->next = merge(l->next, r);
            return l;
        }
        else{
            r->next = merge(l, r->next);
            return r;
        }
    }
};
// @lc code=end

