/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*Node* cur = head;
        unordered_map<Node*, Node*> mp;
        while(cur !=  NULL){
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        for(cur = head; cur != NULL; cur = cur->next){
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
        }
        return mp[head];*/
        if(!head) return NULL;
        unordered_map<Node*, Node*> Map;
        Node* cur = head;
        while(cur){
            Map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        for(cur = head; cur; cur = cur->next){
            Map[cur]->next = Map[cur->next];
            Map[cur]->random = Map[cur->random];
        }

        return Map[head];
    }
};
// @lc code=end

