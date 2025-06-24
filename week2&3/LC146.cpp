class LRUCache {
public:
class Node{
    public:
    Node* next;
    Node* prev;
    int key, val;
    Node(int k, int v){
        key = k;
        val = v;
        prev = next = NULL;
    }
};
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;  // storing next of head;
        head->next = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
        oldNext->prev = newNode;
        
    }

    void delNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;   // stores previous value of node which has to be deleted
        Node* oldNext = oldNode->next;   // stores next val of node which will be deleted
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {   // O(1)
        if(m.find(key) == m.end()){  //doesnot exist key
            return -1;
        }

        Node* ansNode = m[key];
        m.erase(key);             // to shift it top dele that node and then again add
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;
        return ansNode->val;
    }
    
    void put(int key, int value) {    // O(1)
        if(m.find(key) != m.end()){   // same key already present,now rewrite its val by delting its node and making new node
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);  // erase that key from map
        }
        // delete LRU
        if(m.size() == limit){  // capacity reached
            m.erase( tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
