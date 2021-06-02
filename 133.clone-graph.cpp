/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* clone_node = new Node(node->val);
        vector<Node*> visited(101, NULL);
        visited[node->val] = clone_node;
        queue<Node*> q;
        q.push(node);
        BFS(q, visited);
        return clone_node; 
    }
private:
    /*BFS solution*/
    void BFS(queue<Node*>& q, vector<Node*>& visited){
        while (!q.empty())
        {
            Node* tmp = q.front();
            q.pop();
            for(Node* n : tmp->neighbors){
                if(visited[n->val] == NULL){
                    Node* clone = new Node(n->val);
                    visited[tmp->val]->neighbors.push_back(clone);
                    visited[n->val] = clone;
                    q.push(n);
                }
                else{
                    visited[tmp->val]->neighbors.push_back(visited[n->val]);
                }
            }
        }
    }

    /*DFS solution*/
    void DFS(Node* node, Node* clone_node, vector<Node*>& visited){
        visited[node->val] = clone_node;
        for(Node* x : node->neighbors){
            if(visited[x->val] == NULL){
                Node* clone = new Node(x->val);
                clone_node->neighbors.push_back(clone);
                DFS(x, clone, visited);
            }
            else{
                clone_node->neighbors.push_back(visited[x->val]);
            }
        }
    }
};
// @lc code=end

