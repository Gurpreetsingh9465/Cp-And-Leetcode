#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    class Node {
        public:
            int val;
            int key;
            Node *next;
            Node *prev;
            Node(int val, int key) {
                this->val = val;
                this->key = key;
                next = NULL;
                prev = NULL;
            }
    };
    Node *start, *end;
    map<int,Node*> m;
    int current;
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            start = NULL;
            end = NULL;
            current = 0;
        }

        int getCurrent() {
            return current;
        }

        int getCap() {
            return capacity;
        }
    
        void insertNode(int val, int key) {
            Node *node = new Node(val,key);
            if(start == NULL) {
                start = node;
                end = node;
            } else {
                start->prev = node;
                node->next = start;
                start = node;
            }
            current+=1;
        }

        void deleteNode(Node * node) {
            if(node == start && node == end) {
                start = NULL;
                end = NULL;
                delete node;
                current -= 1;
                return;
            }
            if(node == start) {
                Node *temp = node;
                start = node->next;
                start->prev = NULL;
                delete temp;
            } else if(node == end) {
                Node *temp = node;
                end = node->prev;
                end->next = NULL;
                delete temp;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete node;
            }
            current-=1;

        }

        int get(int key) {
            if(m.find(key) == m.end()) {
                return -1;
            }
            Node *node = m[key];
            int val = node->val;
            deleteNode(node);
            insertNode(val, key);
            m[key] = start;
            return val;
        }

        void put(int key, int value) {
            if(m.find(key) != m.end()) {
                deleteNode(m[key]);
                insertNode(value, key);
                m[key] = start;
            } else {
                if(current == capacity) {
                    m.erase(end->key);
                    deleteNode(end);
                    insertNode(value, key);
                    m[key] = start;
                } else {
                    insertNode(value, key);
                    m[key] = start;
                }
            }
            
        }
};

int main() {
//     ["LRUCache","put","get","put","get","get"]
// [[1],[2,1],[2],[3,2],[2],[3]]
    LRUCache l(1);
    l.put(2,1);
    cout<<l.get(2)<<endl;
    l.put(3,2);
    cout<<l.get(2)<<endl;
    cout<<l.get(3)<<endl;
}