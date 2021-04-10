/*

 Question : https://leetcode.com/problems/clone-graph/

 Approach : Traverse each non-visited vertices/nodes of a graph and clone the nodes one by one. Also clone the neighbors from the original graph.

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
    Node* bfs(Node* src){
        queue<Node*> q;
        q.push(src);
        Node* n = new Node(src->val);
        
        map<Node*, Node*> mp;        //used for tracking the visited nodes
        mp[src] = n;
        
        while(!q.empty()){
            Node *u = q.front();
            q.pop();
            vector<Node*> v = u->neighbors;
            int n = v.size();
            for(int i = 0; i < n; i++){
                if(mp[v[i]] == NULL){
                    Node* node = new Node(v[i]->val);
                    q.push(v[i]);
                    mp[v[i]] = node;
                }
                mp[u]->neighbors.push_back(mp[v[i]]);
            }
        }
        return mp[src];
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
       return bfs(node);
    }
};
