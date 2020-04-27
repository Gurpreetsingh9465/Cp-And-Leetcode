#include<bits/stdc++.h>
using namespace std;

class IndexTree {
    private:
        int *arr;
        int n;
        vector<int> v;
    public:
        IndexTree() { }
        IndexTree(vector<int> &v) {
            this->v = v;
            arr = new int[v.size()+1];
            this->n = v.size()+1;
            for(int i=0;i<this->n;i++) {
                arr[i] = 0;
            }
            for(int i=0;i<v.size();i++) {
                this->updateBinaryIndexedTree(v[i], i+1);
            }
        }
        void update(int val, int index) {
            int diff = val-v[index];
            v[index] = val;
            this->updateBinaryIndexedTree(diff, index+1);
        }
        void updateBinaryIndexedTree(int val, int index){
            while(index < this->n){
                arr[index] += val;
                index = getNext(index);
            }
        }
        int prefixQuery(int index) {
            int sum = 0;
            index+=1;
            while(index > 0){
                sum += arr[index];
                index = getParent(index);
            }
            return sum;
        }
        int rangeSum(int start, int end) {
            return prefixQuery(end) - prefixQuery(start-1);
        }
        int getNext(int index) {
            return index + (index & -index);
        }
        int getParent(int index){
            return index - (index & -index);
        }
};

int main() {
    vector<int> v = {3,2,-1,6,5,4,-3,3,7,2,3};
    IndexTree I(v);
    cout<<I.prefixQuery(5)<<endl;
    cout<<I.rangeSum(1,9)<<endl;
    I.update(5,2);
    cout<<I.rangeSum(1,9)<<endl;
}
