/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        /*int left = leftHeight(root);
        int right = rightHeight(root);
        
        if(left == right) 
            return (1 << left) - 1; //满二叉树的个数为pow(2, h) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right); */

        int h = leftHeight(root);
        int low = pow(2, h - 1);
        int high = pow(2, h) - 1;
        while(low < high){
            int mid = high - (high - low)/2;
            if(hasK(root, mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
private:
    bool hasK(TreeNode* root, int K){
        vector<int> path;
        while(K > 0){
            path.push_back(K);
            K /= 2;
        }
        for(int i = path.size() - 1; i >= 0; --i){
            if(root == NULL) return false;
            if(i == 0) return true;
            if(path[i - 1] == 2 * path[i])
                root = root->left;
            else
                root = root->right;
        }
        return false;
    }

    int leftHeight(TreeNode* root){
        int res = 0;
        while(root != 0){
            res++;
            root = root->left;
        }
        return res;
    }
    int rightHeight(TreeNode* root){
        int res = 0;
        while(root){
            res++;
            root = root->right;
        }
        return res;
    }
};
// @lc code=end

