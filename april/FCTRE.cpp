#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

const int MAXN = 1000001;

int spf[MAXN];

void sieve() {
    spf[1] = 1; 
	for (int i=2; i<MAXN; i++)
		spf[i] = i;
	for (int i=4; i<MAXN; i+=2) 
		spf[i] = 2; 
	for (int i=3; i*i<MAXN; i++) 
	{
		if (spf[i] == i) 
		{
			for (int j=i*i; j<MAXN; j+=i)
				if (spf[j]==j) 
					spf[j] = i;
		} 
	}
}

unordered_map<int,int> getFactorization(int x) 
{
	unordered_map<int,int> ret;
	while (x != 1) 
	{ 
		ret[spf[x]]++;
		x = x / spf[x];
	}
	return ret; 
}

class Node {
    public:
        ll val, left, right;
        Node() {
            val = -1;
            left = -1;
            right = -1;
        }
        Node(ll val) {
            this->val = val;
            left = -1;
            right = -1;
        }
        void addValue(ll val) {
            this->val = val;
        }
        void addLeft(ll left) {
            this->left = left;
        }
        void addRight(ll right) {
            this->right = right;
        }
};

class Tree {
    public:
    Node *arr;
    ll root = -1;
    bool *isLeft;
    ll N;
    Tree(ll N) {
        this->N = N;
        this->arr = new Node[N+1];
        this->isLeft = new bool[N+1];
        for(ll i = 1;i<=N;i++) {
            arr[i].val = i;
            isLeft[i] = false;
        }
    }
    void addEdge(ll from, ll to) {
        if(arr[from].left == -1) {
            arr[from].left = to;
        } else {
            arr[from].right = to;
        }
        isLeft[to] = true;
    }
    ll findRoot() {
        for(ll i = 1;i<=N;i++) {
            if(isLeft[i] == false) {
                root = arr[i].val;
                break;
            }
        }
        return this->root;
    }

    bool recGetPath(ll to, ll cur, vector<ll> &res) {
        if(cur == -1) {
            return false;
        }
        res.push_back(arr[cur].val);
        if(cur == to) {
            return true;
        }
        if(recGetPath(to, arr[cur].left, res) || recGetPath(to,arr[cur].right,res)) {
            return true;
        }
        res.pop_back();
        return false;
    }

    vector<ll> getPath(ll to) {
        vector<ll> ans;
        recGetPath(to,root,ans);
        return ans;
    }

};

int main() {
    fastIO;
    ll T;
    sieve();
    cin>>T;
    while (T--) {
        ll N;
        cin>>N;
        Tree *t = new Tree(N);
        for(ll i=0;i<N-1;i++) {
            ll a,b;
            cin>>a>>b;
            t->addEdge(a,b);
        }
        t->findRoot();
        unordered_map<int,int> cost[N+1];
        for(ll i=1;i<=N;i++) {
            int x;
            cin>>x;
            cost[i] = getFactorization(x);
        }
        ll Q;
        cin>>Q;
        while (Q--) {
            ll from, to;
            cin>>from>>to;
            vector<ll> p1 = t->getPath(from);
            vector<ll> p2 = t->getPath(to);
            unordered_map<int,int> res;
            ll index = 0;
            while (index<p1.size() || index<p2.size()) {
                if(index<p1.size() && index<p2.size() && p1[index] == p2[index]) {
                    if(index+1<p1.size() && index+1<p2.size() && p1[index+1] == p2[index+1]) {
                        index++;
                        continue;
                    } else {
                        for(auto &i: cost[p1[index]]) {
                            res[i.first]+=i.second;
                            res[i.first]=res[i.first]%MOD;
                        }
                        index++;
                        continue;
                    }
                } else {
                    if(index<p1.size()) {
                        for(auto &i: cost[p1[index]]) {
                            res[i.first]+=i.second;
                            res[i.first]=res[i.first]%MOD;
                        }
                    }
                    if(index<p2.size()) {
                        for(auto &i: cost[p2[index]]) {
                            res[i.first]+=i.second;
                            res[i.first]=res[i.first]%MOD;
                        }
                    }
                    index++;
                }
            }
            ll ans = 1;
            for(auto &i: res) {
                ans= (ans%MOD*(i.second+1)%MOD)%MOD;
            }
            cout<<ans%MOD<<"\n";
        }
    }
    return 0;
}


