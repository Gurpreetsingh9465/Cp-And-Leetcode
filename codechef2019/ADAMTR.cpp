#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPossible(int **arr1, int **arr2, int N) {
    for(int i = 0;i<N;i++) {
        if(arr1[i][i] != arr2[i][i]) {
            return false;
        }
    }
    for(int i = 1; i<N;i++) {
        for(int j=i;j<N;j++) {
            int r = j;
            int c = j-i;
            int first = arr1[r][c];
            int second = arr1[c][r];
            if((arr2[r][c] == first && arr2[c][r] == second) || (arr2[r][c] == second && arr2[c][r] == first)) {
                continue;
            }
            return false;
        }
    }
    return true;
}


int main() {
    int T;
    cin>>T;
    while (T--) {
        int N;
        cin>>N;
        int** arr1, **arr2;
        arr1 = new int*[N];
        arr2 = new int*[N];
        for(int i = 0;i<N;i++) {
            arr1[i] =  new int[N];
            for(int j = 0;j<N;j++) {
                cin>>arr1[i][j];
            }
        }
        for(int i = 0;i<N;i++) {
            arr2[i] =  new int[N];
            for(int j = 0;j<N;j++) {
                cin>>arr2[i][j];
            }
        }
        if(isPossible(arr1, arr2, N)) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
}
