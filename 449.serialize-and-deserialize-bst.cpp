/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
/*class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialize(root, s);
        return s;    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
    }

private:
    void serialize(TreeNode* root, string& s){
        if(root == NULL) return;
        s.append(reinterpret_cast<const char*>(& root->val)); 
        if(root->left) out << ' '<< serialize(root->left, out);
        if(root->right) out << ' '<< serialize(root->right, out);
    }

    TreeNode* deserialize(const string& s, int& pos, int curMin, int curMax){
        if(pos >= s.size()) return nullptr;
        int val = *reinterpret_cast<const int *>(s.data() + pos);
        if(val < curMin or val > curMax) return nullptr;
        pos += sizeof(val);
        TreeNode* root = new TreeNode(val);
        root->left = deserialize(s, pos, curMin, val);
        root->right = deserialize(s, pos, val, curMax);
        return root;
    }
};*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root, os);
        return os.str();    
    }

    void serialize(TreeNode* root, ostringstream& os){
        if(!root) os << "# ";  //注意这里后面跟了个空格
        else{
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }


    TreeNode* deserialize(istringstream& is){
        string str = " ";
        is >> str;
        if(str == "#") return NULL;
        int n = stoi(str);
        TreeNode* node = new TreeNode(n);
        node->left = deserialize(is);
        node->right = deserialize(is);
        
        return node;
    }        
};


// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

