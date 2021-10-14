/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*Recursive Solution*/
        if(p == NULL and q == NULL) return true;
        else if(p == NULL or q == NULL or p->val != q->val) return false;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);

        /*Iterative Solution*/
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while(!s.empty()){
            q = s.top(); s.pop();
            p = s.top(); s.pop();
            if(!p && !q) continue;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            
            s.push(p->right); s.push(q->right);
            s.push(p->left); s.push(q->left);
        }
        return true;            
    }
};
// @lc code=end

