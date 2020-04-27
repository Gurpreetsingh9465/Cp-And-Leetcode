#include<bits/stdc++.h>
using namespace std;

bool isFancy(string st) {
    for(int i=0;i<st.length()-2;++i){
        if(st[i]=='n' && st[i+1]=='o' && st[i+2]=='t'){
            if((i==0 && (st[i+3]==' ' || st[i+3]=='\0'))
                || (i>0 && st[i-1]==' ' && (st[i+3]==' ' || st[i+3]=='\0'))
            ){
                 return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin>>N;
    while(N--) {
        string st;
        cin.ignore();
        getline(cin, st);
        if(isFancy(st)) {
            cout<<"Real Fancy";
        } else {
            cout<<"regularly fancy";
        }
        cout<<endl;
    }
    return 0;
}