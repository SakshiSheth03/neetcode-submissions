class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    void remove(Node* node) {
        Node* afterNode = node->next;
        Node* beforeNode = node->prev;
        afterNode->prev = beforeNode;
        beforeNode->next = afterNode;
    }
    void insertAfterHead(Node* node) {
        Node* afterHead = head->next;
        afterHead->prev = node;
        node->next = afterHead;
        node->prev = head;
        head->next = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insertAfterHead(node);
        } else {
            if(cache.size()==cap) {
                Node* node = tail->prev;
                int oldKey = node->key;
                remove(node);
                cache.erase(oldKey);
            }
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            cache[key] = newNode;
        }
    }
};
