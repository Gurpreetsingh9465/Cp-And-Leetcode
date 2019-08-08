

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
                tree[i] = tree[2*i] ^ tree[(2*i+1)];
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
                tree[index] = tree[index*2] ^ tree[index*2+1];
                index/=2;
            }
        }

        int query(int l, int r) { 
            int res = 0;
            for (l += size_arr, r += size_arr+1; l < r; l >>= 1, r >>= 1) {
                if (l&1) res ^= tree[l++];
                if (r&1) res ^= tree[--r];
            }
            return res;
        }
};


bool isTriplet(int *a, int i, int j, int k) {
    if(i == j) {
        return false;
    }
    int suml = 0, sumr = 0;
    for(int l = i ;l<j;l++) {
        suml = suml ^ a[l];
    }
    for(int l=j ; l<=k ;l++) {
        sumr = sumr ^ a[l];
    }
    if(sumr != suml)
        return false;
    return true;
}

int fun(int n, SegmentTree &tree) {
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            for(int k = j;k<n;k++) {
                if(i!=j) {
                    int l = tree.query(i,j-1);
                    int r = tree.query(j,k);
                    if(l == r) {
                        ans+=1;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {

	int T;
	cin>>T;
	while(T--) {
        int N;
        cin>> N;
        vector<int> a(N);
        for(int pt = 0;pt<N;pt++) {
            cin>>a[pt];
        }
        SegmentTree tree(a);
        cout<<fun(N, tree)<<endl;
	}
	return 0;
}