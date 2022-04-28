/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        if(k == 0) return {target->val};

        unordered_map<TreeNode*, TreeNode*> Map;
        unordered_set<TreeNode*> visited;
        vector<int> res;

        findFather(root, Map);
        helper(target, k, Map, visited, res);
        return res;   
    }
    
    void findFather(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& Map){
        if(!node) return;
        if(node->left) Map[node->left] = node;
        if(node->right) Map[node->right] = node;
        findFather(node->left, Map);
        findFather(node->right, Map);
    }

    void helper(TreeNode* node, int k, unordered_map<TreeNode*, TreeNode*> Map, unordered_set<TreeNode*>& visited, vector<int>& res){
        if(!node) return;
        if(visited.count(node)) return;
        visited.insert(node);
        if(k == 0) res.push_back(node->val);
        if(node->left) helper(node->left, k - 1, Map, visited, res);
        if(node->right) helper(node->right, k - 1, Map, visited, res);
        if(Map[node]) helper(Map[node], k - 1, Map, visited, res);
    }
    
    void findFather2(TreeNode* node, TreeNode* pre, unordered_map<TreeNode*, vector<TreeNode*>> adj){
        if(!node) return;
        if(adj.count[node]) return;
        if(pre){
            adj[node].push_back(pre);
            adj[pre].push_back(node);
        }
        findFather2(node->left, node, adj);
        findFather2(node->right, node, adj);
    }
};
// @lc code=end
//这个题主要是如何找到父节点然后再向外找。需要建立一个父节点的映射。

