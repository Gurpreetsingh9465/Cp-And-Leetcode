#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>> graph, int start, unordered_set<int> *visited, vector<int> *ans) {
    if(visited->find(start) != visited->end()) {
        return;
    }
    ans->push_back(start);
    visited->insert(start);
    for(auto &i: graph[start]) {
        dfs(graph, i, visited, ans);
    }
}

bool isDirected(vector<vector<int>> &connected,unordered_map<int,vector<int>> &graph) {
    // for(int i = 1; i<=n; i++){
    //     if(!visited[i]){
    //     cnt = 0;
    //     dfs(i);
    //     ans+= cnt*(cnt-1)/2ll;
    //     }
    // }
    for(auto &i: connected) {
        int X = i.size()-1;
        for(auto &j: i) {
            if(graph[j].size() != X) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin>>n>>m;
    unordered_map<int,vector<int>> graph;
    for(int i = 0;i<m;i++) {
        int first, second;
        scanf("%d %d", &first, &second);
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    vector<vector<int>> connected;
    unordered_set<int> *s = new unordered_set<int>();
    for(int i = 1;i<=n;i++) {
        if(s->find(i) == s->end()) {
            vector<int> *d = new vector<int>();
            dfs(graph, i, s, d);
            vector<int> inter(d->size());
            for(int i = 0;i<d->size();i++) {
                inter[i] = (d->at(i));
            }
            connected.push_back(inter);
            delete d;
        }
    }

    bool ans = isDirected(connected, graph);
    if(ans) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    cout<<endl;
}