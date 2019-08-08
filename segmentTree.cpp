#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    private:
        vector<int> tree;
        int size;
        int size_arr;
    public:
        SegmentTree(vector<int> &arr) {
            size = arr.size()*2;
            size_arr = arr.size();
            tree.reserve(size);
            int i = arr.size();
            for(int i = 0;i<arr.size();i++) {
                tree[i+arr.size()] = arr[i];
            }
            for(i = arr.size()-1;i>=1;i--) {
                tree[i] = tree[2*i] + tree[(2*i+1)];
            }
        }
        void printTree() {
            for(int i = 1;i<size;i++) {
                cout<<tree[i]<<" ";
            }
            cout<<endl;
        }

        void update(int index, int val) {
            index+=size_arr;
            tree[index] = val;
            index/=2;
            while(index >= 1) {
                tree[index] = tree[index*2] + tree[index*2+1];
                index/=2;
            }
        }

        int query(int l, int r) { 
            int res = 0;
            for (l += size_arr, r += size_arr+1; l < r; l >>= 1, r >>= 1) {
                if (l&1) res += tree[l++];
                if (r&1) res += tree[--r];
            }
            return res;
        }
};

int main() {
    vector<int> arr = {1,2,4,5,7,8};
    SegmentTree s(arr);
    s.printTree();
    cout<<s.query(0,4)<<endl;
    return 0;
}