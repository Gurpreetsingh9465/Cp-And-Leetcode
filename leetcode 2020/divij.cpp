#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

class cmp {

};

class Solution {
public:
    
    vector<int> price;
    vector<vector<int>> special;
    vector<int> needs;
    unordered_map<vector<int>, int> mem;

    int leftPrice(vector<int> &cur) {
        int cur_price = 0;
        for(int i=0;i<price.size();i++) {
            cur_price = cur_price + price[i] * (needs[i] - cur[i]);
        }
        return cur_price;
    }
    
    bool canApply(vector<int> &offer, vector<int> &cur, vector<int> &clone) {
        bool can = true;
        for(int i=0;i<offer.size()-1;i++) {
            if(cur[i] + offer[i] <= needs[i]) {
                clone[i] = cur[i] + offer[i];
            } else {
                can = false;
                break;
            }
        }
        return can;
    }
    
    int rec(vector<int> &cur) {
        if(mem.count(cur) != 0) {
            return mem[cur];
        }
        int res = leftPrice(cur);
        for(auto &i: special) {
            vector<int> clone(cur.size());
            if(canApply(i, cur, clone)) {
                res = min(res, i[i.size()-1] + rec(clone));
            }
        }
        mem[cur] = res;
        return res;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        this->price = price;
        this->special =special;
        this->needs = needs;
        vector<int> v(needs.size(),0);
        mem.clear();
        return rec(v);
    }
};

int main() {
    return 0;
}