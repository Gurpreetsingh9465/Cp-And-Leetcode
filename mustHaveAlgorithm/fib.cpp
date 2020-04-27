#include<bits/stdc++.h>
using namespace std;
/*
[f(n),  = [[1,1],^n-1 * [f1, 
f(n-1)]    [1,0]]        f0]    
*/

class Matrix {
    private:
        int n,m;
        int **arr;
    public:
        Matrix(int n) {
            this->n = n;
            this->m = n;
            arr = new int*[n];
            for(int i=0;i<n;i++) {
                arr[i] = new int[n];
                for(int j = 0;j<n;j++) {
                    arr[i][j] = 0;
                }
            }
        }
        Matrix(const Matrix &m) {
            this->n = m.n;
            this->m = m.m;
            arr = new int*[n];
            for(int i=0;i<n;i++) {
                arr[i] = new int[n];
                for(int j = 0;j<n;j++) {
                    arr[i][j] = m.arr[i][j];
                }
            }
        }
        Matrix(int n, int m) {
            this->n = n;
            this->m = m;
            arr = new int*[n];
            for(int i=0;i<n;i++) {
                arr[i] = new int[m];
                for(int j = 0;j<m;j++) {
                    arr[i][j] = 0;
                }
            }
        }
        void setValues(vector<vector<int>> &v) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    arr[i][j] = v[i][j];
                }
            }
        }
        int getValue(int i, int j) {
            return arr[i][j];
        }
        void setValue(int i, int j, int val) {
            arr[i][j] = val;
        }
        int getN() { return this->n; };
        int getM() {return this->m; };
        void print() {
            cout<<"[";
            for(int i = 0;i<n;i++) {
                cout<<"[ ";
                for(int j=0;j<m;j++) {
                    cout<<arr[i][j]<<", ";
                }
                cout<<"],"<<endl;
            }
            cout<<"]"<<endl;
        }
        Matrix* matMul(Matrix *b) {
            if(n == 0)
                return NULL;
            int y0 = m;
            int y1 = b->getN();
            if(y0 != y1)
                return NULL;
            int z = b->getM();
            Matrix *ans = new Matrix(n,z);
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < z; ++j)
                    for(int k = 0; k < y0; ++k)
                    {
                        int val  = ans->getValue(i,j) + (this->getValue(i,k) * b->getValue(k,j));
                        ans->setValue(i,j, val);
                    }
            return ans;
        }
        ~Matrix() {
            for (int i=0; i<n; i++)
                delete[] arr[i];
            delete[] arr;
        }

};

Matrix *mat_power(Matrix *init, int n) {
    if(n == 1) {
        return init;
    } else if(n == 2) {
        return init->matMul(init);
    }
    Matrix * res = mat_power(init, n/2);
    if(n&1) {
        return ->matMul(init);
    }
    return res->matMul(res);
}

int fib(int f0, int f1, int n) {
    vector<vector<int>> init = {{1,1},{1,0}};
    Matrix *initialMatrix = new Matrix(2);
    initialMatrix->setValues(init);
    Matrix *ans = mat_power(initialMatrix, n-1);
    ans->print();
    Matrix *fixMatrix = new Matrix(2,1);
    fixMatrix->setValue(0,0,f1);
    fixMatrix->setValue(1,0,f0); 
    Matrix * res = ans->matMul(fixMatrix);
    return res->getValue(0,0);
}

int main() {
    int n = 10;
    cout<<fib(0,1,n)<<endl;
}
