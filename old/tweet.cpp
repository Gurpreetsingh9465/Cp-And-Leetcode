#include<bits/stdc++.h>
int main(){
    int count=0;
    int n;
    int k;
    std::cin>>n;
    std::cin>>k;
    bool arr[n];
    std::memset(arr,false,sizeof(arr));
    while(k--) {
        std::string s;
        std::cin>>s;
        if(s[s.length()-1] == 'L') {
            for(int i=0;i<n;i++) {
                arr[i] = false;
            }
            count = 0;
        } else {
            int value;
            std::cin>>value;
            arr[value-1] = !arr[value-1];
            if(arr[value-1]) {
                count+=1;
            } else {
                count-=1;
            }
        }
        std::cout<<count<<std::endl;
    }
    return 0;
}