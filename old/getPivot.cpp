#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int> v) {
    if(v.size == 0) {
        return -1;
    } else if(v.size() == 1) {
        return v[0];
    }
    int j = v.size()-1;
    int i = 0;
    int mid = (i+j)/2;
    while(j>i) {
        if(v[mid] < v[mid-1]) {
            return v[mid];
        } else if(v[mid] > v[mid+1]) {
            return v[mid+1];
        }
        if(v[mid] < v[i]) {
            mid = (i+mid-1)/2;
        } else if(v[mid]> v[j]) {
            mid = (mid+1+j)/2;
        } else {
            return v[0];
        }
    }
    return v[0];
}

int main() {
    vector<int> v = {41,1,2,3,4,5,7};
    cout<<getPivot(v)<<endl;
    return 0;
}