/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
        if(!root){
            out << "# ";
            return;
        }
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }
    TreeNode* deserialize(istringstream& in){
        string val;
        in >> val;
        if(val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};*/

/*class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL)
                res += "#,";
            else{
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);    
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        for(int i = 0; i < data.size(); ++i){
            int j = i;
            while(j < data.size() && data[j] != ',') ++j;
            string str = data.substr(i, j - i);
            if(str == "#")
                nodes.push_back(NULL);
            else
                nodes.push_back(new TreeNode(stoi(str)));
            
            i = j; //i走到","位置。 然后再++
        }

        int i = 0, j = 1;
        while(j < nodes.size()){
            if(nodes[i] != NULL){
                nodes[i]->left = nodes[j];
                nodes[i]->right = nodes[j + 1];
                j += 2;
            }
            i += 1;
        }
        return nodes[0];
    }
};*/

//recursion + DFS
/*class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        for(int i = 0; i < data.size(); ++i){
            int j = i;
            while(j < data.size() && data[j] != ',') ++j;
            string str = data.substr(i, j - i);
            if(str == "#")
                nodes.push_back(NULL);
            else
                nodes.push_back(new TreeNode(stoi(str)));
            
            i = j;
        }

        return dfs(nodes, 0);
    }

    TreeNode* dfs(vector<TreeNode*> nodes, int k){
        if(nodes[k] == NULL)  return NULL;
        TreeNode* root = nodes[k];
        TreeNode* left = dfs(nodes, k + 1);
        int leftNum = getNum(left);
        TreeNode* right = dfs(nodes, k + leftNum + 1);
        root->left = left;
        root->right = right;
        return root;
    }

    int getNum(TreeNode* root){
        if(root == NULL) return 1;
        return getNum(root->left) + getNum(root->right) + 1;
    }
};*/

//RECURSION + DFS + QUEUE
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        for(int i = 0; i < data.size(); ++i){
            int j = i;
            while(j < data.size() && data[j] != ',') ++j;
            string str = data.substr(i, j - i);
            q.push(str);

            i = j;
        }
        return dfs(q);
    }

    TreeNode* dfs(queue<string>& q){
        string str = q.front();
        q.pop();
        if(str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        TreeNode* left = dfs(q);
        TreeNode* right = dfs(q);
        root->left = left;
        root->right = right;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

