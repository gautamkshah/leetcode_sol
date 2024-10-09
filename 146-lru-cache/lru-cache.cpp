class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* left;
        Node* right;
        Node(int keys, int values) {
            key = keys;
            value = values;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* last = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int sz = 0;
    int cap;

    void insertAtHead(int key, int value) {
        Node* newnode = new Node(key, value);
        newnode->right = head->right;
        head->right->left = newnode;
        head->right = newnode;
        newnode->left = head;
    }

    void deletenode() {
        last->left->left->right = last;
        last->left = last->left->left;
        cout << last->left->value << endl;
    }

    LRUCache(int capacity) {
        head->right = last;
        last->left = head;
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        Node* cur = mp[key];
        int val = cur->value;
        cur->left->right = cur->right;
        cur->right->left = cur->left;
        insertAtHead(key, val);
        mp[key] = head->right;
        return cur->value;
    }

    void put(int key, int value) {

        if (mp.find(key) == mp.end()) {
            if (sz >= cap) {
                int keys = last->left->key;
                mp.erase(keys);
                deletenode();
            }
            insertAtHead(key, value);
            mp[key] = head->right;
            sz++;
        } else if (mp.find(key) != mp.end()) {
            Node* cur = mp[key];
            cur->left->right = cur->right;
            cur->right->left = cur->left;
            insertAtHead(key, value);
            mp[key] = head->right;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */