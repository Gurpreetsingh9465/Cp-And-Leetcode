#include<bits/stdc++.h>
using namespace std;

int main() {
    int W,H,R;
    cin>>W>>H>>R;
    int **arr = new int*[H+1];
    for(int i=0;i<=H;i++) {
        arr[i] = new int[W+1];
        for(int j=0;j<=W;j++) {
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<R;i++) {
        int X,Y;
        cin>>X>>Y;
        arr[X][Y] = 1;
    }
    return 0;
}
