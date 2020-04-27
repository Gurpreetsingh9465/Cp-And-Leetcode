#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int start, int end, bool turn) {
    if(start > end) {
        return 0;
    }
    if(turn) {
        if(start == end-1) {
            return max(arr[start], arr[end]);
        }
        return max(arr[start] + getMax(arr,start+1, end, !turn), arr[end]+getMax(arr, start, end-1, !turn));
    } else {
        if(arr[start] > arr[end]) {
            return getMax(arr, start+1, end, !turn);
        } else {
            return getMax(arr, start, end-1, !turn);
        }
    }
    
}


int main() {
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i<N;i++) {
            cin>>arr[i];
        }
        cout<<getMax(arr,0, N-1, true)<<endl;
    }
    return 0;
}