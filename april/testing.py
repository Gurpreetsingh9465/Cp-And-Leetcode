class NumArray {
    int *arr;
    int n;
    vector<int> v;
public:
    NumArray(vector<int>& v) {
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
    
    void updateBinaryIndexedTree(int val, int index){
        while(index < this->n){
            arr[index] += val;
            index = getNext(index);
        }
    }
    
    int getNext(int index) {
        return index + (index & -index);
    }
    
    int getParent(int index){
        return index - (index & -index);
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
    
    void update(int index, int val) {
        int diff = val-v[index];
        v[index] = val;
        this->updateBinaryIndexedTree(diff, index+1);
    }
    
    int sumRange(int i, int j) {
        return prefixQuery(j) - prefixQuery(i-1);
    }
};