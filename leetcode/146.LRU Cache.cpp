//
// Created by gwengww on 5/11/18.
// beat 92.62%
// space complexity O(capacity)

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto search = hash.find(key);
        int result;
        if (search!=hash.end()) {
            result = search->second->val;
            if (hash.size() > 1) adjust(search->second);
            return result;
        }
        else return -1;
    }

    void put(int key, int value) {
        auto search = hash.find(key);
        if (search != hash.end()) {
            search->second->val = value;
            if (hash.size() > 1) adjust(search->second);
        } else {
            if (hash.size() == 0) {
                // empty hash
                head = new Node(key, value);
                hash[key] = head;
                tail = head;
            } else {
                tail->next = new Node(key, value);
                tail->next->prev = tail; // append a new tail
                tail = tail->next;
                hash[key] = tail;

                if (hash.size() > cap) {
                    // remove head;
                    head->next->prev = nullptr;
                    auto search = hash.find(head->key);
                    hash.erase(search);
                    auto temp = head;
                    head = head->next;
                    delete temp;  // prevent memory leak
                }
            }
        }
    }
private:
    struct Node {
        Node(int k, int v): val(v), key(k) {};
        Node* next;
        Node* prev;
        int val;
        int key;
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> hash;
    int cap;

    void adjust(Node* node) {
        if (node == tail) return;
        if (node == head) {
            head = node->next; // since size > 1, this is not nullptr
            tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            tail = tail->next;
            return;
        }
        tail->next = node;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = tail;
        tail = tail->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */