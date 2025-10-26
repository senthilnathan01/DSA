/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

LINK: https://leetcode.com/problems/lru-cache/description/?envType=problem-list-v2&envId=55vr69d7
*/

class LRUCache {
public:
    class Node{
        public: 
            int key, value;
            Node *next, *prev;
            Node(int key, int value){
                this -> key = key;
                this -> value = value;
                next = NULL;
                prev = NULL;
            }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;   
    }

    void deleteNode(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insert(Node *node){
        // always insert new node after head (-1, -1)
        // as it is recently used
        Node *temp = head->next;
        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            Node *curr = mp[key];
            // make it as recently used just by deleting and inserting
            deleteNode(curr);
            insert(curr);

            return curr->value;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            // update the value
            Node *curr = mp[key];
            curr->value = value;
            
            // make it as recently used
            deleteNode(curr);
            insert(curr);
        }
        else{
            Node *newNode = new Node(key, value);
            if(mp.size()==capacity){
                Node *todelete = tail->prev;
                mp.erase(todelete->key);
                deleteNode(tail->prev);
                delete todelete;

                insert(newNode);
                mp[key] = newNode;
            }
            else{
                insert(newNode);
                mp[key]=newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
