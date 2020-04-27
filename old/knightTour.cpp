#include<bits/stdc++.h>
using namespace std;

int noOfMoves = 0;
void backTrack(int i, int j, int **a, int n) {
    if(i>=0 && i<n && j>=0 && j<n) {
        a[i][j] = 0;
    }
}

void PrintBoard(int **a, int n) {
    // system("clear");
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cout<<setw(3);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool helper(int **a, int k, int i, int j, int target, int n) {
    noOfMoves+=1;
    if(i<0 || j<0 || j>=n || i>=n || a[i][j] != 0) {
        return false;
    }
    a[i][j] = k;
    // PrintBoard(a,n);
    // //cin.get();
    if(k == target) {
        PrintBoard(a,n);
        cout<<"*----------------------=----------------------*"<<endl;
        return true;
    }
    bool ans =  false;
    vector<pair<int,int>> moves = {
        {i+2,j+1},
        {i+1,j+2},
        {i-2,j+2},
        {i-2,j+1},
        {i-2,j-1},
        {i-1,j-2},
        {i+1,j-2},
        {i+2,j-1}
    };
    for(auto &move: moves) {
        bool inter = helper(a,k+1,move.first,move.second,target,n);
        // if(inter == true)
        //     return true;
        ans|=inter;
    }
    // if(ans == false) {
    backTrack(i,j,a,n);
    // }
    return ans;
}

int ** knightTour(int n) {
    int **a = new int*[n];
    for(int i=0;i<n;i++) {
        a[i] = new int[n];
        for(int j=0;j<n;j++) {
            a[i][j] = 0;
        }
    }
    helper(a,1,0,0,n*n,n);
    return a;
}


int main() {
    int n;
    cin>>n;
    int **a = knightTour(n);
    // PrintBoard(a,n);
    // cout<<noOfMoves<<endl;
    return 0;
}