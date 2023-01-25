//Add every unvisited node to the clone
//Time Complexity -> O(nlogn)
//Complexity can be O(n) is unordered map is used
//Memory Complexity -> O(n)

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

class Solution
{
public:
    map<Node*,Node*> m;
    Node* cloneGraph(Node* node)
    {
        if(node == NULL) return NULL;
        if(m.find(node) == m.end())
        {
            m[node] = new Node(node -> val, {});
            int s = node->neighbors.size();
            for(int i=0;i<s;i++)
                m[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return m[node];
    }
};