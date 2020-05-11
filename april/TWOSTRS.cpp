#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
class Node {
    public:
        Node *children[26];
        Node *link;
        int start;
        int *end;
        int suffixIndex;
    Node(int start, int *end, Node *link) {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        this->link = link;
        this->start = start;
        this->end = end;
        this->suffixIndex = -1;

    }
};

class SuffixTree {
    public:
        Node *root;
        Node *lastNewNode;
        Node *activeNode;
        int activeEdge;
        int activeLength;
        int remainingSuffixCount; 
        int leafEnd; 
        int *rootEnd; 
        int *splitEnd; 
        int size;
        SuffixTree() {
            root = NULL;
            lastNewNode = NULL;
            activeNode = NULL;
            activeEdge = -1;
            activeLength = 0;
            remainingSuffixCount = 0;
            leafEnd = -1;
            rootEnd = NULL;
            splitEnd = NULL;
            size = -1;
        }
}


bool cmp(pair<string,int> &l, pair<string,int> &r) {
    return l.second>r.second;
}

int computeCost(string &s, vector<pair<string,int>> &fav) {
    Trie *t = new Trie();
    for(int i=0;i<s.length();i++) {
        t->insertString(s.substr(i));
    }
    int cost = 0;
    for(int i = 0;i<fav.size();i++) {
        cost = cost + fav[i].second * t->countString(fav[i].first);
    }
    return cost;
}

void solve() {
    string A,B;
    cin>>A>>B;
    int N;
    cin>>N;
    vector<pair<string,int>> fav(N);
    for(int i = 0;i<N;i++) {
        string s;
        int b;
        cin>>s>>b;
        fav[i] = {s,b};
    }
    // sort(fav.begin(), fav.end(),cmp);
    int max_cost = 0;
    int an = A.length();
    int bn = B.length();
    for(int i=an;i>=1;i--) {
        for(int j=0;j<bn;j++) {
            string cur = A.substr(0,i)+B.substr(j);
            int curCost = computeCost(cur,fav);
            max_cost = max(max_cost,curCost);
        }
    }
    cout<<max_cost<<"\n";
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}

