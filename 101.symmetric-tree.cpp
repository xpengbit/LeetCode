/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
       /* queue<TreeNode*> q1, q2;
        q1.push(root);
        q2.push(root);
        while(!q1.empty() and !q2.empty() ){
            TreeNode* l = q1.front();
            TreeNode* r = q2.front();
            q1.pop();
            q2.pop();
            if(l == NULL and r == NULL)
                continue;
            if(l == NULL or r == NULL)
                return false;
            if(l->val != r->val)
                return false;
            q1.push(l->left);
            q1.push(l->right);
            q2.push(r->right);
            q2.push(r->left);
        }
        return true;*/
        return helper(root->left, root->right);
    }
/*Recursion method*/    
private:
    bool helper(TreeNode* p, TreeNode* q){
        if(p == NULL and q == NULL)
            return true;
        else if(p == NULL or q == NULL or p->val != q->val)
            return false;
        
        return helper(p->left, q->right) and helper(p->right, q->left);
    }
};
// @lc code=end

