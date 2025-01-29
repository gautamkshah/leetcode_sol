class AllOne {
public:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* last;
    unordered_map<string, Node*> mp;

    // Add a new node with given count after prevNode
    void addnode(Node* prevNode, int count) {
        Node* newnode = new Node(count);
        newnode->next = prevNode->next;
        newnode->prev = prevNode;
        if (newnode->next != nullptr) {
            newnode->next->prev = newnode;
        }
        prevNode->next = newnode;
        if (prevNode == last) {
            last = newnode;
        }
    }

    // Delete a node from the doubly linked list
    void delnode(Node* node) {
        // Ensure node is not head or null
        if (node == nullptr || node == head) return;

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        if (last == node) {
            last = node->prev;
        }
        delete node;
    }

    // Constructor initializes the head and last pointers
    AllOne() {
        head = new Node(0);
        last = head;
    }

    // Increment the count of the given key
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            if (head->next == nullptr || head->next->count != 1) {
                addnode(head, 1);  // Add a new node with count 1
            }
            head->next->keys.insert(key);
            mp[key] = head->next;
        } else {
            Node* curnode = mp[key];
            int curcount = curnode->count;
            if (curnode->next == nullptr || curnode->next->count != curcount + 1) {
                addnode(curnode, curcount + 1);  // Add a new node with count+1
            }
            curnode->next->keys.insert(key);
            curnode->keys.erase(key);
            mp[key] = curnode->next;
            if (curnode->keys.empty()) {
                delnode(curnode);  // Delete node if no keys left
            }
        }
    }

    // Decrement the count of the given key
    void dec(string key) {
        Node* curnode = mp[key];
        int curcount = curnode->count;
        
        if (curcount == 1) {
            mp.erase(key);  // Remove key from map if count is 1
        } else {
            if (curnode->prev==head || curnode->prev->count != curcount - 1) {
                addnode(curnode->prev, curcount - 1);  // Add a new node with count-1
            }

            curnode->prev->keys.insert(key);
            mp[key] = curnode->prev;
        }
        curnode->keys.erase(key);
        if (curnode->keys.empty()) {
            delnode(curnode);  // Delete node if no keys left
        }
    }

    // Get the key with the maximum count
   string getMaxKey() {
    if (last == head || last->keys.empty()) {
        return "";  // Return an empty string if no keys
    }
    return *(last->keys.begin());  // Return the first key from the last node
}

string getMinKey() {
    if (head->next == nullptr || head->next->keys.empty()) {
        return "";  // Return an empty string if no keys
    }
    return *(head->next->keys.begin());  // Return the first key from the first non-head node
}

};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
