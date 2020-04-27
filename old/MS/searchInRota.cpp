#include <bits/stdc++.h>
using namespace std;

int getPivot(vector<int> v) {
    int last = v.size() - 1;
    int first = 0;
    while(first<last) {
        int mid = (first+last)/2;
        if(v[mid] > v[mid-1] && v[mid+1] < v[mid]) {
            return mid;
        }
        if(v[mid] < v[first]) {
            last = mid-1;
            continue;
        } 
        if(v[mid] > v[last]) {
            first = mid+1;
            continue;
        }
        return -1;
        
    }
    return -1;
}

int bs(vector<int> v, int st, int end, int k) {
    while(end > st) {
        int mid = (st+end)/2;
        if(v[mid] == k)
            return mid;
        if(k>v[mid]) {
            st = mid+1;
        } else {
            end = mid-1;
        }
    }
    return -1;
}

int getAns(vector<int> v, int k) {
    int pivot = getPivot(v);
    cout<<pivot<<endl;
    if(pivot == -1) {
        return bs(v,0,v.size()-1,k);
    }
    int l = bs(v,0,pivot,k);
    int r = bs(v,pivot+1,v.size()-1,k);
    if(l == -1 && r == -1)
        return -1;
    return l==-1?r:l;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N;
        int k;
        cin>>N;
        vector<int> v(N);
        for(int i = 0;i<N;i++) {
            cin>>v[i];
        }
        cin>>k;
        cout<<getAns(v,k)<<endl;
    }
    return 0;
}