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
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        if(mp[node]) return mp[node];
        Node* copyNode = new Node(node->val);
        mp[node] = copyNode;
        vector<Node*> ngLs;
        for(auto ngbr: node->neighbors) {
            Node* nNode = dfs(ngbr, mp);
            ngLs.push_back(nNode);
        }
        copyNode->neighbors = ngLs;
        return copyNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*, Node*> copyMap;
        return dfs(node, copyMap);
    }
};
