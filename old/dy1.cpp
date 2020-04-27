#include <bitset> 
#include<bits/stdc++.h>


int main() {
    unsigned int num;
    std::cin>>num;
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    for(unsigned int i = 2;i<=num;i++) {
        unsigned int val = i & (i-1);
        if(val == 0) {
            v.insert(v.begin()+i,1);    
        } else {
            v.insert(v.begin()+i,v[val]+v[i-val]);
        }
    }
    std::cout<<"[";
    for(unsigned int i=0 ; i<=num ; i++) {
        if(i == num) {
            std::cout<<v[i];
        } else { 
            std::cout<<v[i]<<",";
        }
    }
    std::cout<<"]"<<std::endl;
}

