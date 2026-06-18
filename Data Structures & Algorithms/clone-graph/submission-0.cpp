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

    Node* dfs(Node* node,unordered_map<int,Node*> &newNodes){
        if(node == NULL) return NULL;
        Node* copyNode = new Node(node->val);
        newNodes[node->val] = copyNode;

        for(auto x : node->neighbors){
            if(newNodes.find(x->val) == newNodes.end()){
                copyNode->neighbors.push_back(dfs(x,newNodes));
            }else{
                copyNode->neighbors.push_back(newNodes[x->val]);
            }
        }

        return copyNode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> newNodes;
        return dfs(node,newNodes);
    }
};
