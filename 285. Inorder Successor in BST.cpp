/*Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.*/
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //Recursion solution
        if(!p) return NULL;
        inorder(root, p);
        return nxt;
    }
    
    void inorder(TreeNode* root, TreeNode* p){
        if(!root) return;
        inorder(root->left, p);
        if(pre == p) nxt = root;
        pre = root;
        indorder(root->right, p);
    }
    
private:
    TreeNode* pre = NULL, *nxt = NULL;
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //中序遍历iteration写法
        stack<TreeNode*> s;
        bool b = false;
        TreeNode* cur = root;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top(); s.pop();
            if(b == true) return cur;
            if(cur == p) b = true;
            cur = cur->right;
        }
        return NULL;
    }
};