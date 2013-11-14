/*
 * Design and implement a data structure for Least Recently Used (LRU) cache. 
 * It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key 
 * exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present.  
 * When the cache reached its capacity, it should invalidate the least recently used 
 * item before inserting a new item.
 */

// First solution: using STL list 
class LRUCache{
    int cap;
    bool cache_full;
    list< pair<int, int> > freq_queue;   // pair<key, val>
    unordered_map<int, list< pair<int, int> >::iterator> cache;
    
    void update_cache(int key, int value) {
        freq_queue.erase(cache[key]);  // O(1)
        freq_queue.push_back(pair<int, int>(key, value));
        auto it = freq_queue.end();
        cache[key] = --it;
    }
    
public:
    LRUCache(int capacity) {
        if (capacity <= 0) {
            cap = 10;
        }
        cap = capacity;
        cache_full = false;
    }
    
    int get(int key) {  
        auto it = cache.find(key);
        
        if (it != cache.end()) {
            int value = cache[key]->second;
            update_cache(key, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {  
        if (get(key) != -1) {
            update_cache(key, value);
        } else {
            if (cache_full) {
                int lru_key = freq_queue.front().first;
                freq_queue.erase(freq_queue.begin()); // O(1)
                freq_queue.push_back(pair<int, int>(key, value));
                cache.erase(lru_key);
                auto it = freq_queue.end();
                cache[key] = --it;
            } else {
                freq_queue.push_back(pair<int, int>(key, value));
                auto it = freq_queue.end();
                cache[key] = --it;
                if (freq_queue.size() == cap) {
                    cache_full = true;
                }
            }
        }
    }
};

// second solution: using home made doubly linked list
class LRUCache{
    int cap;
    bool cache_full;
    
    struct Node {
        int val;
        int key;
        Node *prev, *next;
        Node(int k, int v, Node *p = nullptr, Node *n = nullptr) 
            : val(v), key(k), prev(p), next(n) {
            
        }
    };
    
    class LinkedList {
        int num;
        Node *begin, *end;
    public:
        LinkedList() : num(0) {
            begin = end = nullptr;
        }
        
        int size() {
            return num;
        }
        
        Node* get_begin() {
            return begin;
        }
        
        Node* push_back(int key, int value) {
            Node *n = new Node(key, value);
            
            if (num == 0) {
                begin = n;
                end = n;
                num++;
            } else {
                n->prev = end;
                end->next = n;
                end = n;
                num++;
            }
            
            return n;
        }
        
        void remove(Node *n) {
            if (num == 0) {
                return;
            }
            
            if (n->prev != nullptr) {
                n->prev->next = n->next;
            } else {
                begin = n->next;
            }
            if (n->next != nullptr) {
                n->next->prev = n->prev;
            } else {
                end = n->prev;
            }
            
            delete n;
            num--;
        }
    };
 
    LinkedList freq_queue;   // pair<key, val>
    unordered_map<int, Node *> cache;
public:
    LRUCache(int capacity) {
        if (capacity <= 0) {
            cap = 10;
        }
        cap = capacity;
        cache_full = false;
    }
    
    int get(int key) {  
        auto it = cache.find(key);
        
        if (it != cache.end()) {
            int value = cache[key]->val;
            freq_queue.remove(cache[key]);  // O(1)
            cache[key] = freq_queue.push_back(key, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {  
        if (get(key) != -1) {
            freq_queue.remove(cache[key]);  // O(1)
            cache[key] = freq_queue.push_back(key, value);
        } else {
            if (cache_full) {
                int lru_key = freq_queue.get_begin()->key;
                freq_queue.remove(freq_queue.get_begin()); // O(1)
                cache[key] = freq_queue.push_back(key, value);
                cache.erase(lru_key);
            } else {
                cache[key] = freq_queue.push_back(key, value);
                if (freq_queue.size() == cap) {
                    cache_full = true;
                }
            }
        }
    }
};