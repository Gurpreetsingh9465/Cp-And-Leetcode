#include<bits/stdc++.h>
using namespace std;

class Trie {
    private:
        class TrieNode {
            unordered_map<char, TrieNode*> *children;
            bool endOfWord;
            public: 
            TrieNode() {
                this->children = new unordered_map<char, TrieNode*>();
                this->endOfWord = false;
            }
            int getLength() {
                return this->children->size();
            }
            void setEndOfWord(bool endOfWord) {
                this->endOfWord = endOfWord;
            }
            bool getEndOfWord() {
                return this->endOfWord;
            }
            TrieNode *insert(char c, bool isEndOfWord = false) {
                if(this->children->find(c) == this->children->end()) {
                    TrieNode *newNode = new TrieNode();
                    this->children->insert({c, newNode});
                    newNode->setEndOfWord(isEndOfWord);
                    return newNode;
                }
                this->children->find(c)->second->setEndOfWord(isEndOfWord);
                return this->children->find(c)->second;
            }
            TrieNode *find(char c) {
                if(this->children->find(c) != this->children->end()) {
                    return this->children->find(c)->second;
                }
                return NULL;
            }
        };
        TrieNode *root;
    public:
        Trie() {
            root = new TrieNode();
        }
        void insertString(string s) {
            TrieNode *curNode = this->root;
            for(int i=0;i<s.length();i++) {
                curNode = curNode->insert(s[i]);
                if(i == s.length()-1)
                    curNode->setEndOfWord(true);
            }
        }
        bool findString(string s) {
            TrieNode *curNode = this->root;
            for(int i=0;i<s.length();i++) {
                curNode = curNode->find(s[i]);
                if(curNode == NULL)
                    return false;
            }
            return curNode->getEndOfWord();
        }

        int matches(string s) {
            TrieNode *curNode = this->root;
            for(int i=0;i<s.length();i++) {
                curNode = curNode->find(s[i]);
                if(curNode == NULL)
                    return 0;
            }
            return curNode->getLength();
        }
};


int main() {
    Trie *t = new Trie();
    vector<string> s = {"aman","am", "yolo", "aditya", "harsh","harshbansal","kartik","gulshan"};
    for(auto i: s) {
        t->insertString(i);
    }
    cout<<t->findString("aman")<<endl;
    cout<<t->findString("am")<<endl;
    cout<<t->findString("ekansh")<<endl;
    cout<<t->findString("har")<<endl;
    cout<<t->matches("am")<<endl;
    cout<<t->matches("yo")<<endl;
    cout<<t->matches("ek")<<endl;
    return 0;
}