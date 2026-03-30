class LRUCache {
public:
    LRUCache(int capacity)
        : cur_capacity{0}
        , max_capacity{capacity}
        , left{new ListNode(-1, -1, nullptr, nullptr)}
        , right{new ListNode(-1, -1, nullptr, nullptr)}
    {
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (keys.contains(key)) {
            int res = keys[key]->val;
            insert_right(remove_node(keys[key]));
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keys.contains(key)) {
            keys[key]->val = value;
            insert_right(remove_node(keys[key]));
        }
        else {
            ListNode* ptr = new ListNode(key, value, nullptr, nullptr);
            insert_right(ptr);
            keys[key] = ptr;
            ++cur_capacity;
            if (cur_capacity > max_capacity) {
                ListNode* node = remove_node(left->next);
                keys.erase(node->key);
                delete node;
                --cur_capacity;
            }
        }
    }
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int k, int v, ListNode* n, ListNode* p) : key(k), val(v), next(n), prev(p) {}
    };
    ListNode* left; // LRU
    ListNode* right; // MRU
    const int max_capacity;
    int cur_capacity;
    unordered_map<int, ListNode*> keys;

    void insert_right(ListNode* node) {
        ListNode* prev_MRU = right->prev;
        node->next = right;
        node->prev = prev_MRU;
        prev_MRU->next = node;
        right->prev = node;
    }

    ListNode* remove_node(ListNode* node) {
        ListNode* prev = node->prev;
        node->prev->next = node->next;
        node->next->prev = prev;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }
};