#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int ans = INT_MAX;

string num_to_bin[19] = {"0","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010"};

bool isSorted(vector<int> p) {
    for(int i = 1;i<p.size();i++) {
        if(p[i] != i)
            return false;
    }
    return true;
}

string vecToString(vector<int> &p) {
    string ans = "";
    for(int i=1;i<p.size();i++) {
        ans += num_to_bin[p[i]];
    }
    return ans;
}


int findCost(vector<int> p,int n, int **canSwap) {
    int i = 1;
    int cost = 0;
    while (i<n) {
        if(p[i] == i) {
            i++;
            continue;
        }
        int i1 = i;
        while (p[i1] != i1) {
            int i2 = p[i1];
            swap(p[i1], p[i2]);
            cost+=canSwap[i1][i2];
        }
    }
    return cost;
}

unordered_set<string> visited_strings;

void rec(vector<int> p, int &n, vector<pair<int,int>> &possible, int &M, int **canSwap, bool *visited) {
    // if(prune>14)
    //     return;
    if(ans == 0)
        return;
    string toStr = vecToString(p);
    if(visited_strings.count(toStr) == 1) {
        return;
    }
    int cost = findCost(p,n, canSwap);
    if(cost == 0) {
        ans = 0;
        return;
    }
    ans = min(ans, cost);
    visited_strings.insert(toStr);
    for(int j=0;j<M;j++) {
        if(visited[j] == true)
            continue;
        auto i = possible[j];
        swap(p[i.first], p[i.second]);
        visited[j] = true;
        rec(p,n,possible, M,canSwap,visited);
        visited[j] = false;
        swap(p[i.first], p[i.second]);
    }
}

void rec2(vector<int> &p, int &n, vector<pair<int,int>> &possible, int &ans, bool *visited, int **canSwap) {
    if(ans == 0)
        return;
    string str = vecToString(p);
    if(visited_strings.count(str))
        return;
    int cost = findCost(p,n, canSwap);
    if(cost == 0) {
        ans = 0;
        return;
    }
    ans = min(ans, cost);
    visited_strings.insert(str);
    for(int j=0;j<possible.size();j++) {
        if(visited[j])
            continue;
        auto i = possible[j];
        swap(p[i.first], p[i.second]);
        visited[j] = true;
        rec2(p,n,possible, ans,visited,canSwap);
        visited[j] = false;
        swap(p[i.first], p[i.second]);
    }
}

int findRecCost(vector<int> p, vector<pair<int,int>> &possiblePair,int n,int **canSwap) {
    int ans = INT_MAX;
    visited_strings.clear();
    bool *visited = new bool[possiblePair.size()];
    for(int i=0;i<possiblePair.size();i++) {
        visited[i] = false;
    }
    rec2(p,n,possiblePair,ans,visited,canSwap);
    if(ans == INT_MAX)
        assert(0);
    return ans;
}

int findCostIt(vector<int> p, int **canSwap) {
    int n = p.size()-1;
    int cost = 0;
    while (!isSorted(p)) {
        int i = 1;
        while (i<n) {
            if(p[i] == i) {
                i++;
                continue;
            }
            int i1 = i;
            vector<int> newP = p;
            unordered_set<int> noChange;
            while (p[i1] != i1) {
                int i2 = p[i1];
                noChange.insert(i1);
                noChange.insert(i2);
                swap(p[i1], p[i2]);
            }
            for(int j=1;j<=n;j++) {
                if(noChange.count(j) == 0) {
                    newP[j] = j;
                }
            }
            vector<pair<int,int>> possiblePair;
            for(int i = 1;i<=n;i++) {
                for(int j=i+1;j<=n;j++) {
                    if(canSwap[i][j] == 0 && noChange.count(i) && noChange.count(j)) {
                        possiblePair.push_back({i,j});
                    }
                }
            }
            cost += findRecCost(newP,possiblePair,n, canSwap);
        }
    }
    return cost;
}

void solve() {
    int N,M;
    cin>>N>>M;
    visited_strings.clear();
    int **canSwap = new int*[N+1];
    for(int i=1;i<=N;i++) {
        canSwap[i] = new int[N+1];
        for(int j=1;j<=N;j++) {
            if(i!=j)
                canSwap[i][j] = 1;
            else
                canSwap[i][j] = 0;
        }
    }
    vector<int> p(N+1);
    for(int i = 1;i<=N;i++) {
        cin>>p[i];
    }
    vector<pair<int,int>> ms(M);
    int index = 0;
    for(int i=0;i<M;i++) {
        int x,y;
        cin>>x>>y;
        if(canSwap[x][y] == 1)
            ms[index++] = {x,y};
        canSwap[x][y] = 0;
        canSwap[y][x] = 0;
    }
    for(int k=1;k<=N;k++) {
        for(int i = 1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                canSwap[i][j] = min(canSwap[i][j],canSwap[i][k]+canSwap[k][j]);
            }
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(canSwap[i][j] == 0) {
                if(p[i] == j && p[j] == i)
                    swap(p[i],p[j]);
            } 
        }
    }

    bool *visited = new bool[index];
    for(int i=0;i<index;i++) {
        visited[i] = false;
    }
    int cost = findCostIt(p, canSwap);
    visited_strings.clear();
    rec(p,N,ms,index,canSwap, visited);
    cout<<min(cost,ans)<<"\n";
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while(T--) {
        ans = INT_MAX;
        solve();
    }
    return 0;
}


