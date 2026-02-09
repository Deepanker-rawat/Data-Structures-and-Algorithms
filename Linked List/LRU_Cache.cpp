// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int key, int value){
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
};

class LRUCache {
    public:
        unordered_map<int, Node*> mp;
        int capacity;
        Node *head;
        Node* tail;
        
        void deleteNode(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        
        void insertAtFront(Node* node){
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
        
        
        LRUCache(int capacity){
            this->capacity = capacity;
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key){
            if(mp.find(key) == mp.end()){
                return -1;
            }
            
            Node* node = mp[key];
            deleteNode(node);
            insertAtFront(node);
            
            return node->value;
        }
        
        
        void put(int key, int value){
            // key already exists → delete old node
            if (mp.find(key) != mp.end()) {
                Node* old = mp[key];
                deleteNode(old);
                delete old;
                mp.erase(key);
            }
            // cache full → remove LRU
            else if (mp.size() == capacity) {
                Node* lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
    
            // insert new node
            Node* node = new Node(key, value);
            insertAtFront(node);
            mp[key] = node;
        }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10

    cache.put(3, 30);             // removes key 2

    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 30

    cache.put(4, 40);             // removes key 1

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 30
    cout << cache.get(4) << endl; // 40

    return 0;
}
    
