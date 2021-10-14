/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*Recursive Solution*/
        /*if(root ==  NULL) return NULL;
        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = root->next ?  root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;*/

        /* BFS*/
        /*queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                Node* tmp = q.front();
                q.pop();
                if(i == sz-1) tmp->next = NULL;
                else tmp->next = q.front();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return root;*/
        /*Iterative Solution*/
        if(!root) return NULL;
        Node* start = root, *cur = NULL;
        while(start->left){
            cur = start;
            while(cur){
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : NULL;
                cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
};
// @lc code=end

