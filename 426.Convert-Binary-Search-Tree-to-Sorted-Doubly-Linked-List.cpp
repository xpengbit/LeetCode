/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
       /*Iterative solution*/
       /* if(root == NULL) return NULL;
        Node* first = NULL;
        Node* pre = NULL;
        stack<Node*> s;
        while(root != NULL or !s.empty()){
            while(root != NULL){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(first = NULL) first = root;
            if(pre != NULL){
                pre->right = root;
                root->left = pre;
            }
            pre = root;
            root = root->right;
        }
        first->left = pre;
        pre->right = first;
        return first;*/

        /*Recurtive solution*/
        if(root == NULL) return root;

    }
private:
    Node* pre = NULL, *head = NULL;
    void inorderTraversal(Node* root){
        if(root == NULL) return;
        inorderTraversal(root->left);
        if(head == NULL) head = root;
        if(pre != NULL){
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        inorderTraversal(root->right);
    }
};
