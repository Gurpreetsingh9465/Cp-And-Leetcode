#include <bits/stdc++.h>
using namespace std;
#define N 4
class cmp {
  public:
    bool operator() (pair<int,int> l, pair<int,int> r) {
        return r.first<l.first;
    }
};
int *mergeKArrays(int arr[][N], int k)
{
    int size = k*N;
    int *res = new int[size];
    int index = 0;
    int idxs[k];
    memset(idxs,0,sizeof(idxs));
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for(int i = 0;i<k;i++) {
        pq.push({arr[i][0],i});
    }
    while(pq.size()>0) {
        pair<int,int> t = pq.top();
        pq.pop();
        res[index++] = t.first;
        idxs[t.second]++;
        if(idxs[t.second] < N)
            pq.push({arr[t.second][idxs[t.second]],t.second});
    }
    for(int i = 0;i<size;i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return res;
}

int main() {
	int arr[4][4] = {{1,2,3,4},{0,5,10,15},{2,4,8,10},{3,9,27,81}};
	int *a = mergeKArrays(arr,4);
	// for(int i = 0;i<16;i++) {
	// 	cout<<a[i]<<" ";
	// }
	cout<<endl;
	return 0;
}