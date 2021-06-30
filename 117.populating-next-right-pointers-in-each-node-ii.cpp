/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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
        if(!root) return NULL;
        Node* parent = root;
        Node* childHead = NULL;
        Node* child = NULL;
        while(parent != NULL){
            while(parent != NULL){
                if(parent->left != NULL){
                    if(childHead == NULL){
                        childHead = parent->left;
                    }
                    else{
                        child->next = parent->left;
                    }
                    child = parent->left;
                }
                if(parent->right != NULL){
                    if(childHead == NULL){
                        childHead = parent->right;
                    }
                    else{
                        child->next = parent->right;
                    }
                    child = parent->right;
                }
                parent = parent->next;
                }
                parent = childHead;
                childHead = NULL;
                child = NULL;
            }
        return root;    
    }
/*private:
    void helper(Node* root){
        if(!root->left and !root->right) return;
        if(root->right == NULL) root->left->next = NULL;
        if(root->right and root->next) root->right->next = root->next->left;
        if(root->left and root->right) root->left->next = root->right;
        helper(root->left);
        helper(root->right);
    }*/
};
// @lc code=end

