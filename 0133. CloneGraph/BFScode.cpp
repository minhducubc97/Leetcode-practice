class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<int, Node*> hashMap;
        hashMap[node->val] = new Node(node->val, {});
        queue<Node*> toDo;
        toDo.push(node);
        while (!toDo.empty()) {
            Node* curNode = toDo.front();
            toDo.pop();
            for (Node* n: curNode->neighbors) {
                if (hashMap.find(n->val) == hashMap.end()) {
                    hashMap[n->val] = new Node(n->val, {});
                    toDo.push(n);
                }
                hashMap[curNode->val]->neighbors.push_back(hashMap[n->val]);
            }
        }
        return hashMap[node->val];
    }
};