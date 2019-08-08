#include<bits/stdc++.h>

int main() {
    std::vector<int> *v = new std::vector<int>();
    v->insert(v->begin()+0,1);
    v->insert(v->begin()+1,5);
    v->insert(v->begin()+1,6);
    for(int i:*v){
        std::cout<<i<<std::endl;
    }
    return 0;
}