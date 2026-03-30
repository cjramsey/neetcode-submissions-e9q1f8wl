/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cache;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        if (cache.contains(head)) {
            return cache[head];
        }
        Node* new_node_ptr = new Node(head->val);
        cache[head] = new_node_ptr;
        new_node_ptr->next = copyRandomList(head->next);
        new_node_ptr->random = copyRandomList(head->random);
        return new_node_ptr;
    }
};
