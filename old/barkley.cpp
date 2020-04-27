
#include<bits/stdc++.h>
#include <utility> 
using namespace std;
int main() {
    long int N, count;
    std::cin>>N;
    count = N;
    vector<long int> *v = new vector<long int>[N+1];
    for(long int i=0;i<N;i++) {
        long int val;
        std::cin>>val;
        v[1].push_back(val);
    }
    for(long int i=2;i<=N;i++) {
        long int ele = i/2;
        for(ele;ele>0;ele=ele/2) {
            if(i%ele==0)
                break;
        }
        for(long int l: v[ele]){
            if(l%i == 0){
                v[i].push_back(l);
                count+=1;
            }
        }
    }
    std::cout<<count<<std::endl;
}

