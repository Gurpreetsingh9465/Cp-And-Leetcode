#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int permute[24][4] = {{0,1,2,3},
    {1,0,2,3},
    {2,0,1,3},
    {0,2,1,3},
    {1,2,0,3},
    {2,1,0,3},
    {2,1,3,0},
    {1,2,3,0},
    {3,2,1,0},
    {2,3,1,0},
    {1,3,2,0},
    {3,1,2,0},
    {3,0,2,1},
    {0,3,2,1},
    {2,3,0,1},
    {3,2,0,1},
    {0,2,3,1},
    {2,0,3,1},
    {1,0,3,2},
    {0,1,3,2},
    {3,1,0,2},
    {1,3,0,2},
    {0,3,1,2},
    {3,0,1,2}
};

void printTable(vector<vector<int>> &table) {
    for(int i = 0;i<table.size();i++) {
        for(int j = 0;j<table[i].size();j++) {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" ============================= "<<endl;
}

ll calci(vector<vector<int>> &table, int seq[4], int time[4]) {
    ll profit = 0;
    for(int i = 0;i<4;i++) {
        int res = table[seq[i]][time[i]];
        if(res == 0) {
            profit-=100;
        } else {
            profit+=(res*25*(i+1));
        }
    }
    return profit;
}

ll calculate(vector<vector<int>> &table, int seq[4]) {
    ll max_profit = INT_MIN;
    for(int i = 0;i<24;i++) {
        ll inter = calci(table, seq, permute[i]);
        if(max_profit<inter) {
            max_profit = inter;
        }
    }

    return max_profit;
}


ll profit(vector<vector<int>> table) {
    ll sale = INT_MIN;
    for(int i = 0;i<24;i++) {
        ll inter = calculate(table, permute[i]);
        if(inter>sale) {
            sale = inter;
        }
    }
    return sale;
}

int main() {
    int T;
    cin>>T;
    ll total_profit = 0;
    while(T--) {
        int N;
        cin>>N;
        vector<vector<int>> v(4);
        for(auto &i: v) {
            i = vector<int>(4);
        }
        while (N--) {
            char movie;
            int time;
            cin>>movie>>time;
            v[movie - 'A'][time/3 - 1] += 1;
        }
        ll pro = profit(v);
        total_profit += pro;
        cout<<pro<<endl;
    }
    cout<<total_profit<<endl;
    return 0;
}