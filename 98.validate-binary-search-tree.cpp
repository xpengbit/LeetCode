/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    /*vector<int> vi;*/
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        //return dfs(root, LONG_MIN, LONG_MAX);
        
        /*bool res = true;
        in_order(root);
        for(int i = 1; i < vi.size(); i++){
            if(vi[i-1] > vi[i]){
                res = false;
                break;
            }
        }
        return res;*/
        if(root == NULL) return true;
        bool left = isValidBST(root->left);
        if(!left) return false;
        if(pre >= root->val) return false;
        pre = root->val;
        return isValidBST(root->right);
    }
private:
    bool dfs(TreeNode* root, long int min_node, long int max_node){
        if(root == NULL) return true;

        return (root->val > min_node) and (root->val < max_node ) and dfs(root->left,min_node, root->val) && dfs(root->right,root->val, max_node);
    }

    /*void in_order(TreeNode* root){
        if(root == NULL) return;
        in_order(root->left);
        vi.push_back(root->val);
        in_order(root->right);
    }*/
};
// @lc code=end

