/*
 * @lc app=leetcode id=428 lang=cpp
 *
 * [428] Serialize and Deserialize N-ary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     vector<TreeNode*> children;
 *     TreeNode(int x) : val(x){}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);        
    }
private:
    void serialize(TreeNode* root, ostringstream& out){
        if(!root) return;
        out << root->val << ' ';
        out << root->children.size() << ' ';
        for(auto child : root->children){
            serialize(child, out);    
        }
    }

    TreeNode* deserialize(istringstream& in){
        string val;
        string num;
        in >> val;
        TreeNode* root = new TreeNode(stoi(val));
        in >> num;
        for(int i = 0; i < stoi(num); i++){
            root->children.push_back(deserialize(in));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end