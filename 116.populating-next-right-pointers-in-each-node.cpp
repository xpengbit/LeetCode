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
        if(root ==  NULL) return NULL;
        helper(root);
        return root;

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
    }
private:
    void helper(Node* root){
        if(root->left == NULL and root->right == NULL) return;
        if(root->next and root->right)
            root->right->next = root->next->left;
        root->left->next = root->right;
        helper(root->left);
        helper(root->right);
    }
};
// @lc code=end

