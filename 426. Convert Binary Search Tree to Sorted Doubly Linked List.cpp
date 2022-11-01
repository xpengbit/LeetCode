class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node* pre = NULL, head = NULL;
        stack<Node*> s;

        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }

            if(!head) head = root;
            if(pre){
                pre->right = root;
                root->left = pre;
            }
            pre = root;
            root = root->right;
        } 

        head->right = pre;
        pre->left = head;

        return head;
    }
};