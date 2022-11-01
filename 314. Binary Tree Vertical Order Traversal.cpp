class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> Map;
        q.push({0, root}); 

        while(!q.empty()){
            auto [c, node] = q.front(); q.pop();
            Map[c].push_back(node->val);
            if(node->left) q.push({c - 1, node->left});
            if(node->right) q.push({c + 1, node->right});
        }

        for(auto m : Map)
            res.push_back(m.second);

        return res;
    }
};