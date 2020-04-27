#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(int **arr ,int i , int j) {
    if(i<0 || i >= 8 || j < 0 || j>=8 || arr[i][j] == 1) {
        return false;
    }
    return true; 
}

void fun(int **arr, int i, int j, int maxDepth) {
    queue<pair<int, int>> q;
    q.push({i, j});
    arr[i][j] = 1;
    int depth = 0;
    while (!q.empty()) {
        if(depth >= maxDepth) {
            break;
        }
        depth++;
        int size = q.size();
        for(int i = 0;i<size;i++) {
            auto pos = q.front();
            q.pop();
            if(isValid(arr, pos.first + 1, pos.second + 1)) {
                arr[pos.first+1][pos.second+1] = 1;
                q.push({pos.first+1, pos.second+1});
            }
            if(isValid(arr, pos.first - 1, pos.second - 1)) {
                arr[pos.first - 1][pos.second - 1] = 1;
                q.push({pos.first - 1, pos.second - 1});
            }
            if(isValid(arr, pos.first - 1, pos.second)) {
                arr[pos.first - 1][pos.second] = 1;
                q.push({pos.first - 1, pos.second});
            }
            if(isValid(arr, pos.first + 1, pos.second)) {
                arr[pos.first + 1][pos.second] = 1;
                q.push({pos.first + 1, pos.second});
            }
            if(isValid(arr, pos.first, pos.second - 1)) {
                arr[pos.first][pos.second - 1] = 1;
                q.push({pos.first, pos.second - 1});
            }
            if(isValid(arr, pos.first, pos.second + 1)) {
                arr[pos.first][pos.second + 1] = 1;
                q.push({pos.first, pos.second + 1});
            }
            if(isValid(arr, pos.first + 1, pos.second - 1)) {
                arr[pos.first + 1][pos.second - 1] = 1;
                q.push({pos.first + 1, pos.second - 1});
            }
            if(isValid(arr, pos.first - 1, pos.second + 1)) {
                arr[pos.first - 1][pos.second + 1] = 1;
                q.push({pos.first - 1, pos.second + 1});
            }
        }
        
    }
    
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        int r, c, k;
        cin>>r>>c>>k;
        r--;
        c--;
        int **arr = new int*[8];
        for(int i=0;i<8;i++) {
            arr[i] = new int[8];
            for(int j=0;j<8;j++) {
                arr[i][j] = 0;
            }
        }
        fun(arr, r, c, k);
        int total = 0;
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                total+=arr[i][j];
            }
        }
        cout<<total<<endl;
    }
}
