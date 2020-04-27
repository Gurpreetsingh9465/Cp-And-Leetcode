#include<bits/stdc++.h>
int main(){
    unsigned int N,R,C,Sr,Sc;
    int T;
    std::cin>>T;
    int Test = T;
    while(T--) {
        std::cin>>N>>R>>C>>Sr>>Sc;
        int arr[50000+1][50000+1];
        for(int i=0;i<=R;i++) {
            for(int j=0;j<=C;j++) {
                arr[i][j] = 0;
            }
        }
        arr[Sr][Sc] = 1;
        std::string s;
        std::cin>>s;
        for(int i=0;i<s.length();i++) {
            while (arr[Sr][Sc]!=0) {
                arr[Sr][Sc] = 1;
                switch (s[i])
                {
                case 'N':
                    Sr-=1;
                    break;
                case 'E':
                    Sc+=1;
                    break;
                case 'S':
                    Sr+=1;
                    break;
                case 'W':
                    Sc-=1;
                    break;
                }
            }
            arr[Sr][Sc] = 1;
        }
        std::cout<<"Case #"<<(Test-T)<<": "<<Sr<<" "<<Sc<<std::endl;
    }
    return 0;
}